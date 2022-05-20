#include <exception>
#include <iostream>
#include <algorithm>

class Compare {
public:

	virtual int CompareElements(void* e1, void* e2) = 0;

};

template<class T>
class ArrayIterator {

private:

	int Current; // mai adaugati si alte date si functii necesare pentru iterator

public:

	ArrayIterator() {
		this->Current = 0;
	}

	ArrayIterator& operator ++ () {
		this->Current++;
	}

	ArrayIterator& operator -- () {
		this->Current--;
	}

	bool operator= (ArrayIterator<T>& copy) {
		this->Current = copy.Current;
	}

	bool operator!=(ArrayIterator<T>&) {

	}

	T* GetElement() {

	}

};

template<class T>
class Array {

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

	class exceptieOutOfBounds : public std::exception {
		virtual const char* what() const throw() {
			return "Index out-of-bounds";
		}
	}OOBException;
	class exceptieSizeDiff : public std::exception {
		virtual const char* what() const throw() {
			return "Size difference error";
		}
	}SDException;

public:

	Array() { // Lista nu e alocata, Capacity si Size = 0
		this->Capacity = 0;
		this->Size = 0;
	}
	~Array() { // destructor
		delete this->List;
		this->Capacity = -1;
		this->Size = -1;
	}
	Array(int capacity) { // Lista e alocata cu 'capacity' elemente
		this->Capacity = capacity;
		this->Size = 0;
		this->List = new T * [capacity];
		for (int i = 0; i < capacity; i++) {
			this->List[i] = nullptr;
		}
	}
	Array(const Array<T>& otherArray) { // constructor de copiere
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		this->List = new T * [this->Capacity];
		for (int i = 0; i < this->Capacity; i++) {
			this->List[i] = otherArray.List[i];
		}
	}


	T& operator[] (int index) { // arunca exceptie daca index este out of range
		if (index < 0 || index >= this->Capacity || this->List[index] == nullptr)
			throw OOBException;
		else
			return *this->List[index];

	}


	const Array<T>& operator+=(const T& newElem) { // adauga un element de tipul T la sfarsitul listei si returneaza this
		if (this->Size == this->Capacity)
			throw OOBException;
		else {
			this->List[this->Size] = new T;
			this->List[this->Size][0] = newElem;
			this->Size++;
			return *this;
		}
	}

	const Array<T>& Insert(int index, const T& newElem) { // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		if (index < 0 || index >= this->Capacity)
			throw OOBException;
		else {
			this->List[index] = new T;
			this->List[index][0] = newElem;
			if (index > this->Size) this->Size = index + 1;
			return *this;
		}
	}
	const Array<T>& Insert(int index, const Array<T> otherArray) { // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		if (index + otherArray.Capacity > this->Capacity)
			throw OOBException;
		int startPos = index, endPos = 0;
		while (startPos < this->Capacity && endPos < otherArray.Capacity) {
			if (otherArray.List[endPos] == nullptr) {
				this->List[startPos] = nullptr;
			}
			else {
				this->List[startPos] = new T;
				this->List[startPos][0] = otherArray.List[endPos][0];
			}
			startPos++, endPos++;
		}
		if (this->Size < otherArray.Size + index) this->Size = otherArray.Size + index;
		return *this;
	}

	const Array<T>& Delete(int index) { // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
		if (index < 0 || index >= this->Capacity)
			throw OOBException;
		else {
			this->List[index] = nullptr;
		}
		return *this;
	}


	bool operator=(const Array<T>& otherArray) {
		//if (this == otherArray) return true;
		if (this->Capacity < otherArray.Capacity)
			throw SDException;
		else {
			for (int i = 0; i < otherArray.Capacity; i++)
				if (otherArray.List[i] == nullptr)
					this->List[i] = nullptr;
				else
					this->Insert(i, otherArray.List[i][0]);
			for (int i = otherArray.Capacity; i < this->Capacity; i++)
				this->List[i] = nullptr;
			this->Size = otherArray.Size;
			return true;
		}
		return false;
	}



