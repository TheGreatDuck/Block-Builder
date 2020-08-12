#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"

static void load_blockGraph(char* program_directory, char* worldName, char* levelLoading)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\level.ter")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\level.ter"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\Level ");
    strcat(fileName,levelLoading);
    strcat(fileName,"\\level.ter");

    blockGraph_loadFromFile(fileName);
    blockGraph_setUpBlockGraphList();
    blockGraph_create3DModel();
}

GMEXPORT double load_level(char* program_directory, char* worldName, char* levelLoading)
{
    load_blockGraph(program_directory, worldName, levelLoading);

    return 1.0;
}
