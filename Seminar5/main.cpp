#include "Number.h"
#include <iostream>

using namespace std;

int main(){
    Number n1("15",8);
    n1.Print();
    n1.SwitchBase(16);
    n1.Print();
    Number n2("13",8);
    Number n3=n1+n2;
    n3.Print();
    Number n4=n1-n2;
    n4.Print();

    cout<<n4[0]<<'\n';

    cout<<(n1>n2)<<' ';
    cout<<(n1>=n2)<<' ';
    cout<<(n1<n2)<<' ';
    cout<<(n1<=n2)<<'\n';

    --n2;
    n2.Print();
    n3--;
    n3.Print();
    cout<<n3.GetDigitsCount()<<'\n';
    cout<<n3.GetBase();

    return 0;
}

