SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: pruebapegado pruebarotacion rutasaereas documentacion

rutasaereas: $(BIN)/rutasaereas

pruebapegado: $(BIN)/pruebapegado

pruebarotacion: $(BIN)/pruebarotacion

$(BIN)/rutasaereas: $(OBJ)/rutasaereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/punto.o $(OBJ)/pais.o $(OBJ)/paises.o $(OBJ)/ruta.o $(OBJ)/almacenrutas.o
	$(CXX) -o $(BIN)/rutasaereas $(OBJ)/rutasaereas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/punto.o $(OBJ)/pais.o $(OBJ)/paises.o $(OBJ)/ruta.o $(OBJ)/almacenrutas.o

$(BIN)/pruebarotacion: $(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/pruebarotacion $(OBJ)/pruebarotacion.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

$(BIN)/pruebapegado: $(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	$(CXX) -o $(BIN)/pruebapegado $(OBJ)/pruebapegado.o $(OBJ)/imagen.o $(OBJ)/imagenES.o


$(OBJ)/rutasaereas.o: $(INC)/imagen.h $(INC)/paises.h $(INC)/almacenrutas.h  $(SRC)/rutasaereas.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/rutasaereas.o $(SRC)/rutasaereas.cpp

$(OBJ)/pruebarotacion.o: $(INC)/imagen.h  $(SRC)/pruebarotacion.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebarotacion.o $(SRC)/pruebarotacion.cpp

$(OBJ)/pruebapegado.o: $(INC)/imagen.h  $(SRC)/pruebapegado.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebapegado.o $(SRC)/pruebapegado.cpp

$(OBJ)/punto.o: $(INC)/punto.h $(SRC)/punto.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp

$(OBJ)/pais.o: $(INC)/punto.h $(INC)/pais.h $(SRC)/pais.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pais.o $(SRC)/pais.cpp

$(OBJ)/paises.o: $(INC)/pais.h $(INC)/paises.h $(SRC)/paises.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/paises.o $(SRC)/paises.cpp

$(OBJ)/ruta.o: $(INC)/punto.h $(INC)/ruta.h $(SRC)/ruta.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/ruta.o $(SRC)/ruta.cpp

$(OBJ)/almacenrutas.o: $(INC)/ruta.h $(INC)/almacenrutas.h $(SRC)/almacenrutas.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/almacenrutas.o $(SRC)/almacenrutas.cpp

$(OBJ)/imagen.o: $(INC)/imagen.h $(INC)/imagenES.h $(SRC)/imagen.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/imagen.o $(SRC)/imagen.cpp

$(OBJ)/imagenES.o: $(INC)/imagen.h $(INC)/imagenES.h $(SRC)/imagenES.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/imagenES.o $(SRC)/imagenES.cpp


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm -f $(BIN)/* doc/html/*
