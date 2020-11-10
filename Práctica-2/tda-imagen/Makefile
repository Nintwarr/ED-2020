HOME = .
SRC = $(HOME)/src
INC= $(HOME)/include
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

all: imagen negativo ejer4 ejer2

imagen: $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/main.o
	g++ -g -o $(BIN)/imagen $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/main.o

negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/negativo $(OBJ)/negativo.o $(OBJ)/imagenES.o

ejer4: $(OBJ)/ejer4.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/ejer4 $(OBJ)/ejer4.o $(OBJ)/imagenES.o

ejer2: $(OBJ)/ejer2.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/ejer2 $(OBJ)/ejer2.o $(OBJ)/imagen.o $(OBJ)/imagenES.o



$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/imagenES.o -I$(INC) $(SRC)/imagenES.cpp

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	g++ -g -c -o $(OBJ)/negativo.o -I$(INC) $(SRC)/negativo.cpp

$(OBJ)/ejer4.o : $(INC)/imagenES.h $(SRC)/ejer4.cpp
	g++ -g -c -o $(OBJ)/ejer4.o -I$(INC) $(SRC)/ejer4.cpp

$(OBJ)/ejer2.o: $(INC)/imagen.h $(INC)/imagenES.h $(SRC)/ejer2.cpp
	g++ -g -c -o $(OBJ)/ejer2.o -I$(INC) $(SRC)/ejer2.cpp

$(OBJ)/imagen.o: $(OBJ)/imagenES.o $(INC)/imagen.h $(INC)/imagenES.h $(SRC)/imagen.cpp
	g++ -g -c -o $(OBJ)/imagen.o -I$(INC) $(SRC)/imagen.cpp

$(OBJ)/main.o: $(INC)/imagenES.h $(INC)/imagen.h $(SRC)/main.cpp
	g++ -g -c -o $(OBJ)/main.o -I$(INC) $(SRC)/main.cpp


clean:
	rm -f $(OBJ)/*.o $(BIN)/*
