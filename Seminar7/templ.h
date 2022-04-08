template<class T>
class vector {
private:
    T *array;
    int numberOfElements;
    int maxElements;
public:
    vector() {
        array = nullptr;
        numberOfElements = 0;
        maxElements = 0;
    }
    ~vector(){
        delete[] this->array;
        this->numberOfElements=-1;
        this->maxElements=-1;
    }

    void push(T element) {
        if (this->maxElements == 0) {
            array = new T[1];
            this->maxElements = 1;
        }
        if (this->numberOfElements == this->maxElements) {
            T *temp = new T[this->maxElements * 2];
            for (int i = 0; i < this->maxElements; i++) {
                temp[i] = this->array[i];
            }
            delete[] this->array;
            this->array = temp;
            this->maxElements *= 2;
        }
        this->array[this->numberOfElements] = element;
        this->numberOfElements++;
    }

    T pop() {
        return this->array[this->numberOfElements - 1];
    }

    void remove(int index) {
        if (index>=this->numberOfElements) return;
        this->numberOfElements--;
        for (int i = index; i < this->numberOfElements - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
    }

    void insert(T element, int index) {
        if(index >= this->numberOfElements) return;
        this->push(element);
        T aux = this->array[index];
        this->array[index] = this->array[this->numberOfElements - 1];
        this->array[numberOfElements - 1] = aux;
    }

    static bool defaultSort(T a, T b) {
        if (a <= b) return true;
        return false;
    }
    void sort(bool (*function)(T, T) = vector::defaultSort) {
        for (int i = 0; i < this->numberOfElements - 1; i++) {
            for (int j = i + 1; j < this->numberOfElements; j++) {
                if (!function(array[i], array[j])) {
                    T aux = array[i];
                    array[i] = array[j];
                    array[j] = aux;
                }
            }
        }
    }

    T get(int index) {
        if (index>=this->numberOfElements) exit(-1);
        return this->array[index];
    }

    void set(T element, int index) {
        if (index < this->numberOfElements) {
            this->array[index] = element;
        }
    }

    int count() {
        return this->numberOfElements;
    }

    static bool defaultCompare(T a, T b){
        if (a==b) return true;
        return false;
    }
    int firstIndexOf(T element, bool(*function)(T, T) = vector::defaultCompare){
        for(int i = 0; i < this->numberOfElements; i ++) {
            if (function(this->array[i], element))
                return i + 1;
        }
        return -1;
    }

};