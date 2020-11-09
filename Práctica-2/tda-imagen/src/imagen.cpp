/**
  * @file imagen.cpp
  * @brief Implementación del TDA Imagen
  *
  */

#include <cassert>
#include <imagen.h>

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
		for (int i=0; i<this->filas; ++i)
			this->imagen[i] = new byte[this->columnas];
	}
}

// -- Copia de los datos de una imagen dada a la actual --
void Imagen::copiar(const Imagen& imagen) {
	// Supone que la memoria está bien reservada
	assert(this->filas==imagen.num_filas() && this->columnas==imagen.num_columnas());

	for (int i=0; i<this->filas; ++i)
		for (int j=0; j<this->columnas; ++j)
			this->asigna_pixel(i,j,imagen.valor_pixel(i,j));
}

// -- Borrar la memoria --
void Imagen::borrar() {
	// Nos aseguramos que la imagen no es vacía
	if (this->imagen != nullptr) {
		// Primero debemos borrar el contenido de las columnas porque se encuentran
		// en el vector de filas al que apunta el puntero a puntero a byte "imagen"
		for (int i=0; i<this->filas; ++i)
			delete [] this->imagen[i];

		// Ya podemos borrar el contenido del puntero a puntero a byte
		delete [] this->imagen;
		// Podemos añadir que las filas y las columnas pasarán a ser 0 aunque ya no importe
		this->filas = 0;
		this->columnas = 0;
	}
}

// -- Lee un fichero con formato pgm --
bool Imagen::leer_fichero_PGM(const char *nombre) {
	// Variable que controla el éxito de la ejecución
	bool exito = false;
	// Variables auxiliares de filas y columnas
	int f = 0,c = 0;
	// Vector de unsigned char o 'bytes' que nos devuelve la función
	byte *datos = LeerImagenPGM(nombre,f,c);

	if (f!=0 && c!=0) {
		// Si miramos la implementaciónde LeerImagenPGM, si devuelve 0 es que
		// no se ha podido leer el archivo
		if (datos != 0) {
			// Indicamos que ha habido éxito
			exito = true;

			// Si la estructura interna no coincide con la del
			// fichero, tenemos que adaptarla
			if (f!=this->filas || c!=this->columnas) {
			this->borrar();

			this->filas = f;
			this->columnas = c;

			this->reservar();
			}

			// Copiamos los datos leídos en nuestra instancia
			for (int i=0; i<this->filas; ++i)
				for (int j=0; j<this->columnas; ++j)
					asigna_pixel(i,j,datos[i*this->columnas+j]);
			// ------------------------------------------- //

			// Liberamos la memoria de datos
			delete [] datos;
		}
	} else {
			cerr << "No se pudo leer la imagen.\nFichero no existente o tipo erróneo: " << nombre << endl;
		}

	return exito;
}

// Convertir los datos a vector unidimensional
byte *Imagen::pasar_unidimensional(int &tam) {
	// Calculamos el tamaño, por si acaso
	tam = this->filas*this->columnas;
	// Reservamos el espacion necesario;
	byte *datos = new byte[tam];

	// Copiamos los datos al vector
	for (int i=0; i<this->filas; ++i)
		for (int j=0; j<this->columnas; ++j)
			datos[i*this->columnas+j] = this->valor_pixel(i,j);

	return datos;
}

// Calcula la media simple de valores de gris en una imagen
double Imagen::calcular_media_gris(Imagen *imagen_entrada) {
	double media = 0;
	int f = imagen_entrada->num_filas();
	int c = imagen_entrada->num_columnas();

	for (int i=0; i<f; ++i)
		for (int j=0; j<c; ++j)
			media += imagen_entrada->valor_pixel(i,j);

	media /= f*c;

	return media;
}

// Calcula las medias de grises en dos extremos en función de
// un umbral de entrada
void Imagen::separar_segun_umbral(Imagen *imagen_entrada, const double umbral_entrada,
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

// -- Umbraliza una imagen según un umbral dado --
void Imagen::umbralizar_basico(Imagen *imagen_entrada, const byte umbral) {
	for (int i=0; i<imagen_entrada->num_filas(); ++i)
		for (int j=0; j<imagen_entrada->num_columnas(); ++j)
			if (imagen_entrada->valor_pixel(i,j) > umbral)
				imagen_entrada->asigna_pixel(i,j,255);
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

// -- Constructor mediante fichero --
Imagen::Imagen(const char *nombre) : Imagen() {
	if (!this->leer_fichero_PGM(nombre))
		exit(1);
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

bool Imagen::cargar_imagen_PGM(const char *nombre) {
	return this->leer_fichero_PGM(nombre);
}

bool Imagen::escribir_imagen_PGM(const char *nombre) {
	bool exito = false;
	int tam = 0;
	byte *datos = this->pasar_unidimensional(tam);

	if (EscribirImagenPGM(nombre,datos,this->filas,this->columnas))
		exito = true;

	delete [] datos;

	return exito;
}

// -- Umbralizar una imagen con un ubmral automático --
bool Imagen::umbralizado_automatico(const char *fichero_entrada, const char *fichero_salida, byte &umbral) {
	bool exito = false;
	bool primera_vez = true;
	double umbral_actual = 0, umbral_siguiente = 0;
	double umbral_primero = 0, umbral_segundo = 0;
	double epsilon = 0.00001;

	// Si podemos cargar la imagen seguimos
	if (this->cargar_imagen_PGM(fichero_entrada)) {
		exito = true;

		// La primera vez que entramos al cálculo de la media de
		// umbrales, debemos usar como referencia la media de
		// la imagen leída de fichero. Las siguientes veces tenemos
		// que tomar como referencia el cálculo conseguido en la iteración anterior
		do {
			if (primera_vez) {
				umbral_actual = this->calcular_media_gris(this);
				primera_vez = false;
			}
			else {
				umbral_actual = umbral_siguiente;
			}

			// Se calculan las medias de grises sobre la imagen cargada
			// separando la selección de píxeles en función del umbral
			// o media de tonos de gris que ya hemos calculado
			this->separar_segun_umbral(this,umbral_actual,umbral_primero,umbral_segundo);
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
		this->umbralizar_basico(this,umbral);

		// Si no podemos escribir la imagen, entendemos que hemos
		// fracasado
		exito = this->escribir_imagen_PGM(fichero_salida);
	}

	return exito;
}
