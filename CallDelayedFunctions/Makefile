CC = g++ 
SRC = *.cpp
OUT = bin/CallDelayedFunctions.dll
OBJ = build
INC= -I include

all: bin/CallDelayedFunctions.dll

bin/CallDelayedFunctions.dll: build/*.o
	$(CC) -shared -o $(OUT) $(OBJ) 

build/*.o: $(SRC) 
	$(CC) $(INC) -DBDLL -c $(SRC) -o $(OBJ)
