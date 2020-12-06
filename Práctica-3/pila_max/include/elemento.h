#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

#include <iostream>

struct elemento {
    int ele;
    int maximo;

};

std::ostream& operator<<(std::ostream &salida, const elemento & elem);

#endif
