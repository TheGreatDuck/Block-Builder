CC = g++ 
OUT = bin/CallDelayedFunctions.dll
OBJ = player.o blockAlchemy.o delayed_function_calls.o battle.o blockGraph.o camera.o combatant.o controls.o gameLoop.o linkedCycle.o loadLevel.o loadWorld.o vector.o
INC= -I include

all: bin/CallDelayedFunctions.dll

bin/CallDelayedFunctions.dll: $(OBJ)
	$(CC) -shared -o $(OBJ) 

player.o: player.cpp
	$(CC) $(INC) -DBDLL -c player.cpp -o player.o

blockAlchemy.o: blockAlchemy.cpp
	$(CC) $(INC) -DBDLL -c blockAlchemy.cpp -o blockAlchemy.o

delayed_function_calls.o: delayed_function_calls.cpp
	$(CC) $(INC) -DBDLL -c delayed_function_calls.cpp -o delayed_function_calls.o

battle.o: battle.cpp
	$(CC) $(INC) -DBDLL -c battle.cpp -o battle.o

blockGraph.o: blockGraph.cpp
	$(CC) $(INC) -DBDLL -c blockGraph.cpp -o blockGraph.o

camera.o: camera.cpp
	$(CC) $(INC) -DBDLL -c camera.cpp -o camera.o

combatant.o: combatant.cpp
	$(CC) $(INC) -DBDLL -c combatant.cpp -o combatant.o

controls.o: controls.cpp
	$(CC) $(INC) -DBDLL -c controls.cpp -o controls.o

gameLoop.o: gameLoop.cpp
	$(CC) $(INC) -DBDLL -c gameLoop.cpp -o gameLoop.o

linkedCycle.o: linkedCycle.cpp
	$(CC) $(INC) -DBDLL -c linkedCycle.cpp -o linkedCycle.o

loadLevel.o: loadLevel.cpp
	$(CC) $(INC) -DBDLL -c loadLevel.cpp -o loadLevel.o

loadWorld.o: loadWorld.cpp
	$(CC) $(INC) -DBDLL -c loadWorld.cpp -o loadWorld.o

vector.o: vector.cpp
	$(CC) $(INC) -DBDLL -c vector.cpp -o vector.o
