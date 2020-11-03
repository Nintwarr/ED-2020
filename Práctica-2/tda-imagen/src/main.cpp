#include <imagen.h>
#include <imagenES.h>
#include <iostream>

using namespace std;

int main() {
    int filas = 10;
    int columnas = 10;

    Imagen imagen(filas,columnas);

    for (int i=0; i<filas; ++i) {
        for (int j=0; j<columnas; ++j) {
            imagen.asigna_pixel(i,j,255);
            cout << imagen.valor_pixel(i,j);
        }
        cout << endl;
    }
}
