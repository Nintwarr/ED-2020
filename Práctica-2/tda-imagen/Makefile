HOME = .
SRC = $(HOME)/src
INC= $(HOME)/include
OBJ = $(HOME)/obj
BIN = $(HOME)/bin

negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o
	g++ -g -o negativo $(OBJ)/negativo.o $(OBJ)/imagenES.o

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	g++ -g -c -o $(OBJ)/imagenES.o -I$(INC) $(SRC)/imagenES.cpp

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	g++ -g -c -o $(OBJ)/negativo.o -I$(INC) $(SRC)/negativo.cpp


clean:
	rm -f $(OBJ)/*.o $(BIN)/*_exe
