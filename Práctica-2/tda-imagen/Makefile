HOME = .
SRC = $(HOME)/src
INC= $(HOME)/include
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

imagen: $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/main.o
	g++ -o $(BIN)/imagen $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/main.o

negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/negativo $(OBJ)/negativo.o $(OBJ)/imagenES.o

all: imagen negativo

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/imagenES.o -I$(INC) $(SRC)/imagenES.cpp

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	g++ -g -c -o $(OBJ)/negativo.o -I$(INC) $(SRC)/negativo.cpp

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ -c -o $(OBJ)/imagen.o -I$(INC) $(SRC)/imagen.cpp

$(OBJ)/main.o: $(INC)/imagenES.h $(INC)/imagen.h $(SRC)/main.cpp
	g++ -c -o $(OBJ)/main.o -I$(INC) $(SRC)/main.cpp


clean:
	rm -f $(OBJ)/*.o $(BIN)/*
