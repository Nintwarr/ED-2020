/**
  * @author Darío Megías Guerrero y María Sánchez Marcos
  * @file rutasaereas.cpp
  * @brief Fichero de programa principal
  */

#include <imagen.h>
#include <paises.h>
#include <almacenrutas.h>
#include <fstream>
#include <cmath>

int latitudToPixel (const double latitud, const int nf){
    int fila = ((nf/180.0)*(90-latitud));
    return fila;
}

int longitudToPixel(const double longitud, const int nc){
    int columna = ((nc/360.0)*(180+longitud));
    return columna;
}

Imagen Rota(const Imagen & Io,double angulo){
    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;
    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=Io.num_filas()-1;
    rcorners[3]=Io.num_filas()-1;
    ccorners[1]=Io.num_cols()-1;
    ccorners[3]=Io.num_cols()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;
    for(int count=0;count<4;count++)
    {
	    inter=rcorners[count]*coseno+ccorners[count]*seno;

	    if(inter<new_row_min)
		    new_row_min=inter;
	    if(inter>new_row_max)
		    new_row_max=inter;
	    inter1=-rcorners[count]*seno+ccorners[count]*coseno;

	    if(inter1<new_col_min)
		    new_col_min=inter1;
	    if(inter1>new_col_max)
		    new_col_max=inter1;
   }

    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);

    Imagen Iout(newimgrows,newimgcols);
    for(int rows=0;rows<newimgrows;rows++) {
        for(int cols=0;cols<newimgcols;cols++) {
        float oldrowcos=((float)rows+new_row_min)*cos(-rads);
        float oldrowsin=((float)rows+new_row_min)*sin(-rads);
        float oldcolcos=((float)cols+new_col_min)*cos(-rads);
        float oldcolsin=((float)cols+new_col_min)*sin(-rads);
        float old_row=oldrowcos+oldcolsin;
        float old_col=-oldrowsin+oldcolcos;
        old_row=ceil((double)old_row);
        old_col=ceil((double)old_col);
        if((old_row>=0)&&(old_row<Io.num_filas())&&
            (old_col>=0)&&(old_col<Io.num_cols()))
        {
            Iout(rows,cols)=Io(old_row,old_col);

        }
        else
            Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
        }
    }
    return Iout;
}

void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
    int fila,col;

    if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){
        if (c1!=c2){
            double a,b;
            a= double(f2-f1)/double(c2-c1);
            b= f1-a*c1;
            col = (int)(c1+c2)/2;
            fila = (int)rint(a*col+b);
        }
        else{
            col = c1;
            fila = (f1+f2)/2;
        }

        double angulo = atan2((f2-f1),(c2-c1));
        Imagen Irota=Rota(avion,angulo);

        I.PutImagen(fila,col,Irota);

        angulo = atan2((f2-fila),(c2-col));
        Irota=Rota(avion,angulo);

        I.PutImagen(f2,c2,Irota);
        angulo = atan2((fila-f1),(col-c1));
        Irota=Rota(avion,angulo);

        I.PutImagen(f1,c1,Irota);
    }
}

