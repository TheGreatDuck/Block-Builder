CC = g++ 
SRC = player.cpp
OUT = bin/CallDelayedFunctions.dll
OBJ = build/player.o 
INC= -I include

all: bin/CallDelayedFunctions.dll

bin/CallDelayedFunctions.dll: build/player.o
	$(CC) -shared -o $(OUT) $(OBJ) 

build/player.o: $(SRC) 
	$(CC) $(INC) -DBDLL -c $(SRC) -o $(OBJ)
