/**
  * @file ejer4.cpp
  * @brief Implementación del ejercicio 4. Creación de un icono a partir de una imagen
  *
  */

#include "imagenES.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

//-- Funcion auxiliar para calcular la media de valores en una submatriz
/** @param matriz que vamos a usar, comienzo de las filas, comienzo de las columnas, final de las filas, final de las columnas y numero de columnas
*/
int calcularMedia(unsigned char* imagen,int inicio_f,
                  int inicio_c, int fin_f, int fin_c, int num_columnas){

    // Inicializamos el resultado a 0
    int solucion = 0;

    //Sumamos los valores de toda la matriz y los almacenamos
    for(int i = inicio_f; i < fin_f;i++){
        for(int j = inicio_c; j < fin_c; j++){
            solucion+= (int)imagen[i*num_columnas + j];
        }
    }

    //Lo dividimos entre el número de elementos para hacer la sol
    solucion = solucion / ((fin_f-inicio_f)*(fin_c-inicio_c));

    return solucion;
}


//-- Funcion que crea una imagen que es un numero entero de veces más pequeña que la original dada
/** @param fichero de origen, fichero de destino, numero de filas de la nueva imagen, numero de columnas de la ultima imgen
*/
void crearIcono(char* origen, char* destino, const int nf, const int nc){

    // Variables para ayudar a los cálculos de la funcion
    int factor_nf, factor_nc, f_original, c_original;

    // Matriz original y matriz solucion
    unsigned char * imagen;
    unsigned char * solucion;

    // Leemos la imagen original y la cargamos en imagen
    imagen = LeerImagenPGM(origen,f_original,c_original);

    // Si no puede leerse, lanza mensaje de error y sale del programa
    if (!imagen){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }

    // Reservamos memoria para la matriz solucion
    solucion = new unsigned char [nf*nc];

    // Calculamos el factor de reduccion que va a sufrir la imagen
    // Redondearemos a un entero ya que es el tipo con el que estamos trabajando
    factor_nf = f_original/nf;
    factor_nc = c_original/nc;

    // Si el factor sale que redondeado es 0, nos salimos porque nos estan pidiendo ampliar la imagen, no hacer un icono
    if (factor_nc == 0 || factor_nf == 0){
        cerr << "Error: Estas pidiendo aumentar la imagen, no hacer un icono." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }
    // Para obtener un resultado optimo, pedimos que el nuevo tamaño de la imagen sea un divisor exacto de la imagen original
    // Así tendremos la imagen a escala
    if(f_original%nf != 0 || c_original%nc != 0){
        cerr << "Error: El valor de las filas y columnas introducidas debe ser divisor exacto de las filas y columnas originales" << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }


    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    int media = 0;


    // Calculamos la media de los pixeles
    // El número de píxeles utilizado se decide según el factor calculado anteriormente
    // Recorremos la matriz orginal y guardamos la media en la matriz solucion
    while (i < f_original ){
        b = 0;
        j = 0;
        while (j < c_original){

            media = calcularMedia(imagen,i,j,i+factor_nf, j+factor_nc,c_original);

            solucion[a*nc + b] = media;

            j+=factor_nc;
            b++;
        }

        a++;

        i+=factor_nf;

    }

    // Guardamos la matriz solucion en el fichero de destino
    if (EscribirImagenPGM (destino, solucion, nf, nc))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (2);
    }

    // Liberaos la memoria usada una vez ya lo hemos guardado
    delete [] solucion;

}

// Comprobacion de que funciona

int main (int argc, char *argv[]){
    if (argc != 5){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: " << argv[0] <<  " <FichImagenOriginal> <FichImagenDestino> <Nuevo tamaño de filas> <Nuevo tamaño de columnas>\n";
        exit (1);
    }

    crearIcono(argv[1],argv[2], atoi(argv[3]), atoi(argv[4]));
}
