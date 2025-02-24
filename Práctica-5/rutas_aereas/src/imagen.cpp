/**
  * @author Darío Megías Guerrero y María Sánchez Marcos
  * @file imagen.cpp
  * @brief Fichero de implementación para Imagen
  */

#include <imagen.h>
#include <imagenES.h>
#include <cassert>
#include <iostream>

void Imagen::Reservar(int nf, int nc) {
    this->nf = nf;
    this->nc = nc;

    if (nf==0 || nc==0)
		data = nullptr;
	else {
		data = new Pixel*[nf];

		for (int i=0; i<nf; ++i) {
            data[i] = new Pixel[nc];
            for (int j=0;j<nc;++j){
                data[i][j].r=255;
                data[i][j].g=255;
                data[i][j].b=255;
                data[i][j].transp=0;
	        }
        }
    }
}

void Imagen::Copiar(const Imagen &I) {
    // Supone que la memoria está bien reservada
	assert(nf==I.num_filas() && nc==I.num_cols());

	for (int i=0; i<nf; ++i)
		for (int j=0; j<nc; ++j)
			(*this)(i,j) = I(i,j);
}

Imagen::Imagen() {
    nf = nc = 0;
    data = nullptr;
}

Imagen::Imagen(int f,int c){
  Reservar(f,c);
}

Imagen::Imagen(const Imagen & I){
    *this = I;
}

Imagen & Imagen::operator=(const Imagen & I) {
    if (this != &I) {
        Borrar();
        Reservar(I.num_filas(),I.num_cols());
        Copiar(I);
    }

    return *this;
}

Imagen::~Imagen() {
    Borrar();
}

Pixel & Imagen::operator ()(int i,int j) {
    assert(i>=0 && i<nf && j>=0 && j<nc);
    return data[i][j];
}

const Pixel & Imagen::operator()(int i,int j)const{
  assert(i>=0 && i<nf && j>=0 && j<nc);
  return data[i][j];
}

void Imagen::Borrar(){
    for (int i = 0; i < nf; i ++){
        delete [] data[i];
    }
    delete [] data;

    nc = 0;
    nf = 0;

}

void Imagen::EscribirImagen(const char * nombre){
    unsigned char * aux = new unsigned char [nf*nc*3];
    unsigned char * m = new unsigned char [nf*nc];

    int total = nf*nc*3;
    for (int i=0;i<total;i+=3){
        int posi = i /(nc*3);
        int posj = (i%(nc*3))/3;

        aux[i]=data[posi][posj].r;
        aux[i+1]=data[posi][posj].g;
        aux[i+2]=data[posi][posj].b;
        m[i/3]=data[posi][posj].transp;
    }

    if (!EscribirImagenPPM (nombre, aux,nf,nc)){
    cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
    }

    delete[]aux;
    string n_aux = "mascara_";
    n_aux =n_aux+nombre;
    std::size_t found =n_aux.find(".ppm");

    if (found!=std::string::npos){
        n_aux =n_aux.substr(0,found);
    }

    n_aux =n_aux+".pgm";


    if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
        cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
    }

    delete []m;

}

void Imagen::LeerImagen(const char * nombre,const string &nombremascara){
    int f,c;
    unsigned char * aux,*aux_mask ;

    LeerTipoImagen(nombre, f, c);
    aux = new unsigned char [f*c*3];
    LeerImagenPPM (nombre, f,c,aux);

    if (nombremascara!="") {
        int fm,cm;
        LeerTipoImagen(nombremascara.c_str(), fm, cm);
        aux_mask = new unsigned char [fm*cm];
        LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
    } else {
	    aux_mask=0;
    }

    Imagen I(f,c);
    int total = f*c*3;

    for (int i=0;i<total;i+=3){
        int posi = i /(c*3);
        int posj = (i%(c*3))/3;
        //   cout<<posi<<" " <<posj<<endl;
        I.data[posi][posj].r=aux[i];
        I.data[posi][posj].g=aux[i+1];
        I.data[posi][posj].b=aux[i+2];
        if (aux_mask!=0)
            I.data[posi][posj].transp=aux_mask[i/3];
        else
            I.data[posi][posj].transp=255;
    }

    *this = I;
    if (aux_mask!=0) delete[]aux_mask;
    delete []aux;

}

void Imagen::PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);

    for (int i=0;i<I.nf;i++)
        for (int j=0;j<I.nc;j++)
        if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
            if (I.data[i][j].transp!=0){
                if (tippegado==OPACO)
                    data[i+posi][j+posj]=I.data[i][j];
                else{
                    data[i+posi][j+posj].r=(data[i+posi][j+posj].r+I.data[i][j].r)/2;
                    data[i+posi][j+posj].g=(data[i+posi][j+posj].r+I.data[i][j].g)/2;
                    data[i+posi][j+posj].b=(data[i+posi][j+posj].r+I.data[i][j].b)/2;
                }
            }
        }
}

void Imagen::LimpiarTransp(){
       for (int i = 0; i < nf; i++){
           for (int j = 0; j < nc; j++){
               data[i][j].transp = 0;
           }
       }
   }

Imagen Imagen::ExtraeImagen(int posi, int posj, int dimi, int dimj) {
    if (posi<0 || posi>nc || posj<0 || posj>nf) {
        Imagen imagen;
        return imagen;
    } else {
        Imagen imagen(dimi,dimj);
        Pixel blank_pixel;
        blank_pixel.r = blank_pixel.g = blank_pixel.b = blank_pixel.transp = 255;

        for (int i=0; i<dimi; ++i, ++posi)
            for(int j=0;j<dimj; ++j, ++posj) {
                if (posi<=nc && posj<=nf)
                    imagen(i,j) = (*this)(posi,posj);
                else
                    imagen(i,j) = blank_pixel;
            }

        return imagen;
    }
}
