#include <Pila_max_Cola.h>

void Pila_Max::copiar(Pila_Max &otra, unsigned int elem_dejar) {
    /*
    Copiamos la otra cola en la instancia actual accediendo al frente
    de la otra cola y luego borrándolo para acceder al elemento
    siguiente
    */
    if (otra.num_elementos() - elem_dejar >= 0) {
        int tam_otra = otra.num_elementos() - elem_dejar;

        for (int i=0; i<tam_otra; ++i) {
        this->cola.poner(otra.cola.frente());
        otra.cola.quitar();
        }
        this->max = otra.max;
    }
}

void Pila_Max::borrar() {
    while (!this->cola.vacia()) {
        this->cola.quitar();
    }
    this->max = 0;
}

Pila_Max::Pila_Max(Pila_Max &otra) {
    this->copiar(otra);
}

Pila_Max & Pila_Max::operator=(Pila_Max &otra) {
    this->borrar();
    this->copiar(otra);
    return *this;
}

bool Pila_Max::vacia() const {
    return this->cola.vacia();
}

elemento Pila_Max::tope(){
    // Hacemos una copia temporal porque tenemos que
    // acceder al último elemento de la cola
    Pila_Max aux(*this);

    // Dejamos un elemento en la cola
    copiar(aux,1);

    // Copiamos el último elemento para tener nuestra
    // pila íntegra
    this->poner(aux.tope().ele);

    return aux.tope();
}

void Pila_Max::poner(const int elem) {
    elemento aux;
    cout << "poner" << endl;
    /*
    Si hay más de un elemento, comprobamos si el elemento
    a insertar es mayor que el máximo hasta ahora.
    - Si es: actualizamos el máximo global y lo añadimos
             al elemento a insertar también
    - Si no es: ponemos como máximo el máximo global

    Si no hay elementos, el nuevo elemento es el máximo hasta ahora
    */
    if (this->num_elementos() > 0) {
        if (elem > this->max) {
            this->max = elem;
            aux.maximo = elem;
        } else {
            aux.maximo = this->max;
        }
    } else {
        this->max = elem;
        aux.maximo = elem;
    }
    // En cualquier caso, el campo ele se rellena con elem
    aux.ele = elem;

    // Se añade a la cola
    this->cola.poner(aux);
}

void Pila_Max::quitar() {
    cout << "quitar" << endl;
    Pila_Max aux(*this);

    copiar(aux,1);

    if (aux.tope().ele == this->max)
        this->max = this->tope().maximo;
}

int Pila_Max::num_elementos() const {
    return this->cola.num_elementos();
}
