#include <ruta.h>

void Ruta::Insertar(const Punto &n) {
    puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n) {
   puntos.remove(n);
}

Ruta::Ruta() : puntos() {
    code = "";
}

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
    Ruta rlocal;

    Punto punto;
    Ruta ruta;
    string aux;
    int num_rutas = 0;

    getline(is,aux,'\t');
    ruta.SetCode(aux);

    getline(is,aux,'\t');
    num_rutas = atoi(aux.c_str());

    for(int i=0; i<num_rutas; ++i) {
        is >> punto;
        ruta.Insertar(punto);
    }

    R=rlocal;
    return is;
}

ostream & operator<<(ostream &os, Ruta &R) {
    os << R.GetCode() << '\t' << R.puntos.size() << '\t';

    Ruta::iterator it = R.begin();
    for (; it != R.end(); ++it) {
        os << *it << '\t';
    }
    return os;
}