int main(int argc, char * argv[]){
    if (argc!=7){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.-Fichero con la informacion de los paises"<<endl;
        cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
        cout<<"3.-Directorio con las banderas"<<endl;
        cout<<"4.-Fichero con el almacen de rutas"<<endl;
        cout<<"5.- Nombre de la imagen con el avion"<<endl;
        cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;

        return 0;
    }

    Paises Pses;
    ifstream f (argv[1]);
    f>>Pses;
    //cout<<Pses;

    Imagen I;
    I.LeerImagen(argv[2]);

    //Leemos los aviones
    Imagen avion;
    avion.LeerImagen(argv[5],argv[6]);

    Almacen_Rutas Ar;
    f.close();
    f.open (argv[4]);
    f>>Ar;
    cout<<"Las rutas: "<<endl<<Ar;
    cout<<"Dime el codigo de una ruta"<<endl;
    string a;
    cin>>a;
    Ruta R=Ar.GetRuta(a);
    cout << "Ruta:";

    Ruta::iterator it_ruta;
    for (it_ruta = R.begin(); it_ruta != R.end(); ++it_ruta) {
        cout << " " << (*Pses.find((*it_ruta))).GetPais();
    }

    cout << endl;
    /*
      1. Si tiene más de o exactamente 2 puntos:
      2. Iterar sobre la ruta R.
        2.1 Escogemos el primero en una variable auxiliar "punto_primero" (no tiene por qué ser este nombre).
        2.2 Para cada uno de los puntos restantes:
            2.2.1 Escogemos el segundo en otra variable auxiliar "punto_segundo".
            2.2.2 Buscamos a qué país corresponde "punto_primero" y "punto_segundo" gracias a "Pses"
                  que resulta en las variables "pais_primero" y "pais_segundo".
            2.2.3 Leemos las banderas de "pais_primero"y "pais_segundo" quedando éstas en
                  "bandera_primera" y "bandera_segunda".
            2.2.4 Calcular a qué posicición de la imagen del mapa corresponden "punto_primero"
                  y "punto_segundo" quedando en "posicion_primera" y "posicion_segunda".
            2.2.5 Llamar a Pintar(...) para que se pinten de forma correcta los aviones entre
                  "posicion_primera" y "posicion_segunda".
            2.2.6 Pegar la bandera de "pais_primero" en "posicion_primera" y la de "pais_segundo"
                  en "posicion_segunda".
            2.2.7 Actualizar "punto_primero" con "punto_segundo" (punto_primero = punto_segundo;)

        2.3 Escribir la imagen del mapa con todo ya pegado en disco.
    */

   if (R.GetNumPuntos() >= 2) {
       // Preparamos el iterador para iterar sobre las rutas
        Ruta::iterator it;
        it = R.begin();

        // Vamos capturando el primer punto
        Punto punto_primero = *it;
        ++it;
        // Declaración de variables necesarias para el bucle
        Punto punto_segundo;

        Pais pais_primero;
        Pais pais_segundo;

        Paises::iterator pais_primero_encontrado;
        Paises::iterator pais_segundo_encontrado;

        string rutas_banderas = argv[3];
        Imagen bandera_primera;
        Imagen bandera_segunda;

        int filas_p1 = 0;
        int columnas_p1 = 0;
        int filas_p2 = 0;
        int columnas_p2 = 0;

        // Ahora sí, iteramos sobre las rutas
        for(; it != R.end(); ++it) {
            // Conseguimos el segundo punto en la pareja de puntos
            punto_segundo = *it;

            // Buscamos a qué países corresponde cada punto
            pais_primero_encontrado = Pses.find(punto_primero);
            pais_segundo_encontrado = Pses.find(punto_segundo);

            pais_primero = *pais_primero_encontrado;
            pais_segundo = *pais_segundo_encontrado;

            // Leemos las banderas de ambos países
            bandera_primera.LeerImagen((rutas_banderas + pais_primero.GetBandera()).c_str());
            bandera_segunda.LeerImagen((rutas_banderas + pais_segundo.GetBandera()).c_str());
            // Calculamos a qué posición de la imagen corresponden los países obtenidos
            filas_p1 = latitudToPixel(punto_primero.getLatitud(),I.num_filas());
            columnas_p1 = longitudToPixel(punto_primero.getLongitud(),I.num_cols());

            filas_p2 = latitudToPixel(punto_segundo.getLatitud(),I.num_filas());
            columnas_p2 = longitudToPixel(punto_segundo.getLongitud(),I.num_cols());

            // Pintamos los aviones en el lugar de salida, de destino y el punto medio
            Pintar (filas_p1, filas_p2, columnas_p1, columnas_p2, I, avion, 85, 70);

            // Pegamos las banderas de los correspondientes países en sus
            // correspondintes posiciones
            I.PutImagen(filas_p1,columnas_p1,bandera_primera,BLENDING);
            I.PutImagen(filas_p2,columnas_p2,bandera_segunda,BLENDING);

            // Actualizamos el segundo punto para que se escojan bien las parejas
            punto_primero = punto_segundo;
        }

        // Escribimos el resultado en el directorio "resultados"
        I.EscribirImagen("datos/resultados/resultado.ppm");
   }
}
