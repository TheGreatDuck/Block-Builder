#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include <windows.h>
#include <malloc.h>
#include "gameMakerLibrary.hpp"
#include "blockGraph.hpp"
#include "blockAlchemy.hpp"
#include "gameLoop.hpp"
#include "controls.hpp"
#include "camera.hpp"
#include "worldMap.hpp"
#include "loadLevel.hpp"
#include "entity.hpp"
#include "hand_render.hpp"
#include "rm_main_menu.hpp"
#include "rm_world_select.hpp"
#include "rm_world_editor_select.hpp"
#include "rm_configure_control.hpp"

int room;
int spr_selectBlock;
int spr_mapIcon;
int spr_mapPlayer;
int spr_mapWestMapPath;
int spr_mapEastMapPath;
int spr_mapNorthMapPath;
int spr_mapSouthMapPath;
int spr_mapLock;
entity* entityList;
entityType** entityTypeList;
unsigned int* entityTypeCount;
unsigned int entityCount;
int entityID;
char* program_directory;
unsigned int worldCount;
char** worldName;
unsigned int worldID;
unsigned int worldEditorMode;

static void load_entityList(const char* levelLoading)
{
    char* fileName = (char*)alloca((strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName[worldID]) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\entityList.el"))*sizeof(char));
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName[worldID]) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\entityList.el"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName[worldID]);
    strcat(fileName,"\\Level ");
    strcat(fileName,levelLoading);
    strcat(fileName,"\\entityList.el");
    FILE* file = fopen(fileName, "r");

    free(entityList);

    fscanf(file, "%u\n", &entityCount);

    entityList = (entity*)malloc(sizeof(entity)*entityCount);
    memset(entityList, 0, sizeof(entity)*entityCount);

    for (unsigned int i = 0; i < entityCount; i += 1)
    {
        fscanf(file, "%u %u %u\n", &entityList[i].typeID, &entityList[i].currentSpace, &entityList[i].sideFacing);
        entityList[i].internalData = entityTypeList[worldID][entityList[i].typeID].createEvent();
        blkGph->blockGraph[entityList[i].currentSpace].entityID = i;
        entityList[i].entityID = i;
    }
}

static void load_entityType(const char* typeName, unsigned int entityTypeID, unsigned int loadedWorld)
{
    char* fileName = (char*)alloca((strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\") + strlen(typeName) + strlen(".dll"))*sizeof(char));
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\") + strlen(typeName) + strlen(".dll"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName[loadedWorld]);
    strcat(fileName,"\\EntityData\\");
    strcat(fileName,typeName);
    strcat(fileName,".dll");

    HINSTANCE dllHandle = LoadLibrary(TEXT(fileName));

    entityTypeList[loadedWorld][entityTypeID].createEvent  = (CREATE_EVENT) GetProcAddress(dllHandle, "createEvent");
    entityTypeList[loadedWorld][entityTypeID].stepEvent    = (STEP_EVENT) GetProcAddress(dllHandle, "stepEvent");
    entityTypeList[loadedWorld][entityTypeID].drawEvent    = (DRAW_EVENT) GetProcAddress(dllHandle, "drawEvent");
    INSTANTIATE_ENTITY instantiate_entity_DLL = (INSTANTIATE_ENTITY) GetProcAddress(dllHandle, "instantiate_entity");

    entity_callback_data ecd;
    ecd.numberOfBlocks3D = numberOfBlocks_3D;
    ecd.blkGph           = blkGph;

    ecd.d3d_draw_block     = d3d_draw_block;
    ecd.d3d_draw_cylinder  = d3d_draw_cylinder;
    ecd.d3d_draw_cone      = d3d_draw_cone;
    ecd.d3d_draw_ellipsoid = d3d_draw_ellipsoid;
    ecd.d3d_draw_wall      = d3d_draw_wall;
    ecd.d3d_draw_floor     = d3d_draw_floor;

    ecd.d3d_transform_set_identity      = d3d_transform_set_identity;
    ecd.d3d_transform_add_rotation_x    = d3d_transform_add_rotation_x;
    ecd.d3d_transform_add_rotation_y    = d3d_transform_add_rotation_y;
    ecd.d3d_transform_add_rotation_z    = d3d_transform_add_rotation_z;
    ecd.d3d_transform_add_translation   = d3d_transform_add_translation;
    ecd.d3d_transform_add_rotation_axis = d3d_transform_add_rotation_axis;
    ecd.d3d_transform_add_scaling       = d3d_transform_add_scaling;

    ecd.sprite_add         = sprite_add;
    ecd.sprite_get_texture = sprite_get_texture;

    ecd.d3d_primitive_begin       = d3d_primitive_begin;
    ecd.d3d_vertex                = d3d_vertex;
    ecd.d3d_vertex_color          = d3d_vertex_color;
    ecd.d3d_primitive_end         = d3d_primitive_end;
    ecd.d3d_model_draw            = d3d_model_draw;
    ecd.d3d_model_create          = d3d_model_create;
    ecd.d3d_model_load            = d3d_model_load;
    ecd.d3d_model_primitive_begin = d3d_model_primitive_begin;
    ecd.d3d_model_vertex_texture  = d3d_model_vertex_texture;
    ecd.d3d_model_primitive_end   = d3d_model_primitive_end;
    ecd.d3d_model_destroy         = d3d_model_destroy;

    ecd.d3d_transform_add_block_matrix = d3d_transform_add_block_matrix;

    instantiate_entity_DLL(&ecd);
}

static void load_entityTypeList(unsigned int loadedWorld)
{
    char* fileName = (char*)alloca((strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\entityTypeList.etl"))*sizeof(char));
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\entityTypeList.etl"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName[loadedWorld]);
    strcat(fileName,"\\EntityData\\entityTypeList.etl");
    FILE* file = fopen(fileName, "r");

    free(entityTypeList);

    fscanf(file, "%u\n", &entityTypeCount[loadedWorld]);

    entityTypeList[loadedWorld] = (entityType*)malloc(sizeof(entityType)*entityTypeCount[loadedWorld]);

    for (unsigned int i = 0; i < entityTypeCount[loadedWorld]; i += 1)
    {
        char typeName[1000];
        fscanf(file, "%[^\n]", typeName);
        fscanf(file, "\n");
        load_entityType(typeName, i, loadedWorld);
    }
}

static void load_worldName()
{
    char* fileName = (char*)alloca((strlen(program_directory) + strlen("\\Worlds\\worldName.txt"))*sizeof(char));
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\worldName.txt"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\worldName.txt");
    FILE* file = fopen(fileName, "r");

    if (worldName)
    {
        for (unsigned int i = 0; i < worldCount; i += 1)
            free(worldName[i]);
    }

    fscanf(file, "%u\n", &worldCount);
    free(worldName);
    worldName = (char**)malloc(worldCount*sizeof(char*));
    entityTypeList = (entityType**)malloc(worldCount*sizeof(entityType*));
    entityTypeCount = (unsigned int*)malloc(worldCount*sizeof(unsigned int));

    for (unsigned int i = 0; i < worldCount; i += 1)
    {
        worldName[i] = (char*)malloc(1000*sizeof(char));
        memset(worldName[i], 0, 1000*sizeof(char));
        fscanf(file, "%[^\n]", worldName[i]);
        fscanf(file, "\n");
    }
}
