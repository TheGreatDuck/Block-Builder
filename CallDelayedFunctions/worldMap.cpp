#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include <malloc.h>
#include "delayed_function_calls.hpp"
#include "worldMap.hpp"

unsigned int map_width;
unsigned int map_height;
unsigned int map_player_x;
unsigned int map_player_y;
unsigned int* map_icons;
unsigned int* map_collision;
unsigned int* map_path;

unsigned int numberOfLocks;
map_lock* map_locks;

unsigned int numberOfLevels;
map_level* map_levels;

int* map_levelCompletion;

static void load_map(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.map");
    FILE* file = fopen(fileName, "r");

    fscanf(file, "%u\n", &map_width);
    fscanf(file, "%u\n", &map_height);

    free(map_icons);
    map_icons = (unsigned int*)malloc(map_width*map_height*sizeof(unsigned int));

    for (unsigned int i = 0; i < map_height; i += 1)
    {
        for (unsigned int j = 0; j < map_width; j += 1)
            fscanf(file, "%u", &map_icons[map_width*i + j]);
    }
    fclose(file);
}

static void save_map(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.map");
    FILE* file = fopen(fileName, "w");

    fprintf(file, "%u\n", map_width);
    fprintf(file, "%u\n", map_height);

    for (unsigned int i = 0; i < map_height; i += 1)
    {
        for (unsigned int j = 0; j+1 < map_width; j += 1)
            fprintf(file, "%u ", map_icons[map_width*i + j]);

        fprintf(file, "%u\n", map_icons[map_width*i + map_width-1]);
    }
    fclose(file);
}

static void load_collision(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.col");
    FILE* file = fopen(fileName, "r");

    free(map_collision);
    map_collision = (unsigned int*)malloc(map_width*map_height*sizeof(unsigned int));

    for (unsigned int i = 0; i < map_height; i += 1)
    {
        for (unsigned int j = 0; j < map_width; j += 1)
            fscanf(file, "%u", &map_collision[map_width*i + j]);
    }
    fclose(file);
}

static void save_collision(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.map"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.col");
    FILE* file = fopen(fileName, "r");

    for (unsigned int i = 0; i < map_height; i += 1)
    {
        for (unsigned int j = 0; j+1 < map_width; j += 1)
            fprintf(file, "%u ", map_collision[map_width*i + j]);

        fprintf(file, "%u\n", map_collision[map_width*i + map_width-1]);
    }
    fclose(file);
}

static void load_player(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.play"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.play"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.play");
    FILE* file = fopen(fileName, "r");

    fscanf(file, "%u\n", &map_player_x);
    fscanf(file, "%u\n", &map_player_y);

    fclose(file);
}

static void load_path(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.pat"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.pat"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.pat");
    FILE* file = fopen(fileName, "r");

    free(map_path);
    map_path = (unsigned int*)malloc(map_width*map_height*sizeof(unsigned int));

    for (unsigned int i = 0; i < map_height; i += 1)
    {
        for (unsigned int j = 0; j < map_width; j += 1)
            fscanf(file, "%u", &map_path[map_width*i + j]);
    }
    fclose(file);
}

static void load_level(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.lev"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.lev"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.lev");
    FILE* file = fopen(fileName, "r");

    fscanf(file, "%u\n", &numberOfLevels);

    map_levels = (map_level*)malloc(sizeof(map_level)*numberOfLevels);
    map_levelCompletion = (int*)malloc(sizeof(int)*numberOfLevels);

    for (unsigned int i = 0; i < numberOfLevels; i += 1)
    {
        map_levelCompletion[i] = 15;
        fscanf(file, "%u %u %u %u %u %u %u\n", &map_levels[i].xPos, &map_levels[i].yPos, &map_levels[i].level, &map_levels[i].north, &map_levels[i].west, &map_levels[i].east, &map_levels[i].south);
    }
    fclose(file);
}

static void load_lock(const char* worldName)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.loc"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName) + strlen("\\overworld.loc"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\overworld.loc");
    FILE* file = fopen(fileName, "r");

    fscanf(file, "%u\n", &numberOfLocks);

    map_locks = (map_lock*)malloc(sizeof(map_lock)*numberOfLocks);

    for (unsigned int i = 0; i < numberOfLocks; i += 1)
    {
        unsigned int north;
        unsigned int west;
        unsigned int east;
        unsigned int south;

        fscanf(file, "%u %u %u %u %u %u %u\n", &map_locks[i].xPos, &map_locks[i].yPos, &map_locks[i].level, &north, &west, &east, &south);
        map_locks[i].side = (north << 0) + (west << 1) + (east << 2) + (south << 3);
    }
    fclose(file);
}

void load_world(const char* worldName)
{
    load_map(worldName);
    load_collision(worldName);
    load_player(worldName);
    load_path(worldName);
    load_level(worldName);
    load_lock(worldName);
}

void save_world(const char* worldName)
{
    save_map(worldName);
    save_collision(worldName);
    //load_player(worldName);
    //load_path(worldName);
    //load_level(worldName);
    //load_lock(worldName);
}
