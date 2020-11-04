/**
* @file imagen.h
* @author Darío Megías Guerrero & María Sánchez Marcos
* @date 22 Oct 2020
* @copyright 2020 Darío Megías Guerrero & María Sanchez Marcos
* @brief Fichero de cabecera asociado a la biblioteca libimg.a.
* Implementacion del TDA imagen (imagen digital en niveles de gris).
*/

#ifndef __IMAGEN__H__
#define __IMAGEN__H__

#include <iostream>
#include <imagen.h>

using namespace std;

/**
* @brief T.D.A. Imagen
*
* Una instancia @e c del tipo de dato abstracto @c Imagen es un objeto que
* representa una imagen como una sucesión de píxeles dispuesta en filas
* y columnas. Los píxeles representan valores de luminosidad de la pantalla.
* Además almacena el número de filas de la imagen y su número de columnas.
*
* @author Darío Megías Guerrero y María Sánchez Marcos
* @date Octubre 2017
*/

typedef unsigned char byte;

class Imagen {

private:
	/**
	* @page repImagen Rep del TDA Imagen
	*
	* @section invImagen Invariante de la representación
	*
	* El invariante es \e rep.filas>=0, rep.columnas>=0
	*
	* @section faImagen Función de abstracción
	*
	* Un objeto válido @e rep del TDA Racional representa a una imagen cuyos
	* datos están en rep.imagen (una matriz dinámica de bytes) con tamaño
	* rep.filas * rep.columnas. Así, queda la terna
	*
	* ({rep.imagen[0][0],rep.imagen[0][1],...,rep.imagen[0][rep.columnas],...,rep.imagen[rep.filas][rep.columnas]},
	* rep.filas,
	* rep.columnas)
	*/

	unsigned int filas;     /** Es el número de filas de la imagen */
	unsigned int columnas;  /** Es el número de columnas de la imagen */
	byte **imagen;          /** Apunta a un vector de punteros a @e byte */

	// -- Métodos auxiliares -- //

	/**
	* Se encarga de reservar la memoria de forma que "imagen" apunta a un
	* vector de punteros a byte y cada posicón de ese vector apunta a un
	* vector de bytes.
	*/
	void reservar();
	/**
	* Se encarga de copiar los píxeles de "imagen" a "this".
	* Asume que las filas y las columnas coinciden
	*/

	void copiar(const Imagen& imagen);
	/**
	* Borra la estructura de memoria que reservamos con "reservar()"
	*/

	void borrar();
	/**
	* Utiliza el módulo @c imagenES para leer una imagen y copiar los datos
	* a la estructura interna
	*/

	void leerFichero(const char *nombre);

public:
	// -- Constructores -- //

	/**
	* @brief Constructor por defecto y por parámetros
	* @param [in] filas Indica el número de filas que tendrá la imagen
	* @param [in] columnas Indica el número de columnas que tendrá la image
	* @details Crea una imagen en memoria con "filas" filas y "cols" columnas.
	*          Reserva memoria para alojar la imagen de "filas" x "cols" pixeles.
	*          El objeto resultante no está inicializado y tendrá valores basura.
	* @note Este constructor sirve como constructor por defecto si se invoca vacío
	*/
	Imagen(int filas = 0, int columnas = 0);

	/**
	* @brief Constructor de copia
	* @param [in] imagen Es un objeto del tipo Imagen que queremos copiar en @e this
	*/
	Imagen(const Imagen& imagen);

	/**
	*
	*
	*/
	Imagen(const char *nombre_archivo);

	/**
	* @brief Destructor
	* @details Desaloja la memoria que se reserva para la matriz dinámica en la
	*          que guardamos los datos de la imagen llamando a "borrar()"
	*/
	~Imagen();

	/**
	* @brief Operador de asignación
	* @param [in] imagen Es un objeto del tipo Imagen que queremos asignar a @e this
	* @return Devuelve la referencia de una copia de \e imagen
	*/
	Imagen& operator=(const Imagen& imagen);

	/**
	* @brief Getter del atributo @c filas
	* @return Devuelve el valor del atributo @c filas
	*/
	int num_filas() const {return filas;};

	/**
	* @brief Getter del atributo @c columnas
	* @return Devuelve el valor del atributo @c columnas
	*/
	int num_columnas() const {return columnas;};

	/**
	* @brief Asigna el valor @e valor al pixel (@e fila, @e columna) de la imagen
	* @param [in] fila Coordenada @e x del píxel en el que insertar @e valor
	* @param [in] columna Coordenada @e y del píxel en el que insertar @e valor
	* @param [in] valor Valor de luminosidad a escribir
	* @pre 0 <= @e fila <= imagen.num_filas()
	* @pre 0 <= @e columna <= imagen.num_columnas()
	* @pre 0 <= @e valor <= 255
	* @post imagen(@e fila, @e columna) = @valor
	* @note Se asigna un único valor en una única coordenada
	*/
	void asigna_pixel(int fila, int columna, byte valor);

	/**
	* @brief Consultar el valor de la casilla (@e fila, @e columna) de la imagen
	* @param [in] fila Coordenada @e x del píxel a consultar
	* @param [in] columna Coordenada @e y del píxel a consultar
	* @pre 0 <= @e fila <= imagen.num_filas()
	* @pre 0 <= @e columna <= imagen.num_columnas()
	* @return Devuelve un valor de tipo @e byte que se encuentra en la posición
	*         imagen(@e fila, @e columna)
	*/
	byte valor_pixel(int fila, int columna) const;

	/**
	* @brief Lee un fichero en formato @e .pgm y lo copia en la estructura interna
	* @details Utliza el módulo @e imagenES para cargar la imagen
	* @param nombre Archivo a leer
	* @pre Las filas y las columnas del archivo deben coincidir con las filas
	*	   y las columnas de la instancia
	* @post En la estructura interna de la instancia se habrán copiado
	*       los datos del fichero
	* @return Valor booleano que indica si se ha leído el archivo correctamente
	*/
	bool cargar_imagen_PGM(const char *nombre);

	/**
	* @brief Vuelca los datos de la instancia en un arhcivo con formato @e .pgm
	* @details Utiliza el módulo @e imagenES para escribir la imagen
	* @param nombre Nombre del archivo en le que se van a escribir los datos.
	*               Puede existir o no.
	* @pre Los datos de la instancia se suponen inicailizados
	* @post En el nombre o ruta indicada se habrá creado una imagen con
	*       extensión @e .pgm conteniendo los datos actuales de la instancia
	* @return Si la escritura ha tenido éxito o no
	*/
	bool escribir_imagen_PGM(const char *nombre);
};

#endif
