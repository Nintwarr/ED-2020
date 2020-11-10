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
    const string RUTA_BASE = "imagenespgmppm/";
    string cameraman = RUTA_BASE + "/cameraman.pgm";
    string salida1 = RUTA_BASE + "/salidaMain1.pgm";
    string salida2 = RUTA_BASE + "/salidaMain2.pgm";
    string salida3 = RUTA_BASE + "/salidaMain3.pgm";
    string salida4 = RUTA_BASE + "/salidaMain4.pgm";

    int filas =    255;
    int columnas = 255;
    Imagen imagen1;
    Imagen imagen2(filas,columnas);
    Imagen imagen3(cameraman.c_str());
    Imagen imagen4(imagen3);

    for (int i=0; i<filas; ++i)
        for(int j=0;j<columnas; ++j)
            imagen2.asigna_pixel(i,j,255);

    imagen1 = imagen2;

    imagen1.escribir_imagen_PGM(salida1.c_str());
    imagen2.escribir_imagen_PGM(salida2.c_str());
    imagen3.escribir_imagen_PGM(salida3.c_str());
    imagen4.escribir_imagen_PGM(salida4.c_str());

}
