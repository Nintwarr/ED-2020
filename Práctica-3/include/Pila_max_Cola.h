#ifndef _PILA_MAX_COLA_H_
#define _PILA_MAX_COLA_H_

#include <elemento.h>
#include <cola.h>

class Pila_max_Cola {
private:
    Cola<elemento> cola;
public:
    Pila_max_Cola() : cola(Cola()) {
    };

    Pila_max_Cola(const Pila_max_Cola &copia);
};

#endif
