/**
  * @author Darío Megías Guerrero y María Sánchez Marcos
  * @file imagen.h
  * @brief Fichero cabecera para TDA imagen
  *
  * Representa puntos geograficos
 * @date Enero 2021
  *
  */
#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <string>

enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;
/**
 *  @brief Struct Pixel
 *
 *
 * Una instancia @e c del tipo de struct Pixel almacena la siguiente información:
 * - Su valor rgb: tres valores entre 0 y 255 que representan la presencia de rojo,verde y azul en un pixel
 * -  El valor de transparencia
  *
*/
struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
};

/**
 *  @brief Imagen
 *
 *
 * Un objeto de clase imagen almacena los siguientes valores:
 * - Una matriz bidimensional en la que cada elemento representa un pixel.
 * - Número de filas
 * - Número de columnas
 *
*/
class Imagen{
  private:
    Pixel ** data;
    int nf,nc;

    void Reservar(int nf=0, int nc=0);
    void Borrar(); //Falta
    void Copiar(const Imagen &I); //Falta

  public:
   /**
   * @brief Constructor por defecto
   */
   Imagen();

 /**
   * @brief constructor con parámetros
   * @param f numero de filas
   * @param c numero de columnas
   * @return una instancia de imagen de tamaño fxc
   */
   Imagen(int f,int c);

/**
   * @brief constructor de copia
   * @param I Imagen que quiere ser duplicada
   * @return una instancia con los datos de I
   */
   Imagen(const Imagen & I);

/**
   * @brief Operador de asignacion
   * @param I Imagen que queremos que se asigne a la instancia actual
   * @return Una imagen con los datos de I
   */
   Imagen & operator=(const Imagen & I);

/**
   * @brief destructor
   */
   ~Imagen();

  /**
   * @brief Operador () (Set y get)
   * @param i Numero de fila
   * @param j Numero de columna
   * @return Devuelve el pixel de la matriz correspondiente  a la posicion [i][j]
   */
   Pixel & operator ()(int i,int j);

/**
   * @brief Operador () constante
   * @param i Numero de fila
   * @param j Numero de columna
   * @return Devuelve el pixel de la matriz correspondiente  a la posicion [i][j]
   */
   const Pixel & operator ()(int i,int j)const;

  /**
   * @brief Escribe los datos que contiene la instancia al disco
   * @param nombre Nombre del archivo en el que se va a escribir
   */
   void EscribirImagen(const char * nombre);

 /**
   * @brief Lee los datos que contiene la instancia
   * @param nombre Nombre del archivo que se va a poner
   * @param nombremascara nombre del archivo que contiene la mascara de recorte para la imagen
   */
   void LeerImagen (const char *nombre,const string &nombremascara="");
   void LimpiarTransp();

   /**
   * @brief Return numFilas
   * @return Devuelve el numero de Filas de una imagen
   */
   int num_filas()const{return nf;}
   /**
   * @brief Return numColumnas
   * @return Devuelve el numero de columnas de una imagen
   */
   int num_cols()const{return nc;}

    /**
   * @brief Pone una imagen encima de otra
   * @param posi Fila en la que se va a pegar
   * @param posj Columna en la que se va a pegar
   * @param I Imagen que se va a pegar encima de la que tenemos
   * @param tippegado forma en la que se va a pegar la imagen (por defecto opaco)
   */
   void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

    /**
   * @brief Extrae una subimagen de una imagen
   * @param posi Fila en la que se empieza
   * @param posj Columna en la que se empieza
   * @param dimi Dimension de filas
   * @param dimj fDimension de columnas
   * @return la imagen creada a partir del recorte hecho
   */
   Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);
};

#endif
