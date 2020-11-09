HOME = .
SRC = $(HOME)/src
INC= $(HOME)/include
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

all: imagen negativo ejer4

imagen: $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/main.o
	g++ -g -o $(BIN)/imagen $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/main.o

negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/negativo $(OBJ)/negativo.o $(OBJ)/imagenES.o

ejer4: $(OBJ)/ejer4.o $(OBJ)/imagenES.o
	g++ -g -o $(BIN)/ejer4 $(OBJ)/ejer4.o $(OBJ)/imagenES.o



$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/imagenES.o -I$(INC) $(SRC)/imagenES.cpp

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	g++ -g -c -o $(OBJ)/negativo.o -I$(INC) $(SRC)/negativo.cpp


$(OBJ)/ejer4.o : $(SRC)/ejer4.cpp
	g++ -g -c -o $(OBJ)/ejer4.o -I$(INC) $(SRC)/ejer4.cpp

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	g++ -g -c -o $(OBJ)/imagen.o -I$(INC) $(SRC)/imagen.cpp

$(OBJ)/main.o: $(INC)/imagenES.h $(INC)/imagen.h $(SRC)/main.cpp
	g++ -g -c -o $(OBJ)/main.o -I$(INC) $(SRC)/main.cpp


clean:
	rm -f $(OBJ)/*.o $(BIN)/*
