#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "gameMakerLibrary.hpp"
#include "blockGraph.hpp"
#include "loadLevel.hpp"

static void load_blockGraph(const char* worldName, const char* levelLoading)
{
    char fileName[strlen("Worlds\\") + strlen(worldName) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\level.ter")];
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\level.ter"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\Level ");
    strcat(fileName,levelLoading);
    strcat(fileName,"\\level.ter");

    blockGraph_loadFromFile(fileName);
    blockGraph_setUpBlockGraphList();
    blockGraph_create3DModel();
}

void load_level(const char* worldName, const char* levelLoading)
{
    load_blockGraph(worldName, levelLoading);
}
