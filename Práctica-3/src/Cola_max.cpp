#include "Cola_max.h"

using namespace std;

Cola_Max::Cola_Max(){

}

Cola_Max::Cola_Max (Cola_Max & otro){
    *this = otro;

}

Cola_Max::~Cola_Max(){
}

bool Cola_Max::vacia() const{ 
    return(this->pila.empty());
}

elemento Cola_Max::front(){
    std::stack<elemento> auxiliar;

    while (!this->pila.empty()){
        auxiliar.push(this->pila.top());
        this->pila.pop();
    }

    elemento resul = auxiliar.top();

        while (!auxiliar.empty()){
        this->pila.push(auxiliar.top());
        auxiliar.pop();
    }

    return resul;
}

elemento Cola_Max::back(){
    return (this->pila.top());
}

void Cola_Max::poner(const int & elem){
    
    elemento aux;
    if (this->pila.size() == 0){
        aux.ele = elem;
        aux.maximo = elem;
    } else{
        aux.ele = elem;
        if(elem > this->pila.top().maximo){
            aux.maximo = elem;
        } else{
            aux.maximo = this->pila.top().maximo;
        }
    }

    this->pila.push(aux);
}

void Cola_Max::quitar(){
   std::stack<elemento> auxiliar;

    while (!this->pila.empty()){
        auxiliar.push(this->pila.top());
        this->pila.pop();
    }

    auxiliar.pop();

    while (!auxiliar.empty()){
        this->pila.push(auxiliar.top());
        auxiliar.pop();
    }

}


Cola_Max& Cola_Max:: operator= (const Cola_Max & otra){

    this->pila = otra.pila;

    return *this;
}
