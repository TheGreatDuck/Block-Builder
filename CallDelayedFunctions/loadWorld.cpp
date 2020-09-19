#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"

static void load_map(char* program_directory, char* worldName)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.map")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.map"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.map");
    FILE* file = fopen(fileName, "r");

    unsigned int width;
    unsigned int height;

    fscanf(file, "%u\n", &width);
    fscanf(file, "%u\n", &height);

    for (unsigned int i = 0; i < height; i += 1)
    {
        for (unsigned int j = 0; j < width; j += 1)
        {
            unsigned int type;
            fscanf(file, "%u", &type);

            if (type == 0)
            {
                //instance_create(j*32, i*32, obj_mapWater);
            }

            if (type == 1)
            {
                //instance_create(j*32, i*32, obj_mapLand);
            }

            if (type == 2)
            {
                //instance_create(j*32, i*32, obj_mapGrass);
            }

            if (type == 3)
            {
                //instance_create(j*32, i*32, obj_mapSand);
            }

            if (type == 4)
            {
                //instance_create(j*32, i*32, obj_mapSwamp);
            }

            if (type == 5)
            {
                //instance_create(j*32, i*32, obj_mapMetal);
            }

            if (type == 6)
            {
                //instance_create(j*32, i*32, obj_mapLava);
            }
        }
    }
    fclose(file);
}

static void load_collision(char* program_directory, char* worldName)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.map")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.map"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.col");
    FILE* file = fopen(fileName, "r");

    unsigned int width;
    unsigned int height;

    fscanf(file, "%u\n", &width);
    fscanf(file, "%u\n", &height);

    for (unsigned int i = 0; i < height; i += 1)
    {
        for (unsigned int j = 0; j < width; j += 1)
        {
            unsigned int type;
            fscanf(file, "%u", &type);
            if (type == 1)
            {
                //instance_create(j*32, i*32, obj_mapBarrier);
            }
        }
    }
    fclose(file);
}

static void load_player(char* program_directory, char* worldName)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.play")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.play"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.play");
    FILE* file = fopen(fileName, "r");

    unsigned int width;
    unsigned int height;

    fscanf(file, "%u\n", &width);
    fscanf(file, "%u\n", &height);

    //instance_create(32*width, 32*height, obj_mapPlayer);

    fclose(file);
}

static void load_path(char* program_directory, char* worldName)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.pat")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.pat"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.pat");
    FILE* file = fopen(fileName, "r");

    unsigned int width;
    unsigned int height;

    fscanf(file, "%u\n", &width);
    fscanf(file, "%u\n", &height);

    for (unsigned int i = 0; i < height; i += 1)
    {
        for (unsigned int j = 0; j < width; j += 1)
        {
            unsigned int type;
            fscanf(file, "%u", &type);

            if (type & (1 << 0))
            {
                //instance_create(j*32, i*32, obj_mapWestMapPath);
            }

            if (type & (1 << 1))
            {
                //instance_create(j*32, i*32, obj_mapEastMapPath);
            }

            if (type & (1 << 2))
            {
                //instance_create(j*32, i*32, obj_mapNorthMapPath);
            }

            if (type & (1 << 3))
            {
                //instance_create(j*32, i*32, obj_mapSouthMapPath);
            }
        }
    }
    fclose(file);
}

static void load_level(char* program_directory, char* worldName)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.lev")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.lev"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.lev");
    FILE* file = fopen(fileName, "r");

    unsigned int numberOfLevels;
    fscanf(file, "%u\n", &numberOfLevels);

    for (unsigned int i = 0; i < numberOfLevels; i += 1)
    {
        unsigned int xPos;
        unsigned int yPos;

        unsigned int level;

        unsigned int north;
        unsigned int west;
        unsigned int east;
        unsigned int south;

        fscanf(file, "%u %u %u %u %u %u %u\n", &xPos, &yPos, &level, &north, &west, &east, &south);

        /*createdLevel = instance_create(32*xPos, 32*yPos, obj_mapLevel);

        createdLevel.level = file_text_read_real(file);

        createdLevel.north = file_text_read_real(file);
        createdLevel.west  = file_text_read_real(file);
        createdLevel.east  = file_text_read_real(file);
        createdLevel.south = file_text_read_real(file);*/
    }
    fclose(file);
}

static void load_lock(char* program_directory, char* worldName)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.loc")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\overworld.loc"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.loc");
    FILE* file = fopen(fileName, "r");

    unsigned int numberOfLocks;
    fscanf(file, "%u\n", &numberOfLocks);

    for (unsigned int i = 0; i < numberOfLocks; i += 1)
    {
        unsigned int xPos;
        unsigned int yPos;

        unsigned int level;

        unsigned int north;
        unsigned int west;
        unsigned int east;
        unsigned int south;

        fscanf(file, "%u %u %u %u %u %u %u\n", &xPos, &yPos, &level, &north, &west, &east, &south);

        /*createdLock = instance_create(32*xPos, 32*yPos, obj_mapLock);

        createdLock.level = file_text_read_real(file);

        createdLock.north = file_text_read_real(file);
        createdLock.west  = file_text_read_real(file);
        createdLock.east  = file_text_read_real(file);
        createdLock.south = file_text_read_real(file);*/
    }
    fclose(file);
}

void load_world(char* program_directory, char* worldName)
{
    load_map(program_directory, worldName);
    load_collision(program_directory, worldName);
    load_player(program_directory, worldName);
    load_path(program_directory, worldName);
    load_level(program_directory, worldName);
    load_lock(program_directory, worldName);
}
