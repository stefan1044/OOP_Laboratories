#include <string>
#include "templ.h"

using namespace std;

int main() {

    Map<int, const char *> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for(auto[key, value, index]:m){
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for(auto[key, value, index] :  m){
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m.Set(10,"nou");
    m.Set(40, "nou2");
    for(auto[key, value, index] :  m){
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    //Get method
    const char* c ;
    m.Get(10,c);
    printf("%s\n", c);

    //Count method
    printf("%d\n", m.Count());

    //Delete method
    m.Delete(20);
    for(auto[key, value, index] :  m){
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    //Includes method
    Map<int, const char *> m2;
    m2[10] = "nou";
    m2[30] = "Poo";
    m2[40] = "nou2";

    bool a;
    a=m.Includes(m2);
    if (a) printf("True\n");
    else printf("False\n");

    //Clear Method
    m.Clear();
    for(auto[key, value, index] :  m){
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
