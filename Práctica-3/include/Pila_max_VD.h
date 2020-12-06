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

#include <elemento.h>
#include <vector>


/**
 *  @brief PilaMax_VD
 *  Pila_Max implementada a partir de un vector dinámio de la STL :)
 *
 *
 *
 * @author María Sánchez Marcos y Darío Guerrero Megías
 * @date Noviembre 2020
*/

class Pila_Max {
private:

    std::vector<elemento> vector;

public:
    /**
     * @brief Constructor por defecto
     */
    Pila_Max();

    /**
     * @brief Constructor de copia
     * @param otra La pila que se va a asignar.
     */
    Pila_Max (Pila_Max & otro);

    /**
     * @brief DESTRUCTOR
     */

    ~Pila_Max();

    /**
     * @brief Operador de asignación
     * @param otra La pila que se va a asignar.
     */
    Pila_Max &operator= (const Pila_Max & otra);

    /**
     * @brief Devuelve true si la cola está vacía, false si no
     */
    bool vacia () const;

    /**
     * @brief Devuelve el elemento tope de la pila
     */
    elemento tope ();

    /**
     * @brief añade el elemento elem al tope de la pila
     * @param elem elemento que se va a añadir al tope.
     */
    void poner (const int & elem);

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
