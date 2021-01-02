/**
  * @file punto.h
  * @brief Fichero cabecera para el TDA
  *
  * Representa puntos geograficos
  *
  */

#ifndef _PUNTO_H_
#define _PUNTO_H_

class Punto {
    private:
        double latitud;
        double longitud;

    public:

    /**
     * @brief Crea un objeto tipo Punto
     * @see Constructor sin parámetros
     */
        Punto();

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

};

#endif
