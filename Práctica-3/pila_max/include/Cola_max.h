/**
  * @file Cola_max.h
  * @author Darío Megías Guerrero & María Sánchez Marcos
  * @date 5 Dec 2020
  * @copyright 2020 Darío Megías Guerrero & María Sanchez Marcos
  * @brief Fichero cabecera de ColaMax
  *
  * Gestiona una secuencia de elementos con estructura de cola en la que encontramos
  * dos objetos, el elemento de la cola front, el back y el mayor valor hasta el momento
  *
  */
#ifndef COLA_MAX
#define COLA_MAX

#include "elemento.h"
#include <stack>


/**
 *  @brief ColaMax
 *  Cola_Max implementada a partir de una Pila Stack de la STL :)
 *
 *
 *
 * @author María Sánchez Marcos y Darío Megías Guerrero
 * @date Diciembre 2020
*/

class Cola_Max {
private:

    std::stack<elemento> pila;

public:
    /**
     * @brief Constructor por defecto
     */
    Cola_Max();

    /**
     * @brief Constructor de copia
     * @param otra La cola que se va a asignar.
     */
    Cola_Max (Cola_Max & otro);

    /**
     * @brief DESTRUCTOR
     */

    ~Cola_Max();

    /**
     * @brief Operador de asignación
     * @param otra La cola que se va a asignar.
     */
    Cola_Max &operator= (const Cola_Max & otra);

    /**
     * @brief Devuelve true si la cola está vacía, false si no
     */
    bool vacia () const;

    /**
     * @brief Devuelve el elemento frente de la cola
     */
    elemento front ();

    /**
     * @brief Devuelve el elemento final de la cola
     */
    elemento back ();

    /**
     * @brief añade el elemento elem a la cola
     * @param elem elemento que se va a añadir.
     */
    void poner (const int & elem);

    /**
     * @brief Elimina el elemento del frente de la cola
     */
    void quitar ();

    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos () const;


};


#endif
