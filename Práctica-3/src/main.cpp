#include <iostream>
#include "pila_max.h"
#include "elemento.h"

using namespace std;

int main(){
    Pila_Max p;
    int i;
    for ( i=10; i>=0 ; i--){
        p.poner(i);
    }
    p.poner(32);
    p.poner(2);
    
    while (!p.vacia() ){
        elemento x = p.tope();
        cout << x << endl;
        p.quitar();
    }
    return 0;
}