	void Sort() { // sorteaza folosind comparatia intre elementele din T
		for (int i = 0; i < this->Size; i++) {
			if (this->List[i] == nullptr) {
				int j = i + 1;
				while (j < this->Size) {
					if (this->List[j] != nullptr) {
						this->Insert(i, this->List[j][0]);
						this->List[j] = nullptr;
						break;
					}
					j++;
				}
			}
		}
		int cont = 0;
		while (this->List[cont] != nullptr)
			cont++;
		this->Size = cont;

		for (int i = 1; i < this->Size; i++) {
			int key = this->List[i][0];
			int j = i - 1;
			while (j >= 0 && this->List[j][0] > key) {
				this->List[j + 1][0] = this->List[j][0];
				j--;
			}
			this->List[j + 1][0] = key;
		}
	}
	void Sort(int(*compare)(const T&, const T&)) { // sorteaza folosind o functie de comparatie
		for (int i = 0; i < this->Size; i++) {
			if (this->List[i] == nullptr) {
				int j = i + 1;
				while (j < this->Size) {
					if (this->List[j] != nullptr) {
						this->Insert(i, this->List[j][0]);
						this->List[j] = nullptr;
						break;
					}
					j++;
				}
			}
		}
		int cont = 0;
		while (this->List[cont] != nullptr)
			cont++;
		this->Size = cont;

		for (int i = 1; i < this->Size; i++) {
			int key = this->List[i][0];
			int j = i - 1;
			while (j >= 0 && compare(this->List[j][0], key) == 1) {
				this->List[j + 1][0] = this->List[j][0];
				j--;
			}
			this->List[j + 1][0] = key;
		}
	}
	void Sort(Compare* comparator) { // sorteaza folosind un obiect de comparatie
		for (int i = 0; i < this->Size; i++) {
			if (this->List[i] == nullptr) {
				int j = i + 1;
				while (j < this->Size) {
					if (this->List[j] != nullptr) {
						this->Insert(i, this->List[j][0]);
						this->List[j] = nullptr;
						break;
					}
					j++;
				}
			}
		}
		int cont = 0;
		while (this->List[cont] != nullptr)
			cont++;
		this->Size = cont;

		for (int i = 1; i < this->Size; i++) {
			int key = this->List[i][0];
			int j = i - 1;
			while (j >= 0 && comparator->CompareElements(this->List[j][0], key) == 1) {
				this->List[j + 1][0] = this->List[j][0];
				j--;
			}
			this->List[j + 1][0] = key;
		}
	}


	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem) { // cauta un element folosind binary search in Array
		this->Sort();

		int left = 0, right = this->Size - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - 1) / 2;
			if (this->List[mid][0] == elem)
				return mid;
			if (elem < this->List[mid][0])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind binary search si o functie de comparatie
		this->Sort(compare);

		int left = 0, right = this->Size - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - 1) / 2;
			if (compare(this->List[mid][0], elem) == 0)
				return mid;
			if (compare(elem, this->List[mid][0]) == -1)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
	int BinarySearch(const T& elem, Compare* comparator) {//  cauta un element folosind binary search si un comparator
		this->Sort(comparator);

		int left = 0, right = this->Size - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - 1) / 2;
			if (comparator->CompareElements(this->List[mid][0], elem) == 0)
				return mid;
			if (comparator->CompareElements(elem, this->List[mid][0]) == -1)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}


	int Find(const T& elem) { // cauta un element in Array
		for (int i = 0; i < this->Capacity; i++) {
			if (this->List[i][0] == elem)
				return i;
		}
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind o functie de comparatie
		for (int i = 0; i < this->Capacity; i++) {
			if (compare(this->List[i][0], elem) == 0)
				return i;
		}
		return -1;
	}
	int Find(const T& elem, Compare* comparator) {//  cauta un element folosind un comparator
		for (int i = 0; i < this->Capacity; i++) {
			if (comparator->CompareElements(this->List[i][0], elem))
				return i;
		}
		return -1;
	}


	int GetSize() {
		return this->Size;
	}

	int GetCapacity() {
		return this->Capacity;
	}



	ArrayIterator<T> GetBeginIterator();

	ArrayIterator<T> GetEndIterator();

};
