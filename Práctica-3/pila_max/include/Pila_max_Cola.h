/**
* @file Pila_max_Cola.h
* @author Darío Megías Guerrero & María Sánchez Marcos
* @date 5 Dec 2020
* @copyright 2020 Darío Megías Guerrero & María Sanchez Marcos
* @brief Fichero de cabecera asociado a la pila de pares valor-máximo.
* Implementacion del TDA Pila_Max.
*/

#ifndef _PILA_MAX_COLA_H_
#define _PILA_MAX_COLA_H_

#include <elemento.h>
#include <cola.h>

using namespace std;

/**
* @brief T.D.A. Pila_Max
*
* Una instancia @e c del tipo de dato abstracto @c Pila_max_Cola es un objeto que
* representa una estructura de datos que funciona tal cual funcionan las colas
* tradicionales. La peculiaridad de esta cola es que guarda parejas de valores.
* Así, el primer elemento es el elemento normal con el que trabajamos y el
* segundo representa el valor máximo introducido en la cola hasta el momento.
*
* Para esta versión en concreto, se utiliza un T.D.A. @e cola propio
*
* @author María Sánchez Marcos y Darío Megías Guerrero
* @date Diciembre 2020
*/

class Pila_Max {
private:
    /**
	* @page repPila_max_Cola Rep del TDA Pila_Max con cola
	*
	* @section invPila_max_Cola Invariante de la representación
	*
	* El invariante es:
    * Para todo \e rep.cola.frente().ele = \e e, entonces
    * \e rep.cola.frente().maximo >= \e e.
	*
	* @section faPila_max_Cola Función de abstracción
	*
	* Un objeto válido @e rep del TDA Cola_Max representa a una
    * estructura de datos que se comporta como una \c pila que almacena
	* datos del tipo \c elemento. Estos son parejas valor-maximo.
	*
    * Si la pila tiene \e n elementos y el tope es el elemento n-ésimo:
	* | rep.cola[n]   | Corresponde con rep.cola.ultima.
    * | rep.cola[n-1] |
    * | ...           |
    * | rep.cola[0]   | Corresponde con rep.cola.primera.
	*/

    Cola<elemento> cola; // Estructura que va a almacenar los elementos
    int max = 0;         // Máximo uxiliar necesario para evitar recursividad infinita

    /**
     * @brief Copia una pila en otra
     * @param otra Pila a copiar
     * @param elem_dejar Con cuántos elementos dejar \e otra
     * @post El parámetro \e otra se verá \c modificado de forma que le
     *       quedarán \e elem_dejar elementos
     */
    void copiar(Pila_Max &otra, unsigned int elem_dejar = 0);

    /**
     * @brief Borra la pila
     */
    void borrar();

public:

    /**
     * @brief Constructor sin parámetro que incializa la pila vacía
    */
    Pila_Max(){
    };

    /**
     * @brief Constructor de copia que copia los elementos de
     * una pila_Max a otra.
     * @param copia Instancia de Pila_max_Cola a copiar.
     * @post El parámetro \e otra se verá \c modificado quedando
     *       totalmente vacío.
     */
    Pila_Max(Pila_Max &copia);

    /**
     * @brief Operador de asignación para Pila_max_Cola
     * @param otra Es el \e right-value en la asignación
     * @return Devuleve a la nueva pila una vez hecha la asignación.
     */
    Pila_Max &operator=(Pila_Max &otra);

    /**
     * @brief Indica si la pila se encuentra vacía o no.
     * @return Valor booleano que estará a \e true si la pila
     *         está vacía.
     */
    bool vacia() const;

    /**
     * @brief Devuelve el elemento que hay en el tope de la pila.
     * @return Un dato \e struct que contiene el último valor
     *         almacenado en la pila y el valor máximo almacenado
     *         hasta el momento.
     */
    elemento tope();

    /**
     * @brief Añade un elemento a la pila haciéndose cargo de actualizar
     *        el máximo.
     * @param elem Valor entero a poner en la pila
     */
    void poner(const int elem);

    /**
     * @brief Elimina el elemento que hay en el tope de la pila
     */
    void quitar();

    /**
     * @brief Dice el número de elemento que tiene la pila
     * @return Valor entero que representa el número de elementos
     *         que hay almacenados en al pila
     */
    int num_elementos() const;


};

#endif
