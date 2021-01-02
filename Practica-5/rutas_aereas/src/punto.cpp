#include "punto.h"


Punto::Punto (const Punto & otro){
    latitud = otro. latitud;
    longitud = otro. longitud;
}

Punto::Punto (const double & lat, const double & lon){
    latitud = lat;
    longitud = lon;
}

void Punto::setLatitud (const double & lat){
    latitud = lat;
}

void Punto::setLongitud (const double & lon){
    longitud = lon;
}

double Punto::getLatitud(){
    return latitud;
}

double Punto::getLongitud(){
    return longitud;
}

bool Punto::operator< (const Punto & p) const {
    if (latitud == p.latitud) {
        if (longitud == p.longitud){
            return false;
        } else if (longitud < p.longitud){
            return true;
        } else{
            return false;
        }
    } else if (latitud < p.latitud){
        return true;
    } else {
        return false;
    }

}

bool Punto::operator== (const Punto & p) const {
    if (latitud != p.latitud) {
        return false;
    } else if (longitud != p.longitud){
        return false;
    } else {
        return true;
    }
}

istream & operator >> (istream & is, Punto & p){
    is >> 
}

ostream & operator << (ostream & os, const Punto & p){
     os << "("<<  p.latitud << ")"<< ", (" << p.longitud << ")"<<endl;
}