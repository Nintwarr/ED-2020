SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

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


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
