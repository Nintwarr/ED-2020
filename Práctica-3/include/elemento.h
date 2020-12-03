#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

#include <iostream>

struct elemento {
    int ele;
    int maximo;

    std::ostream& operator<<(std::ostream &salida) {
        salida << "Elemento de la pila: " << ele << ", Máximo de la pila: "
               << maximo << std::endl;

        return salida;
    }
};

#endif
