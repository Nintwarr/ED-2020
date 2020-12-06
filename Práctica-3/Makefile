HOME = .
SRC = $(HOME)/src
INC= $(HOME)/include
OBJ = $(HOME)/obj
BIN = $(HOME)/bin
LIB = $(HOME)/lib

all: documentacion $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(OBJ)/pila_max.o $(OBJ)/elemento.o
	g++ -g -o $(BIN)/main -I$(INC) $(OBJ)/main.o $(OBJ)/pila_max.o $(OBJ)/elemento.o

documentacion:
	doxygen Doxyfile



$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/pila_max.h
	g++ -g -c -o $(OBJ)/main.o -I$(INC) $(SRC)/main.cpp

$(OBJ)/pila_max.o: $(INC)/pila_max.h $(INC)/Pila_max_VD.h $(SRC)/Pila_max_VD.cpp $(INC)/Pila_max_Cola.h $(SRC)/Pila_max_Cola.cpp $(INC)/elemento.h
	g++ -g -c -o $(OBJ)/pila_max.o -I{$(INC),$(SRC)} $(SRC)/pila_max.cpp

$(OBJ)/elemento.o : $(SRC)/elemento.cpp $(INC)/elemento.h
	g++ -g -c -o $(OBJ)/elemento.o -I$(INC) $(SRC)/elemento.cpp




clean:
	rm -f $(OBJ)/*.o $(BIN)/*
