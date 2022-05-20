#include "templ.h"
#include <iostream>
#include <exception>
#include <vector>

using namespace std;

int desc(const int &a,const int &b) {
    if (a == b)
        return 0;
    else if (a < b)
        return 1;
    return -1;
}
/*
class compareAsc : public Compare {
    int CompareElements(void* e1, void* e2);
    int CompareElements(const int& e1, const int& e2) {
        if (e1 == e2)
            return 0;
        else if (e1 < e2)
            return -1;
        return 1;
    }
}comparator;*/

int main() {

    Array<int> A(15);
    Array<int> B(A);
    
    int n = 25;
    A += n;
    cout << A[0]<<'\n';
    A.Insert(2, 17);
    cout << A[2]<<'\n';
    B.Insert(0,A);
    cout <<B[0]<<' '<< B[2] << '\n';
    B.Delete(2);
    
    bool test1 = (B = A);
    if (test1 == true )
        cout<<"Copied" << '\n';
    cout << B[2] << '\n';

    A += 19, A += 221;
    A.Sort();
    for (int i = 0; i < A.GetSize(); i++)
        cout << A[i] << ' ';
    cout << '\n';
    A.Sort(desc);
    for (int i = 0; i < A.GetSize(); i++)
        cout << A[i] << ' ';
    cout << '\n';
   //compareAsc* point1;
   //point1 = &comparator;
   //A.Sort(point1);
    for (int i = 0; i < A.GetSize(); i++)
        cout << A[i] << ' ';
    cout << '\n';

    cout<<A.BinarySearch(221)<<'\n';
    cout << A.BinarySearch(221, desc) << '\n';
    //cout<<A.BinarySearch(221, point1) << '\n';

    cout << A.Find(19) << '\n';
    cout << A.Find(19, desc) << '\n';
    //cout << A.Find(19, point1) << '\n';
    
    cout << A.GetSize() << ' ' << A.GetCapacity() << '\n';
    


    return 0;

}
