#include "almacenrutas.h"

Almacen_Rutas::Almacen_Rutas(){
    Ruta r;
    ruta.emplace("", r);
}

void Almacen_Rutas::Insertar (const Ruta & R){
    ruta.emplace("", R);
}

void Almacen_Rutas::Borrar (const Ruta &R){
    map <string,Ruta>:: iterator it = ruta.find (R.GetCode());
    ruta.erase(it);

}

Ruta Almacen_Rutas::GetRuta (const string & a){
    map <string,Ruta>:: iterator it = ruta.find(a);
    return (*it).second;
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
