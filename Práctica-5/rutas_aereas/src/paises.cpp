/**
  * @author Darío Megías Guerrero y María Sánchez Marcos
  * @file paises.cpp
  * @brief Fichero de implementación para los Paises
  */

#include <paises.h>

void Paises::Insertar (const Pais &P) {
    datos.insert(P);
}

void Paises::Borrar (const Pais &P) {
    datos.erase(P);
}

Paises::iterator Paises::begin() {
    Paises::iterator it;
    it.p = datos.begin();
    return it;
}

Paises::const_iterator Paises::begin() const {
    Paises::const_iterator it;
    it.p = datos.cbegin();
    return it;
}

Paises::iterator Paises::end () {
    Paises::iterator it;
    it.p = datos.end();
    return it;
}

Paises::const_iterator Paises::end () const{
    Paises::const_iterator it;
    it.p = datos.cend();
    return it;
}

Paises::iterator Paises::find(const Pais &p) {
    Paises::iterator it;
    set<Pais>::iterator i;
    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
    it.p=i;
    return it;
}

Paises::iterator Paises::find(const Punto &p) {
    Paises::iterator it;
    set<Pais>::iterator i;
    for (i=datos.begin(); i!=datos.end() && !((*i).GetPunto()==p);++i);
    it.p=i;
    return it;
}

istream & operator>>(istream & is, Paises & R) {
    Paises rlocal;

    //leemos el comentario
    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Pais P;
    while (is>>P){
        rlocal.Insertar(P);
    }

    R=rlocal;
    return is;
}

ostream & operator<<(ostream & os, const Paises &R) {
    Paises::const_iterator it;

    for (it=R.begin(); it!=R.end(); ++it){
        os<<*it<<"\t";
    }
    return os;
}
