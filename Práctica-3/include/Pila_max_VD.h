/**
  * @file Pila_max_VD.h
  * @brief Fichero cabecera del TDA PilaMAX
  *
  * Gestiona una secuencia de elementos con estructura de pila en la que encontramos 
  * dos objetos, el elemento de la pila y el tope hasta el momento
  *
  */
#ifndef PILA_MAX_VD
#define PILA_MAX_VD

#include <vector>


struct elemento{
    int ele; //Elemnto a almacenar
    int maximo; //el maximo
};

class PilaMax {
private:

    elemento *pila;

public:
    PilaMax();
    PilaMax (PilaMax & otro);
    ~PilaMax();

    /**
     * @brief Operador de asignación
     * @param otra La pila que se va a asignar.
     */
    PilaMax operator= (const PilaMax otra);

    /**
     * @brief Devuelve true si la cola está vacía, false si no
     */
    bool vacía () const;

    /**
     * @brief Devuelve el elemento tope de la pila
     */
    elemento tope ();

    /**
     * @brief añade el elemento elem al tope de la pila
     * @param elem elemento que se va a añadir al tope.
     */
    void anadir (const elemento & elem);

    /**
     * @brief Elimina el elemento tope de la pila
     */
    void quitar ();
    
    /**
     * @brief Devuelve el número de elementos de la pila
     */
    int num_elementos () const;


};


#endif