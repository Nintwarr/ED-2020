#include <Pila_max_Cola.h>

void Pila_max_cola::copiar(const Pila_max_Cola &otra, unsigned int elem_dejar = 0) {
    assert(otra.num_elementos() > 0);

    if (otra.num_elementos() - elem_dejar > 0) {
        for (int i=0; i<otra.cola.num_elementos()-elem_dejar; ++i) {
        this->cola.poner(otra.cola.frente());
        otra.cola.quitar();
    }
    }
}

void Pila_max_Cola::borrar() {
    while (!this->cola.vacia()) {
        this->cola.quitar();
    }
}

Pila_max_Cola::Pila_max_cola(const Pila_max_Cola &otra) {
    this->copiar(otra);
}

Pila_max_Cola & Pila_max_Cola::operator=(const Pila_max_Cola &otra) {
    this->borrar();
    this->copiar(otra);
}

bool Pila_max_Cola vacia() const {
    return this->cola.vacia();
}

elemento Pila_max_Cola::tope() const {
    Pila_max_cola aux(*this);

    copiar(aux,1);

    this->poner(aux.frente());

    return aux.frente();
}

void Pila_max_Cola::poner(const int elem) {
    elemento aux = tope();
    aux.ele = elem;
    aux.maximo = (elem > aux.maximo) ? elem : aux.maximo;

    this->cola.poner(aux);
}

void Pila_max_Cola::quitar() {
    Pila_max_cola aux(*this);

    copiar(aux,1);
}

int Pila_max_Cola::num_elementos() const {
    return this->cola.num_elementos();
}
