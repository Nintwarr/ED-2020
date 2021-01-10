/**
  * @author Darío Megías Guerrero y María Sánchez Marcos
  * @file almacenrutas.cpp
  * @brief Fichero de implementación para el Almacen de Rutas
  */

#include "almacenrutas.h"


void Almacen_Rutas::Insertar (const Ruta & R){
    ruta.emplace(R.GetCode(), R);
}

void Almacen_Rutas::Borrar (const Ruta &R){
    map <string,Ruta>:: iterator it = ruta.find (R.GetCode());
    ruta.erase(it);

}

Ruta Almacen_Rutas::GetRuta (const string & a){
    map <string,Ruta>:: iterator it = ruta.find(a);
    if (it != ruta.end())
        return (*it).second;
    else
        return Ruta();
}

Almacen_Rutas::iterator Almacen_Rutas::begin(){
    Almacen_Rutas::iterator it;
    it.p = ruta.begin();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::begin()const{
    Almacen_Rutas::const_iterator it;
    it.p = ruta.cbegin();
    return it;
 }

Almacen_Rutas::iterator Almacen_Rutas::end(){
    Almacen_Rutas::iterator it;
    it.p = ruta.end();
    return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::end()const{
    Almacen_Rutas::const_iterator it;
    it.p = ruta.cend();
    return it;
}


istream & operator >> (istream & is, Almacen_Rutas & AR){

    string aux;
    getline(is,aux);

    Ruta R;

    if ( aux == "#Rutas"){

        while(is >> R){
            AR.Insertar(R);
        }
    }

    return is;
}

ostream & operator << (ostream & os, const Almacen_Rutas &R){
    os << "#Rutas" << endl;

    Almacen_Rutas::const_iterator it;

    for (it = R.begin(); it != R.end();++it){
        os << (*it) << endl;
    }

    return os;
}
