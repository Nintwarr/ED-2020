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

byte umbralizado_automatico(Imagen imagen, string entrada, string salida) {
    byte umbral = 0;

    if (imagen.umbralizado_automatico(entrada.c_str(),salida.c_str(),umbral)) {
        cout << "Imagen '" << entrada << "' umbralizada automáticamente con éxito "
             << "en '" << salida << "'." << endl;
        cout << "Se ha utilizado un umbral de: " << int(umbral) << endl;
    } else {
        cout << "No se ha podido umbralizar la imagen";
    }

    return umbral;
}

int main() {
    const string RUTA_BASE = "imagenespgmppm/";
    string salida          = RUTA_BASE + "salidaMain.pgm";
    string cameraman       = RUTA_BASE + "cameraman.pgm";
    string saturno         = RUTA_BASE + "saturno.pgm";
    string vacas           = RUTA_BASE + "vacas.pgm";
    string celulas         = RUTA_BASE + "celulas.pgm";
    string castillo        = RUTA_BASE + "castillo.pgm";
    string board           = RUTA_BASE + "board.pgm";
    string llave           = RUTA_BASE + "llave.pgm";
    string llaves          = RUTA_BASE + "llaves.pgm";
    string niveles         = RUTA_BASE + "niveles.pgm";
    Imagen imagen;

    umbralizado_automatico(imagen,niveles,salida);
}
