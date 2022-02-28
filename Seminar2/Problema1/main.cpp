#include "NumberList.h"
using namespace std;
int main() {
	NumberList Obiect ;
	//Pentru a initializa count
	Obiect.Init();
	//Adaugam elemente
	Obiect.Add(4);
	Obiect.Add(1);
	//Sortam elementele
	Obiect.Sort();
	//Pentru a afisa elementele
	Obiect.Print();
}