#ifndef _ALMACEN_RUTAS_H_
#define _ALMACEN_RUTAS_H

#include <iostream>
#include <map>
#include "ruta.h"

class Almacen_Rutas{
    private:
        map<string,Ruta> ruta; //Codigo de ruta y ruta

    public:
        Almacen_Rutas(): ruta() {};
        void Insertar (const Ruta & R);
        void Borrar (const Ruta &R);
        Ruta GetRuta (const string & a);

        class iterator {
            private:
                map <string, Ruta>::iterator p;
            public:


            /**
             * @brief Operador de acceso a memoria
             * @return Devuelve una referencia a la ruta que esta en la posición del iterador
             */
                Ruta & operator*(){return (*p).second;}

            /**
             * @brief Operador de incremento
             * @return Devuelve un iterador de la clase ruta incrementado en una unidad (Siguiente ruta)
             */
                iterator & operator++(){++p; return *this;}

            /**
             * @brief Operador de decremento
             * @return Devuelve un iterador de la clase ruta decrementado en una unidad (Ruta anterior)
             */
                iterator & operator--(){--p; return *this;}

            /**
             * @brief Operador igualdad
             * @param i Una referencia constante del iterador que queremos comparar
             * @return Devuelve un booleano, true en caso de que los iteradores sean iguales, false en el contrario
             */
                bool operator==(const iterator &i){return p == i.p;}

                /**
                 * @brief Operador desigualdad
                 * @param i Una referencia constante del iterador que queremos comparar
                 * @return Devuelve un booleano, false en caso de que los iteradores sean iguales, true en el contrario
                 */
                bool operator!=(const iterator &i){return p != i.p;}

                friend class Almacen_Rutas;
                friend class const_iterator;

        };

        class const_iterator{
            private:
                map<string,Ruta>:: const_iterator p;

            public:

        /**
         * @brief Operador de acceso a memoria
         * @return Devuelve una referencia constante a la ruta que esta en la posición del iterador
         */
            const Ruta & operator*(){return (*p).second;}

        /**
         * @brief Operador de incremento
         * @return Devuelve un iterador constante de la clase país incrementado en una unidad
         */
            const_iterator & operator++(){++p; return *this;}

        /**
         * @brief Operador de decremento
         * @return Devuelve un iterador constante de la clase país decrementado en una unidad
         */
            const_iterator & operator--(){--p; return *this;}

        /**
         * @brief Operador igualdad
         * @param i Una referencia constante del iterador que queremos comparar
         * @return Devuelve un booleano, true en caso de que los iteradores sean iguales, false en el contrario
         */
            bool operator==(const const_iterator &i){return p == i.p;}

        /**
         * @brief Operador desigualdad
         * @param i Una referencia constante del iterador que queremos comparar
         * @return Devuelve un booleano, false en caso de que los iteradores sean iguales, true en el contrario
         */
            bool operator!=(const const_iterator &i){return p != i.p;}

            friend class Almacen_Rutas;
        };

        iterator begin();
        const_iterator begin () const;
        iterator end();
        const_iterator end () const;

        friend istream & operator >> (istream & is, Almacen_Rutas & AR);
        friend ostream & operator << (ostream & os, const Almacen_Rutas &R);
};


#endif
