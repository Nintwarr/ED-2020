#ifndef _RUTA_H_
#define _RUTA_H_

/**
  * @file ruta.h
  * @brief Fichero cabecera del TDA Ruta
  * @author María Sánchez Marcos y Darío Megías Guerrero
  *
  * Maneja una lista de puntos geográficos y un código asociado a la lista
  */

 /**
  *  @brief T.D.A. Ruta
  *
  *
  * Una instancia @e c del tipo de dato abstracto Ruta almacena una colección
  * de puntos geográficos. La forma en que se almacenan es usando el tipo @c list de la STL.
  * De forma que estarán ordenadas por orden de inserción y podrá haber repetidos.
  *
  * Además, se almacena un código (cadena de carácteres) que identificará a la ruta.
  *
  * Para cada dato podremos usar su dominio completo.
  *
  * @author María Sánchez Marcos y Darío Megías Guerrero
  * @date Enero 2021
  */

#include <string>
#include <list>
#include <punto.h>

using namespace std;

class Ruta {
private:
    list<Punto> puntos; ///< Lista de la STL de puntos geográficos.
    string code;        ///< Código que identifica a la ruta.
public:

    /**
     * @brief Constructor por defecto
     */
    Ruta();

    /**
     * @brief Inserción de un punto en la colección
     * @param n Punto a insertar en la lista
     * @post En cualquier caso, la lista tendrá un elemento más y @e n
     *       quedará al final de la lista
     */
    void Insertar(const Punto &n);

    /**
     * @brief Borrado de un punto
     * @param n Punto a borrar de lal ista
     * @post Si se encuentra el elemento @e n en la lista, se elimina.
     *       Sino, no ocurre nada.
     */
    void Borrar(const Punto &n);

    /**
     * @brief Getter del código que identifica la ruta
     * @return Cadena de tipo @e string que representa el código de la ruta.
     */
    string GetCode() const {return code;}


    /**
     * @brief Setter del cópdigo que identifica la ruta
     * @param code Código a insertar
     */
    void SetCode(const string &code) {this->code = code;}

    /**
     * @brief Getter del numero de puntos que tiene la ruta
     * @return Numero de puntos de la ruta (int)
     */
    int GetNumPuntos() const {return puntos.size();}

    /**
     * @brief Operador de igualdad
     * @param R Otra ruta con la que comparar la actual
     * @return @c Verdadero si la ruta actual tiene la misma secuencia de Puntos.
     *         @c Falso en caso contrario.
     */
    bool operator==(const Ruta &R) const;

    /**
     * @brief Operador @e "menor que" que determina cuándo una ruta es menor que otra.
     * @param R Otra ruta con la que comparar la actual
     * @return @c Verdadero si el número de puntos en la ruta actual es menor que en @e R.
     *         Si tiene el mismo número de puntos, devolverá @c Verdadero si todos los puntos
     *         en la ruta actual son menores que en R.
     *         @c Falso en caso contrario.
     */
    bool operator<(const Ruta &R) const;

    /**
     *  @brief iterator del T.D.A. Ruta
     *
     *
     * Una instancia @e c del tipo de dato abstracto @e iterator representa
     * una referencia a un elemento concreto de la colección de puntos o
     * al final de dicha colección.
     *
     * @author María Sánchez Marcos y Darío Megías Guerrero
     * @date Enero 2021
     */
    class iterator {
    private:
        list<Punto>::iterator p;
    public:

        /**
         * @brief Operador de acceso a memoria
         * @return Devuelve una referencia al punto que está en la posición del iterador
         */
        Punto & operator*(){return *p;}

        /**
         * @brief Operador de incremento
         * @return Devuelve un iterador de la clase Ruta incrementado en una unidad
         */
        iterator & operator++(){++p; return *this;}

        /**
         * @brief Operador de decremento
         * @return Devuelve un iterador constante de la clase Ruta decrementado en una unidad
         */
        iterator & operator--(){--p; return *this;}

