#include "Pila_max_VD.h"

using namespace std;

Pila_Max::Pila_Max(){

}

Pila_Max::Pila_Max (Pila_Max & otro){
    *this = otro;

}

Pila_Max::~Pila_Max(){
    this->vector.clear();
}

bool Pila_Max::vacia() const{ 
    return(this->vector.empty());
}

elemento Pila_Max::tope(){
    return (this->vector[this->vector.size()-1]);
}

void Pila_Max::poner(const int & elem){
    
    elemento aux;
    if (this->vector.size() == 0){
        aux.ele = elem;
        aux.maximo = elem;
    } else{
        aux.ele = elem;
        if(elem > this->vector[this->vector.size() -1].maximo){
            aux.maximo = elem;
        } else{
            aux.maximo = this->vector[this->vector.size() -1].maximo;
        }
    }

    this->vector.push_back(aux);
}

void Pila_Max::quitar(){
    elemento aux;
    if (this->vector.size() != 0){
        this->vector.pop_back();
    }
}


Pila_Max& Pila_Max:: operator= (const Pila_Max & otra){

    this->vector = otra.vector;

    return *this;
}
