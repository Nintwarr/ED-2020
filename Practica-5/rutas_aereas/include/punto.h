/**
  * @author Darío Megías Guerrero y María Sánchez Marcos 
  * @file punto.h
  * @brief Fichero cabecera para el TDA
  *
  * Representa puntos geograficos
  *
  */

#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>

using namespace std;

class Punto {
    private:
        double latitud;
        double longitud;

    public:

    /**
     * @brief Crea un objeto tipo Punto
     * @see Constructor sin parámetros
     */
        Punto(){
            latitud = longitud = 0;
        }

    /**
     * @brief Crea un objeto tipo Punto a partir de otro
     *
     * @param otro es el Punto que queremos copiar
     * @see Constructor de copia
     */
        Punto(const Punto & otro);

    /**
     * @brief Crea un objeto de tipo Punto a partir de su latitud y longitud
     *
     * @param lat Latitud del punto
     * @param lon longitud del punto
     *
     * @see  Constructor por parámetros
     */

        Punto (const double & lat, const double & lon);

    /**
     * @brief Asigna un valor al atributo latitud
     * @param lat Latitud a signar
    
     *
     * @see setLatitud
     */
        void setLatitud (const double & lat);

    /**
     * @brief Asigna un valor al atributo longitud
     * @param lon Longitud a signar
    
     *
     * @see setLongitud
     */
        void setLongitud (const double & lon);
        
    /**
     * @brief Devuelve el valor del atributo latitud
     * @return Valor de latitud
     *
     * @see getLatitud
     */
        double getLatitud();

    /**
     * @brief Devuelve el valor del atributo longitud
     * @return Valor de longitud
     *
     * @see getLongitud
     */
        double getLongitud();

    /**
     * @brief  Compara que punto es menos según el criterio de menor latitud
     *
     * @param p El punto con el que lo queremos comparar
     * @return Devuelve true si es menor y false si no lo es 
     *
     * @see Operator<
     */
        bool operator< (const Punto & p) const;

    /**
     * @brief  Compara que dos puntos son iguales
     *
     * @param p El punto con el que lo queremos comparar
     * @return Devuelve true son iguales, false si no lo son
     *
     * @see Operator==
     */
        bool operator== (const Punto & p) const;


    /**
     * @brief  Operador de entrada para objetos de tipo Punto
     *
     * @param is flujo de entrada
     * @param p El punto a insertar
     * @return Devuelve el flujo is
     *
     * @see Operator>>
     */
        friend istream & operator >> (istream & is, Punto & p);

    /**
     * @brief  Operador de salida para objetos de tipo Punto
     *
     * @param os flujo de salida
     * @param p El punto que queremos mostrar
     * @return Devuelve el flujo os
     *
     * @see Operator>>
     */
        friend ostream & operator << (ostream & os, const Punto & p);



};

#endif