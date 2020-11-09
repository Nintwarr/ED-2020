#include "imagenES.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int calcularMedia(unsigned char* imagen,int inicio_f, 
                  int inicio_c, int fin_f, int fin_c, int num_columnas){

    int solucion = 0;

    for(int i = inicio_f; i < fin_f;i++){
        for(int j = inicio_c; j < fin_c; j++){
            solucion+= (int)imagen[i*num_columnas + j];
        }
    }
    solucion = solucion / ((fin_f-inicio_f)*(fin_c-inicio_c));

    return solucion;
} 

void crearIcono(char* origen, char* destino, const int nf, const int nc){

    int factor_nf, factor_nc, f_original, c_original;
    unsigned char * imagen;
    unsigned char * solucion;

    imagen = LeerImagenPGM(origen,f_original,c_original);

    if (!imagen){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }
    solucion = new unsigned char [nf*nc];
    
    factor_nf = f_original/nf;
    factor_nc = c_original/nc;

    if (factor_nc == 0 || factor_nf == 0){
        cerr << "Error: Estas pidiendo aumentar la imagen, no hacer un icono." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (1);
    }

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

    if (EscribirImagenPGM (destino, solucion, nf, nc))
        cout  << "La imagen se guardo en " << destino << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit (2);
    }

    delete [] solucion; 

}

int main (int argc, char *argv[]){
    if (argc != 5){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: " << argv[0] <<  " <FichImagenOriginal> <FichImagenDestino> <Nuevo tamaño de filas> <Nuevo tamaño de columnas>\n";
        exit (1);
    }

    crearIcono(argv[1],argv[2], atoi(argv[3]), atoi(argv[4]));
}
