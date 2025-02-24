/**
  * @author Darío Megías Guerrero y María Sánchez Marcos
  * @file pais.cpp
  * @brief Fichero de implementación para el Pais
  */

#include <pais.h>

istream & operator>>(istream & is, Pais & P) {
    double lat,lng;

    is>>lat>>lng>>P.pais>>P.bandera;

    P.p=Punto(lat,lng,"");
    return is;
}

ostream & operator<<(ostream & os, const Pais &P) {
    os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
    return os;
}
