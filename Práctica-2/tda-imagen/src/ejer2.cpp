#include <imagenES.h>
#include <imagen.h>
#include <iostream>
#include <string>

/**
* @file ejer2.cpp
* @brief Implementación del ejercicio 2. Umbralización automática
* @author Darío Megías Guerrero
*/

/**
* @brief Calcula la media de los niveles de gris en una imagen
* @param imagen_entrada Imagen de la que queremos calcular la media
* @return Un valor decimal que representa la media simple de grises
*         que tiene la imagen
*/
double calcular_media_gris(Imagen *imagen_entrada) {
	double media = 0;
	int f = imagen_entrada->num_filas();
	int c = imagen_entrada->num_columnas();

	for (int i=0; i<f; ++i)
		for (int j=0; j<c; ++j)
			media += imagen_entrada->valor_pixel(i,j);

	media /= f*c;

	return media;
}

/**
* @brief Calcula las medias de grises en dos extremos en función de
*        un umbral de entrada
* @param imagen_entrada Imagen sobre la que trabajar
* @param umbral_entrada Imagen que determina el valor de gris
*                       a partir del cual separamos el cálculo
*                       de las medias
* @param [out] umbral_primero Parámetro de salida en el que quedará la media
*                       de tonos de gris por \b debajo del umbral
* @param [out] umbral_segundo Parámetro de salida en el que quedará la media
*                       de tonos de gris por \b encima del umbral
*/
void separar_segun_umbral(Imagen *imagen_entrada, const double umbral_entrada,
                          double &umbral_primero, double &umbral_segundo) {
	int tam_primero = 0, tam_segundo = 0;
	byte pixel = 0;
	umbral_primero = umbral_segundo = 0;

	// Recorremos la imagen y, conforme visitamos su píxeles,
	// podemos saber si estos pertenecen a un extremo del
	// umbral u otro. Gracias a esto ya podemos encargarnos
	// de calcular la media del tono de gris para cada
	// extremo y asignársela al parámetro de salida.
	// Así, no tenemos que crear nuevas imágenes que
	// no sabemos qué dimensiones tendrán. Cosa que,
	// por otro lado, es totalmente irrelevante
	// para el cálculo.
	for (int i=0; i<imagen_entrada->num_filas(); ++i)
		for (int j=0; j<imagen_entrada->num_columnas(); ++j) {
			pixel = imagen_entrada->valor_pixel(i,j);
			if (pixel <= umbral_entrada) {
				umbral_primero += pixel;
				++tam_primero;
			} else {
				umbral_segundo += pixel;
				++tam_segundo;
			}
		}

	umbral_primero /= tam_primero;
	umbral_segundo /= tam_segundo;
}

/**
* @brief Umbraliza una imagen según un umbral dado
* @param imagen_entrada Imagen a umbralizar
* @param umbral Umbral a utilizar para la operación
*/
void umbralizar_basico(Imagen *imagen_entrada, const byte umbral) {
	for (int i=0; i<imagen_entrada->num_filas(); ++i)
		for (int j=0; j<imagen_entrada->num_columnas(); ++j)
			if (imagen_entrada->valor_pixel(i,j) > umbral)
				imagen_entrada->asigna_pixel(i,j,255);
}

/**
* @brief Genera una imagen a partir de una imagen de entrada tal que los píxeles
*        con un valor menor que un umbral calculado de forma automática se dejan
*        tal cual. Y todos aquellos que estén por encima de ese umbral, se pasan
*        a blanco.
* @param fichero_entrada Nombre del fichero a leer
* @param fichero_salida Nombre del fichero que se va a escribir umbralizado
* @param [out] umbral Parámetro de salida que informa del umbral que se ha calculado de
                forma automática.
* @return Si ha tenido éxito la umbralización o no
*/
bool umbralizado_automatico(const char *fichero_entrada, const char *fichero_salida, byte &umbral) {
	bool exito = false;
	bool primera_vez = true;
    Imagen *imagen = new Imagen();
	double umbral_actual = 0, umbral_siguiente = 0;
	double umbral_primero = 0, umbral_segundo = 0;
	double epsilon = 0.00001;

	// Si podemos cargar la imagen seguimos
	if (imagen->cargar_imagen_PGM(fichero_entrada)) {
		exito = true;

		// La primera vez que entramos al cálculo de la media de
		// umbrales, debemos usar como referencia la media de
		// la imagen leída de fichero. Las siguientes veces tenemos
		// que tomar como referencia el cálculo conseguido en la iteración anterior
		do {
			if (primera_vez) {
				umbral_actual = calcular_media_gris(imagen);
				primera_vez = false;
			}
			else {
				umbral_actual = umbral_siguiente;
			}

			// Se calculan las medias de grises sobre la imagen cargada
			// separando la selección de píxeles en función del umbral
			// o media de tonos de gris que ya hemos calculado
			separar_segun_umbral(imagen,umbral_actual,umbral_primero,umbral_segundo);
			// Con esas dos medias, se vuelve a hacer una media
			umbral_siguiente = (umbral_primero + umbral_segundo)/2;
			// Ciclamos mientras el valor absoluto de la diferencia
			// entre el umbral calculado tras la separación y el de la
			// iteración anterior sea mayor o igual que un valor
			// muy pequeño. Es decir, buscamos que la diferencia
			// entre la media de una iteración y otra, sea muy
			// pequeña
		} while (abs(umbral_siguiente-umbral_actual) >= epsilon);

		// Como en la imagen se guardan bytes, eso es lo que el usuario
		// espera que use como umbral. Así que redondeamos el umbral,
		// lo convertimos a byte y lo asignamos al parámetro de salida
		umbral = byte(round(umbral_siguiente));

		// Hacemos efectiva la umbralización con el umbral calculado
		umbralizar_basico(imagen,umbral);

		// Si no podemos escribir la imagen, entendemos que hemos
		// fracasado
		exito = imagen->escribir_imagen_PGM(fichero_salida);
	}

    delete imagen;

	return exito;
}

int main(int argc, char *argv[]) {
    const string RUTA_BASE = "imagenespgmppm/";
    const string RUTA_SALIDA = RUTA_BASE + "umbralizada.pgm";

    if (argc != 2) {
        cerr << "Insuficientes argumentos" << endl;
        cerr << "Uso: " << argv[0] << " <nombre del fichero a umbralizar>" << endl;
        cerr << "El fichero quedará en: " << RUTA_SALIDA << endl;

        exit(1);
    }

    byte umbral = 0;
    string entrada = argv[1];

    if (umbralizado_automatico(entrada.c_str(),RUTA_SALIDA.c_str(),umbral)) {
        cout << "Imagen '" << entrada << "' umbralizada automáticamente con éxito "
             << "en '" << RUTA_SALIDA << "'." << endl;
        cout << "Se ha utilizado un umbral de: " << int(umbral) << endl;
    } else {
        cout << "No se ha podido umbralizar la imagen";
    }

    exit(0);
}
