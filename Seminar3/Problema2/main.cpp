#include "Canvas.h"
#include <iostream>
using namespace std;

int main() {
    Canvas a(10, 10);
    a.Clear();
    a.DrawCircle(4, 4, 3, '*');
    a.Print();
    cout << "\n\n\n";
    a.FillCircle(4, 4, 2, '*');
    a.Print();
    cout << "\n\n\n";
    a.DrawRect(2, 2, 6, 6, '*');
    a.Print();
    cout << "\n\n\n";
    a.FillRect(1, 3, 9, 6, '*');
    a.Print();
    cout << "\n\n\n";
    a.SetPoint(9, 9, '*');
    a.Print();
	

	return 0;
}