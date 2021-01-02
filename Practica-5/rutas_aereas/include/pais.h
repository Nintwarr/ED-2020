#ifndef _PAIS_H_
#define _PAIS_H_

/**
  * @file pais.h
  * @brief Fichero cabecera del TDA Pais
  *
  * Gestiona la información que necesitamos sobre países
  */

/**
 *  @brief T.D.A. Pais
 *
 *
 * Una instancia @e c del tipo de dato abstracto Pais almacena la siguiente información
 * sobre un páis:
 * - Su punto geogŕafico representado con nuestra clase @e Punto.
 * - El nombre del país, una cadena de carácteres.
 * - La ruta de la imagen en la que está su bandera, otra cadena de carácteres.
 *
 * Para cada dato podremos usar su dominio completo.
 *
 * @author María Sánchez Marcos y Darío Megías Guerrero
 * @date Enero 2021
*/
#include "punto.h"
class Pais{
private:
    Punto p;        ///< Punto geográfico
    string pais;    ///< Nombre del país
    string bandera; ///< Imagen de la bandera

public:

    /**
     * @brief Constructor por defecto
     */
    Pais(){}

    /**
     * @brief Getter del atributo @e p, que es un @c Punto geográfico
     * @return Un objeto de la clase @e Punto
     */
    Punto GetPunto()const {return p;}

    /**
     * @brief Getter del atributo @e pais
     * @return Un string con el nombre del país
     */
    string GetPais()const{return pais;}

    /**
     * @brief Getter del atributo @e bandera
     * @return Un string con el nombre del archivo que tiene la badera
     */
    string GetBandera()const{return bandera;}

    /**
     * @brief Operador @e "menor que" que determina cuándo un páis es menor que otro
     * @param P Otro país con el que comparar el actual
     * @return @c Verdadero si el nombre del país actual está por debajo en orden alfabético.
     *         En caso contrario, devuelve @c Falso
     */
    bool operator<(const Pais &P)const{
	    return pais < P.GetPais();
    }

    /**
     * @brief Operador de igualdad
     * @param P Otro país con el que comprar el actual
     * @return @c Verdadero si tanto el nombre del país como su punto geofráfico
     *         son iguales. @c Falso en caso contrario.
     */
    bool operator==(const Pais &P)const{
	    return pais == P.pais && p == P.GetPunto();
    }

    /**
     * @brief Operador de igualdad
     * @param P Un punto geográfico con el que comparar el actual
     * @return @c Verdadero si el punto geográfico del país actual es
     *         igual a @e P. @c Falso en caso contrario
     */
    bool operator==(const Punto &P)const{
        return p == P;
    }

    /**
     * @brief Operador de entrada
     * @param is Flujo de entrada
     * @param P País que le pasamos al flujo de entrada
     * @return Referencia al flujo de entrada en el que leemos los datos
     *         para rellenar nuestro país
     */
    friend istream & operator>>(istream & is, Pais & P){
        double lat,lng;

        is>>lat>>lng>>P.pais>>P.bandera;

        P.p=Punto(lat,lng,"");
        return is;
    }

    /**
     * @brief Operador de salida
     * @param os Flujo de salida
     * @param P País que le pasamos al flujo de salida
     * @return Referencia al flujo de salida en el que volcamos los datos
     *         de nuestro país
     */
    friend ostream & operator<<(ostream & os, const Pais &P){
        os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
        return os;
    }
};

#endif
