/**
  * @author Darío Megías Guerrero y María Sánchez Marcos
  * @file ruta.cpp
  * @brief Fichero de implementación para la Ruta
  */

#include <ruta.h>

void Ruta::Insertar(const Punto &n) {
    puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n) {
   puntos.remove(n);
}

Ruta::Ruta() : puntos(), code() {}

bool Ruta::operator==(const Ruta &R) const {
    bool es_igual = false;
    const_iterator it = begin();
    const_iterator it_r = R.begin();

    for (; it != end() && *it == *it_r; ++it, ++it_r);

    if (it == end())
        es_igual = true;

    return es_igual;
}

bool Ruta::operator<(const Ruta &R) const {
    bool es_menor = false;

    if (puntos.size() < R.puntos.size()) {
        es_menor = true;
    } else if (puntos.size() == R.puntos.size()) {
        const_iterator it = begin();
        const_iterator it_r = R.begin();

        for (; it != end() && *it < *it_r; ++it, ++it_r);

        if (it == end())
            es_menor = true;
    }
    return es_menor;
}

Ruta::iterator Ruta::begin() {
    Ruta::iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin() const {
    Ruta::const_iterator it;
    it.p = puntos.cbegin();
    return it;
}

Ruta::iterator Ruta::end() {
    Ruta::iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end() const {
    Ruta::const_iterator it;
    it.p = puntos.cend();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p) {
    Ruta::iterator it;
    list<Punto>::iterator i;
    for (i=puntos.begin(); i!=puntos.end() && !((*i)==p);++i);
    it.p=i;
    return it;
}

istream & operator>>(istream &is, Ruta &R) {
    if (is.peek()) {
        Ruta rlocal;

        Punto punto;
        string aux;
        int num_puntos = 0;

        getline(is,aux,'\t');
        rlocal.SetCode(aux);

        getline(is,aux,'\t');
        num_puntos = atoi(aux.c_str());

        for(int i=0; i<num_puntos; ++i) {
            is >> punto;
            rlocal.Insertar(punto);
        }
        // Se queda colgando un salto de línea '\n'
        // y hay que quitarlo para que todo funcione
        int characters_to_ignore = 200;
        is.ignore(characters_to_ignore,'\n');

        R=rlocal;
    }

    return is;
}

ostream & operator<<(ostream &os, const Ruta &R) {
    os << R.GetCode() << '\t' << R.puntos.size() << '\t';

    Ruta::const_iterator it = R.begin();
    for (; it != R.end(); ++it) {
        os << *it << ' ';
    }
    return os;
}
