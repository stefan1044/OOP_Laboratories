#include <exception>
#include <iostream>
#include <algorithm>

class Compare{
public:

    virtual int CompareElements(void* e1, void* e2) = 0;

};

template<class T>
class ArrayIterator{

private:

    int Current; // mai adaugati si alte date si functii necesare pentru iterator

public:

    ArrayIterator(){
        this->Current = 0;
    }

    ArrayIterator& operator ++ (){
        this->Current++;
    }

    ArrayIterator& operator -- (){
        this->Current--;
    }

    bool operator= (ArrayIterator<T> & copy){
        this->Current = copy.Current;
    }

    bool operator!=(ArrayIterator<T> &){

    }

    T* GetElement(){

    }

};

template<class T>
class Array{

private:

    T** List; // lista cu pointeri la obiecte de tipul T*

    int Capacity; // dimensiunea listei de pointeri

    int Size; // cate elemente sunt in lista

class exceptieOutOfBounds : public std::exception{
    virtual const char* what() const throw(){
        return "Index out-of-bounds";
    }
}OOBException;
class exceptieSizeDiff : public std::exception{
    virtual const char* what() const throw(){
        return "Size difference error";
    }
}SDException;

public:

    Array(){ // Lista nu e alocata, Capacity si Size = 0
        this->Capacity = 0;
        this->Size = 0;
    }
    ~Array() { // destructor
        delete this->List;
        this->Capacity = -1;
        this ->Size = -1;
    }
    Array(int capacity) { // Lista e alocata cu 'capacity' elemente
        this->Capacity = capacity;
        this->Size = 0;
        this->List = new T*[capacity];
    }
    Array(const Array<T> &otherArray) { // constructor de copiere
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;
        this->List = new T*[this->Capacity];
        for (int i = 0;i<this->Capacity;i++){
            this->List[i] = otherArray.List[i];
        }
    }


    T& operator[] (int index) { // arunca exceptie daca index este out of range
        if (index < 0 || index >= this->Capacity)
            throw OOBException;
        else
            return this->List[index];
    }


    const Array<T>& operator+=(const T &newElem) { // adauga un element de tipul T la sfarsitul listei si returneaza this
        if(this->Size == this->Capacity)
            throw OOBException;
        else{
            this->List[this->Size] = newElem;
            this->Size++;
            return this;
        }
    }

    const Array<T>& Insert(int index, const T &newElem) { // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index >= this->Capacity)
            throw OOBException;
        else{
            this->List[index] = newElem;
            return this;
        }
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) { // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if ( index + otherArray.Capacity >= this->Capacity)
            throw OOBException;
        int startPos = index, endPos = 0;
        while (startPos < this->Capacity &&  endPos < otherArray.Capacity){
            this->List[startPos] = otherArray.List[endPos];
            startPos++;
            endPos++;
        }
        return this;
    }

    const Array<T>& Delete(int index) { // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index >= this->Capacity)
            throw OOBException;
        else{
            this->List[index] = nullptr;
        }
        return this;
    }


    bool operator=(const Array<T> &otherArray){
        if (this->Capacity < otherArray.Capacity) {
            throw SDException;
            return false;
        }
        else{
            for(int i = 0;i<otherArray.Capacity;i++)
                this->List[i] = otherArray.List[i];
            for(int i = otherArray.Capacity;i<this->Capacity;i++)
                this->List[i] = nullptr;
            this->Size = otherArray.Size;
            return true;
        }
    }



    void Sort() { // sorteaza folosind comparatia intre elementele din T
        std::sort(this->List, this->List + this->Size);
    }
    void Sort(int(*compare)(const T&, const T&)) { // sorteaza folosind o functie de comparatie
        std::sort(this->List,this->List + this->Size,compare);
    }
    void Sort(Compare *comparator) { // sorteaza folosind un obiect de comparatie
        //std::sort(this->List, this->List + this->Size, comparator->CompareElements);
    }


    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

    int BinarySearch(const T& elem) { // cauta un element folosind binary search in Array
        int left = 0, right = this->Size - 1;
        int mid;
        while(left<=right){
            mid = (left + right - 1) / 2;
            if (this->List[mid]== elem)
                return mid;
            if (elem < this->List[mid])
                right=mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind binary search si o functie de comparatie
        int left = 0, right = this->Size - 1;
        int mid;
        while(left<=right){
            mid = (left + right - 1) / 2;
            if (compare(this->List[mid], elem) == 0)
                return mid;
            if (compare(elem,this->List[mid]) == -1)
                right=mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator



    int Find(const T& elem); // cauta un element in Array

    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie

    int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator



    int GetSize();

    int GetCapacity();



    ArrayIterator<T> GetBeginIterator();

    ArrayIterator<T> GetEndIterator();

};
