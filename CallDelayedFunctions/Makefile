CC = g++ 
OUT = bin/CallDelayedFunctions.dll
OBJ = player.o blockAlchemy.o call_delayed_functions.o battle.o
INC= -I include

all: bin/CallDelayedFunctions.dll

bin/CallDelayedFunctions.dll: player.o blockAlchemy.o delayed_function_calls.o
	$(CC) -shared -o $(OUT) $(OBJ) 

player.o: player.cpp
	$(CC) $(INC) -DBDLL -c player.cpp -o player.o

blockAlchemy.o: blockAlchemy.cpp
	$(CC) $(INC) -DBDLL -c blockAlchemy.cpp -o blockAlchemy.o

delayed_function_calls.o: delayed_function_calls.cpp
	$(CC) $(INC) -DBDLL -c delayed_function_calls.cpp -o delayed_function_calls.o

battle.o: battle.cpp
	$(CC) $(INC) -DBDLL -c battle.cpp -o battle.o
