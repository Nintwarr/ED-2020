#include <iostream>
#include <elemento.h>

using namespace std;

std::ostream& operator<<(std::ostream &salida, const elemento & elem) {
    salida << "Elemento: " << elem.ele << ", Máximo: "
            << elem.maximo << std::endl;

    return salida;
}
