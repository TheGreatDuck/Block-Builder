CC = g++ 
SRC = player.cpp blockAlchemy.cpp
OUT = bin/CallDelayedFunctions.dll
OBJ = player.o blockAlchemy.o
INC= -I include

all: bin/CallDelayedFunctions.dll

bin/CallDelayedFunctions.dll: build/*.o
	$(CC) -shared -o $(OUT) $(OBJ) 

build/*.o: $(SRC) 
	$(CC) $(INC) -DBDLL -c $(SRC) -o $(OBJ)
