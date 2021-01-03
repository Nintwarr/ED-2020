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
    return *it;
}

Almacen_Ruta::iterator Almacen_Ruta::begin(){
    Almacen_Ruta::iterator it;
    it.p = ruta.begin();
    return it;
}

Almacen_Ruta::const_iterator Almacen_Ruta::begin(){
    Almacen_Ruta::const_iterator it;
    it.p = ruta.cbegin();
    return it;
 }

Almacen_Ruta::iterator Almacen_Ruta::end(){
    Almacen_Ruta::iterator it;
    it.p = ruta.end();
    return it;
}

Almacen_Ruta::const_iterator Almacen_Ruta::end(){
    Almacen_Ruta::const_iterator it;
    it.p = ruta.cend();
    return it;
 }