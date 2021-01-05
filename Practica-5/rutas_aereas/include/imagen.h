enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;
struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
};
class Imagen{
  private:
    Pixel ** data;
    int nf,nc;

    void Reservar(int nf=0, int nc=0);
    void Borrar(); //Falta
    void Copiar(const Imagen &I); //Falta

  public:
   Imagen(); //Falta

   Imagen(int f,int c);

   Imagen(const Imagen & I); //Falta

   Imagen & operator=(const Imagen & I); //Falta

   ~Imagen(); //Falta

   //set y get
   Pixel & operator ()(int i,int j);

   const Pixel & operator ()(int i,int j)const;

   void EscribirImagen(const char * nombre);

   void LeerImagen (const char *nombre,const string &nombremascara="");
   void LimpiarTransp(); //Falta
   int num_filas()const{return nf;}
   int num_cols()const{return nc;}
   void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);
   Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj); //Falta
};
