CC = g++ 
OUT = bin/CallDelayedFunctions.dll
OBJ = player.o blockAlchemy.o
INC= -I include

all: bin/CallDelayedFunctions.dll

bin/CallDelayedFunctions.dll: build/player.o build/blockAlchemy.o
	$(CC) -shared -o $(OUT) $(OBJ) 

build/player.o: player.cpp
	$(CC) $(INC) -DBDLL -c player.cpp -o build/player.o

build/blockAlchemy.o: blockAlchemy.cpp
	$(CC) $(INC) -DBDLL -c blockAlchemy.cpp -o blockAlchemy.o
