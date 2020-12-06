HOME = .
SRC = $(HOME)/src
INC= $(HOME)/include
OBJ = $(HOME)/obj
BIN = $(HOME)/bin
LIB = $(HOME)/lib

all: documentacion $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(OBJ)/Pila_max_VD.o $(OBJ)/elemento.o
	g++ -g -o $(BIN)/main $(OBJ)/main.o $(OBJ)/Pila_max_VD.o $(OBJ)/elemento.o

documentacion:
	doxygen Doxyfile



$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/pila_max.h
	g++ -g -c -o $(OBJ)/main.o -I$(INC) $(SRC)/main.cpp

$(OBJ)/Pila_max_VD.o : $(SRC)/Pila_max_VD.cpp
	g++ -g -c -o $(OBJ)/Pila_max_VD.o -I$(INC) $(SRC)/Pila_max_VD.cpp

$(OBJ)/elemento.o : $(SRC)/elemento.cpp
	g++ -g -c -o $(OBJ)/elemento.o -I$(INC) $(SRC)/elemento.cpp




clean:
	rm -f $(OBJ)/*.o $(BIN)/* 
