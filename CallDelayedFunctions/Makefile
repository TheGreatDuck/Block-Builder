CC = g++ 
OUT = bin/CallDelayedFunctions.dll
OBJ = player.o blockAlchemy.o call_delayed_functions.o
INC= -I include

all: bin/CallDelayedFunctions.dll

bin/CallDelayedFunctions.dll: build/player.o build/blockAlchemy.o build/delayed_function_calls.o
	$(CC) -shared -o $(OUT) $(OBJ) 

build/player.o: player.cpp
	$(CC) $(INC) -DBDLL -c player.cpp -o build/player.o

build/blockAlchemy.o: blockAlchemy.cpp
	$(CC) $(INC) -DBDLL -c blockAlchemy.cpp -o build/blockAlchemy.o

build/delayed_function_calls.o: delayed_function_calls.cpp
	$(CC) $(INC) -DBDLL -c delayed_function_calls.cpp -o build/delayed_function_calls.o
