class Sort{
    int* vec;
    int numberOfElements;

public:

    Sort(int count, int min, int max);
    Sort();
    Sort(int arr[], int count);
    Sort(int count, ...);
    Sort(char string[]);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

    int partition(int start, int end);

    void qs(int start, int end);

};