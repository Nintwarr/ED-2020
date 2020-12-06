#include <iostream>
#include "Cola_max.h"

using namespace std;

int main(){
    Cola_Max c;
    int i;
    for ( i=10; i>=0 ; i--){
        c.poner(i);
    }
    c.poner(32);
    c.poner(2);

    while (!c.vacia() ){
        elemento x = c.front();
        cout << x << endl;
        c.quitar();
    }
    return 0;
}
