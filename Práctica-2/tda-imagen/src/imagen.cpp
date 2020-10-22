/**
  * @file imagen.cpp
  * @brief Implementación del TDA Imagen
  *
  */

#include <cassert>
#include "../include/imagen.h"

// -- Reserva de memoria estructurada --
void Imagen::reservar(){
	// Si no tenemos filas o columnas, podemos considerar la imagen como nula o vacía
	if (filas==0 || columnas==0)
		this->imagen = nullptr;
		// Si tenemos alguna fila y columna, declaramos la estructura
	else {
		// Las filas se almacenan en un vector de punteros a byte.
		// Éstos apuntarán a vectores de byte que se corresponden con las columnas
		this->imagen = new byte*[this->filas];

		// Hacemos que cada fila apunte a un vector de byte para que contenga
		// los valores de la imagen
		for (int i=0; i<this->filas; i++)
			this->imagen[i] = new byte[this->columnas];
	}
}

// -- Copia de los datos de una imagen dada a la actual --
void Imagen::copiar(const Imagen& imagen) {
	// Supone que la memoria está bien reservada
	assert(this->filas==imagen.num_filas() && this->columnas==imagen.num_columnas());

	for (int i=0; i<this->filas; i++)
		for (int j=0; j<this->columnas; i++)
			this->asigna_pixel(i,j,imagen.valor_pixel(i,j));
}

// -- Borrar la memoria --
void Imagen::borrar() {
	// Nos aseguramos que la imagen no es vacía
	if (this->imagen != nullptr) {
		// Primero debemos borrar el contenido de las columnas porque se encuentran
		// en el vector de filas al que apunta el puntero a puntero a byte "imagen"
		for (int i=0; i<this->filas; i++)
			delete [] this->imagen[i];

		// Ya podemos borrar el contenido del puntero a puntero a byte
		delete [] this->imagen;
		// Podemos añadir que las filas y las columnas pasarán a ser 0 aunque ya no importe
		this->filas = 0;
		this->columnas = 0;
	}
}

// -- Constructor por defecto y con parámetros --
Imagen::Imagen(int filas, int columnas) {
	// Nos aseguramos de que filas y columnas son mayores que 0
	assert(filas>=0 && columnas >=0);

	// Guardamos el valor de filas y columnas en nuestros atributos
	this->filas = filas;
	this->columnas = columnas;

	// Reservamos la memoria con la forma de una matriz dinámica
	this->reservar();
}

// -- Constructor de copia --
// En la lista de inicialización llama al constructor para preparar los atributos
// y asignar la memoria dinámica correspondiente y no repetir código
Imagen::Imagen(const Imagen& imagen) : Imagen(imagen.num_filas(),imagen.num_columnas()) {
	this->copiar(imagen);
}

// -- Destructor --
// Libera la memoria usada en el puntero a puntero imagen
Imagen::~Imagen() {
	this->borrar();
}

// -- Operador de asignación --
Imagen& Imagen::operator=(const Imagen& imagen) {
	// Si "imagen" es distinta al objeto actual, entonces...
	if (this != &imagen) {
		// Tenemos que borrar el contenido para liberar la memoria y no desperdiciarla
		this->borrar();
		// Fijamos el valor de filas y columnas a los nuevos valores
		this->filas = imagen.num_filas();
		this->columnas = imagen.num_columnas();
		// Reservamos de nuevo la memoria necesaria de forma estructurada
		this->reservar();
		// Ya podemos proceder a copiar los valores de "imagen" en el objeto actual
		this->copiar(imagen);
	}
		// En cualquier caso, devolvemos una referencia del objeto actual ya que:
		// si copiamos, es lo que nos interesa que devolver
		// y sino, de todas formas tenemos que devolverlo
		return *this;
}

// -- Dar un valor a un píxel --
void Imagen::asigna_pixel(int fila, int columna, byte valor) {
	// Los valores de entrada deben estar en unos intervalos concretos
	assert(fila>=0 && columna>=0 && valor>=0 && valor<=255);

	// Gracias a la estructura elegida para representar la matriz, podemos
	// acceder al elemento deseado aplicando un operador corchete sobre el
	// resultado de otro operador corchete. Así, se parece a la matriz estática
	this->imagen[fila][columna] = valor;
}

byte Imagen::valor_pixel(int fila, int columna) const {
	// Los valores de entrada deben estar en unos intervalos concretos
	assert(fila>=0 && fila<=this->filas && columna>=0 && columna<=this->columnas);

	// Accedemos al valor con los parámetros introducidos
	return this->imagen[fila][columna];
}
