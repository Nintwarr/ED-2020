#ifndef _PAISES_H_
#define _PAISES_H_

/**
  * @file paises.h
  * @brief Fichero cabecera del TDA Paises
  *
  * Gestiona toda la colección de países disponible
  * utilizando una estructura subyacente del estilo @e conjunto
  */

 /**
  *  @brief T.D.A. Paises
  *
  *
  * Una instancia @e c del tipo de dato abstracto Paises almacena una colección
  * de países. La forma en que se almacenan es usando el tipo @c set de la STL.
  * De forma que quedarán ordenados por nombre y no habrá países repetidos.
  *
  * Para cada dato podremos usar su dominio completo.
  *
  * @author María Sánchez Marcos y Darío Megías Guerrero
  * @date Enero 2021
  */
#include "pais.h"
#include <set>

using namespace std;

class Paises{
private:
    set<Pais> datos; ///< Conjunto de países
public:

    /**
     * @brief Constructor por defecto
     */
    Paises(){}

    /**
     * @brief Insertar un país en la colección
     * @param P El país a insertar
     * @post El conjunto quedará con un elemento más si es nuevo. Además
     *       quedará en la posición tal que haga que el conjunto de países
     *       esté ordenado alfabéticamente.
     *       Si el país a insertar ya se encontraba en el conjunto, se
     *       sustituirá por el nuevo.
     */
    void Insertar(const Pais &P);

    /**
     * @brief Borrar un país del conjunto
     * @param P País a borrar
     * @post Si el país a borrar es igual que uno de dentro del conjunto,
     *       se eliminará. Sino, no ocurrirá nada
     */
    void Borrar(const Pais &P);

    class const_iterator;

    /**
     *  @brief iterator del T.D.A. Paises
     *
     *
     * Una instancia @e c del tipo de dato abstracto @e iterator representa
     * una referencia a un elemento concreto de la colección de países o
     * al final de dicha colección.
     *
     * @author María Sánchez Marcos y Darío Megías Guerrero
     * @date Enero 2021
     */
	class iterator{
	private:
        set<Pais>::iterator p; ///< Iterador del tipo set de la STL
	public:

        /**
         * @brief Operador de acceso a memoria
         * @return Devuelve una referencia al país que esta en la posición del iterador
         */
        Pais & operator*(){return *p;}

        /**
         * @brief Operador de incremento
         * @return Devuelve un iterador de la clase país incrementado en una unidad
         */
        iterator & operator++(){++p; return *this;}

        /**
         * @brief Operador de decremento
         * @return Devuelve un iterador de la clase país decrementado en una unidad
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

	    friend class Paises;
	    friend class const_iterator;
	};

    /**
     *  @brief iterator constante del T.D.A. Paises
     *
     *
     * Una instancia @e c del tipo de dato abstracto @e iterator representa
     * una referencia a un elemento concreto de la colección de países o
     * al final de dicha colección.
     *
     * Estas referencias son constantes de forma que se puede acceder a su
     * información pero no modificarla.
     *
     * @author María Sánchez Marcos y Darío Megías Guerrero
     * @date Enero 2021
     */
    class const_iterator{
	private:
        set<Pais>::const_iterator p; ///< Iterador constante del tipo set de la STL
	public:

        /**
         * @brief Operador de acceso a memoria
         * @return Devuelve una referencia constante al país que esta en la posición del iterador
         */
	    const Pais & operator*(){return *p;}

        /**
         * @brief Operador de incremento
         * @return Devuelve un iterador constante de la clase país incrementado en una unidad
         */
        const_iterator & operator++(){++p; return *this;}

        /**
         * @brief Operador de decremento
         * @return Devuelve un iterador constante de la clase país decrementado en una unidad
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

	    friend class Paises;
	};

    /**
     * @brief Inicio de la colección
     * @return Devuelve un iterador de @e Paises que apunta al primer elemento de
     *         la colección
     */
	iterator begin();

    /**
     * @brief Inicio de la colección
     * @return Devuelve un iterador constante de @e Paises que apunta al primer elemento de
     *         la colección
     */
	const_iterator begin()const;

    /**
     * @brief Fin de la colección
     * @return Devuelve un iterador de @e Paises que apunta al último elemento de
     *         la colección. Este elemento no contiene información.
     */
	iterator end();

    /**
     * @brief Fin de la colección
     * @return Devuelve un iterador constante de @e Paises que apunta al último elemento de
     *         la colección. Este elemento no contiene información.
     */
	const_iterator end()const;

    /**
     * @brief Búsqueda de un país por nombre dentro de la colección.
     * @param p País a buscar
     * @return Un iterador que apunta a la posición en la que se ha encontrado el país.
     *         Si no se encuentra, éste apunta al final de la colección.
     */
	iterator find(const Pais &p);

    /**
     * @brief Búsqueda de un país por punto geográfico dentro de la colección.
     * @param p País a buscar
     * @return Un iterador que apunta a la posición en la que se ha encontrado el país.
     *         Si no se encuentra, éste apunta al final de la colección.
     */
	iterator find(const Punto &p);

    /**
     * @brief Operador de entrada de la colección
     * @param is Flujo de entrada
     * @param R Conjunto de países que se le pasa al flujo de entrada
     * @return Una referencia al flujo de entrada en el que se han
     *         leído los países
     * @post Si en el flujo se ha seguido el formato correcto,
     *       la colección actual quedará cargada con los datos
     *       encontrados en él.
     */
	friend istream & operator>>(istream & is, Paises & R);

    /**
     * @brief Operador de salida del contenedor de países
     * @param os Flujo de salida
     * @param R País que se le pasa al flujo de salida
     * @return Una referencia al flujo de salida en el que se ha
     *         "escrito" el conjunto de países con un formato determinado
     */
	friend ostream & operator<<(ostream & os, const Paises &R);
};

#endif
