#include <imagen.h>
#include <imagenES.h>
#include <iostream>

using namespace std;

Imagen crear_imagen_blanca(int filas, int columnas) {
    Imagen imagen(filas,columnas);

    for (int i=0; i<filas; ++i)
        for (int j=0; j<columnas; ++j)
            imagen.asigna_pixel(i,j,255);

    return imagen;
}

Imagen crear_imagen_rayas(int filas, int columnas) {
    Imagen imagen(filas,columnas);
    unsigned char valor = filas*columnas;

    for (int i=0; i<filas; ++i)
        for (int j=0; j<columnas; ++j)
            imagen.asigna_pixel(i,j,(valor--%255));

    return imagen;
}

int main() {
    Imagen imagen("imagenespgmppm/cameraman.pgm");

    imagen.cargar_imagen_PGM("imagenespgmppm/celulasese.pgm");

    imagen.escribir_imagen_PGM("imagenespgmppm/salidaMain.pgm");
}