        /**
         * @brief Operador igualdad
         * @param i Una referencia constante del iterador que queremos comparar
         * @return Devuelve un booleano, true en caso de que los iteradores sean iguales, false en el contrario
         */
        bool operator==(const iterator &i){return p == i.p;}

        /**
         * @brief Operador desigualdad
         * @param i Una referencia constante del iterador que queremos comparar
         * @return Devuelve un booleano, false en caso de que los iteradores sean iguales, true en el contrario
         */
        bool operator!=(const iterator &i){return p != i.p;}

        friend class Ruta;
    };

    /**
     *  @brief iterator constante del T.D.A. Ruta
     *
     *
     * Una instancia @e c del tipo de dato abstracto @e iterator representa
     * una referencia a un elemento concreto de la colección de puntos o
     * al final de dicha colección.
     *
     * Estas referencias son constantes de forma que se puede acceder a su
     * información pero no modificarla.
     *
     * @author María Sánchez Marcos y Darío Megías Guerrero
     * @date Enero 2021
     */
    class const_iterator {
    private:
        list<Punto>::const_iterator p;
    public:

        /**
         * @brief Operador de acceso a memoria
         * @return Devuelve una referencia constante al punto que está en la posición del iterador
         */
        const Punto & operator*(){return *p;}

        /**
         * @brief Operador de incremento
         * @return Devuelve un iterador constante de la clase punto incrementado en una unidad
         */
        const_iterator & operator++(){++p; return *this;}

        /**
         * @brief Operador de decremento
         * @return Devuelve un iterador constante de la clase punto decrementado en una unidad
         */
        const_iterator & operator--(){--p; return *this;}

        /**
         * @brief Operador igualdad
         * @param i Una referencia constante del iterador que queremos comparar
         * @return Devuelve un booleano, true en caso de que los iteradores sean iguales, false en el contrario
         */
        bool operator==(const const_iterator &i){return p == i.p;}

        /**
         * @brief Operador desigualdad
         * @param i Una referencia constante del iterador que queremos comparar
         * @return Devuelve un booleano, false en caso de que los iteradores sean iguales, true en el contrario
         */
        bool operator!=(const const_iterator &i){return p != i.p;}

        friend class Ruta;
    };

    /**
     * @brief Inicio de la colección
     * @return Devuelve un iterador de la lista de puntos @e que apunta al primer elemento de
     *         la colección
     */
    iterator begin();

    /**
     * @brief Inicio de la colección
     * @return Devuelve un iterador constante de la lista de puntos @e que apunta al primer elemento de
     *         la colección.
     */
    const_iterator begin() const;

    /**
     * @brief Fin de la colección
     * @return Devuelve un iterador de la lista de puntos @e que apunta al último elemento de
     *         la colección. Este elemento no contiene información.
     */
    iterator end();

    /**
     * @brief Inicio de la colección
     * @return Devuelve un iterador constante de la lista de puntos @e que apunta al último elemento de
     *         la colección.
     */
    const_iterator end() const;

    /**
     * @brief Búsqueda de un punto dentro de la lista de puntos de la ruta.
     * @param p punto a buscar
     * @return Iterador de la lista de puntos que apunta al punto encontrado.
     *         Si no se encuentra, apunta al final de la lista.
     */
    iterator find(const Punto &p);

    /**
     * @brief Operador de entrada de la ruta
     * @param is Flujo de entrada
     * @param R Otra ruta que se le pasa al flujo de entrada
     * @return Una referencia al flujo de entrada en el que se ha
     *         leído la ruta.
     * @post Si en el flujo se ha seguido el formato correcto,
     *       la colección actual quedará cargada con los datos
     *       encontrados en él.
     */
    friend istream & operator>>(istream & is, Ruta  &R);

    /**
     * @brief Operador de salida de la ruta
     * @param os Flujo de salida
     * @param R Ruta que se le pasa al flujo de salida
     * @return Una referencia al flujo de salida en el que se ha
     *         "escrito" la ruta con un formato determinado
     */
    friend ostream & operator<<(ostream & os, const Ruta &R);
};

#endif
