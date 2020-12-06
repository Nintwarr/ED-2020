#include <iostream>
#include "elemento.h"

using namespace std;

std::ostream& operator<<(std::ostream &salida, const elemento & elem) {
    salida << "Elemento de la pila: " << elem.ele << ", Máximo de la pila: "
            << elem.maximo << std::endl;

    return salida;
}