#include <iostream>
#include "templ.h"

using namespace std;

float char_to_float(const char *temp) {
    float nr = 0;
    bool positive = 1;
    if (*temp == '-')
        positive = 0, temp++;
    while ((*temp) != '.' && (*temp) != 0)
        nr = nr * 10 + ((*temp) - '0'), temp++;
    if (*temp == '.') {
        float m = 0.1;
        for (temp++; *temp != 0; temp++, m /= 10)
            nr = nr + m * ((*temp) - '0');
    }
    if (positive)
        return nr;
    return -nr;
}

float operator "" _Kelvin(const char *temp) {
    return char_to_float(temp) - 273.15;
}


float operator "" _Kelvin(const char *temp, size_t sz) {
    return char_to_float(temp) - 273.15;
}


float operator "" _Fahrenheit(const char *temp) {
    return (char_to_float(temp) - 32) / 1.8;
}

float operator "" _Fahrenheit(const char *temp, size_t sz) {
    return (char_to_float(temp) - 32) / 1.8;
}

bool descSort(int a, int b){
    if (a>b) return true;
    return false;
}
bool notEqual(int a, int b){
    if (a!=b) return true;
    return false;
}

int main() {

    float a = 300_Kelvin;
    cout << a << '\n';
    float b = 120_Fahrenheit;
    cout << b << '\n';


    vector<int> A;
    A.push(12);
    A.push(13);
    A.push(10);
    A.push(11);
    A.push(19);
    A.push(14);

    cout << A.count()<< '\n';

    cout << A.pop() << '\n';

    A.remove(5);
    cout << A.count() << ' ' << A.pop() << '\n';

    A.insert(15,3);
    cout << A.count() << ' ' << A.get(3) << '\n';

    A.sort();
    cout << A.count() << ' ';
    for(int i=0;i<A.count();i++){
        cout<<A.get(i)<<' ';
    }
    cout<<'\n';
    A.sort(descSort);
    for(int i=0;i<A.count();i++){
        cout<<A.get(i)<<' ';
    }
    cout<<'\n';

    A.set(16,5);
    cout<<A.pop()<<'\n';


    cout<<A.firstIndexOf(15)<<' ';
    cout<<A.firstIndexOf(19,notEqual);

    return 0;
}