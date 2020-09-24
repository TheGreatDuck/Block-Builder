#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include <windows.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"
#include "blockAlchemy.h"
#include "gameLoop.h"
#include "controls.h"
#include "camera.h"
#include "loadLevel.h"
#include "entity.h"

int room;
int spr_selectBlock;

#ifdef EDITOR_DLL
void render();
extern int renderedBlockGraph_ID[640*512];
extern vector cam_m[4];
#endif

entity* entityList;
entityType* entityTypeList;
unsigned int entityTypeCount;
unsigned int entityCount;
int entityID;

static void load_entityList(const char* program_directory, const char* worldName, const char* levelLoading)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\entityList.el")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\entityList.el"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
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
        entityList[i].internalData = entityTypeList[entityList[i].typeID].createEvent();
        blkGph->blockGraph[entityList[i].currentSpace].entityID = i;
    }
}

static void load_entityType(const char* program_directory, const char* worldName, const char* typeName, unsigned entityTypeID)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\EntityData\\") + strlen(typeName) + strlen(".dll")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\EntityData\\") + strlen(typeName) + strlen(".dll"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\EntityData\\");
    strcat(fileName,typeName);
    strcat(fileName,".dll");

    HINSTANCE dllHandle = LoadLibrary(TEXT(fileName));

    entityTypeList[entityTypeID].createEvent  = (CREATE_EVENT) GetProcAddress(dllHandle, "createEvent");
    entityTypeList[entityTypeID].stepEvent    = (STEP_EVENT) GetProcAddress(dllHandle, "stepEvent");
    entityTypeList[entityTypeID].drawEvent    = (DRAW_EVENT) GetProcAddress(dllHandle, "drawEvent");
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

static void load_entityTypeList(const char* program_directory, const char* worldName)
{
    char fileName[strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\EntityData\\entityTypeList.etl")];
    memset(fileName, 0, strlen(program_directory) + strlen("\\Worlds\\") + strlen(worldName) + strlen("\\EntityData\\entityTypeList.etl"));
    strcat(fileName,program_directory);
    strcat(fileName,"\\Worlds\\");
    strcat(fileName,worldName);
    strcat(fileName,"\\EntityData\\entityTypeList.etl");
    FILE* file = fopen(fileName, "r");

    free(entityTypeList);

    fscanf(file, "%u\n", &entityTypeCount);

    entityTypeList = (entityType*)malloc(sizeof(entityType)*entityTypeCount);

    for (int i = 0; i < entityTypeCount; i += 1)
    {
        char typeName[1000];
        fscanf(file, "%[^\n]", typeName);
        fscanf(file, "\n");
        load_entityType(program_directory, worldName, typeName, i);
    }
}

GMEXPORT double gameLoopInit(char* program_directory)
{
    #ifdef EDITOR_DLL
    cam_m[3].x = 0;
    cam_m[3].y = 0;
    cam_m[3].z = 100;

    cam_m[2].x = 0;
    cam_m[2].y = 1;
    cam_m[2].z = 0;

    cam_m[1].x = 0;
    cam_m[1].y = 0;
    cam_m[1].z = 1;

    cam_m[0].x = -1;
    cam_m[0].y =  0;
    cam_m[0].z =  0;
    #endif

    blockGraph_initBlockModelAssets(program_directory, (char*)"YggdrasilQuest");
    load_level(program_directory, (char*)"YggdrasilQuest", (char*)"1");

    sprite_add("block.png", 1, 0, 0, 0, 0, &blkGph->spr_blockTexture);
    sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);

    sprite_add("selectBlock.png", numberOfBlocks_3D, 0, 0, 0, 0, &spr_selectBlock);

    //sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\block.png", 1, 0, 0, 0, 0, &player.texBody);
    //sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);

    initGameControl();

    d3d_start();
    d3d_set_fog(1,0,600,1000);
    //draw_set_color(c_white);
    //texture_set_interpolation(0);
    //d3d_set_culling(true);
    d3d_set_lighting(0);

    load_entityTypeList(program_directory, (char*)"YggdrasilQuest");
    load_entityList(program_directory, (char*)"YggdrasilQuest", (char*)"1");
    entityList[entityID].turnActive = 1;
    return 1.0;
}

GMEXPORT double gameLoopStep(double double_x, double double_y)
{
    #ifdef EDITOR_DLL
    if (gameControl.control_moveUp.gameControlPressed)
    {
        cam_m[3].y -= 1;
    }

    if (gameControl.control_moveRight.gameControlPressed)
    {
        cam_m[3].x += 1;
    }

    if (gameControl.control_moveDown.gameControlPressed)
    {
        cam_m[3].y += 1;
    }

    if (gameControl.control_moveLeft.gameControlPressed)
    {
        cam_m[3].x -= 1;
    }

    if (gameControl.control_blockRight.gameControlPressed)
    {
        //cam_m[3].z -= 1;
        entityID += 9;
        entityID = entityID % 10;
    }

    if (gameControl.control_blockLeft.gameControlPressed)
    {
        //cam_m[3].z += 1;
        entityID++;
        entityID = entityID % 10;
    }

    render();

    int x = double_x;
    int y = double_y;

    if (y < 512 && x < 640 && y >= 0 && x >= 0)
    {
        if (renderedBlockGraph_ID[y*640 + x] != -1)
        {
            if (blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].entityID == entityID || blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].entityID == -1)
            {
                blkGph->blockGraph[entityList[entityID].currentSpace].entityID = -1;
                blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].entityID  = entityID;
                entityList[entityID].currentSpace = renderedBlockGraph_ID[y*640 + x];
            }
        }
    }
    #endif

    #ifdef RELEASE_DLL
    if (entityList[entityID].turnActive == 1)
    {
        entityTypeList[entityList[entityID].typeID].stepEvent(&entityList[entityID], gameControl);
    } else
    {
        entityID++;
        if (entityID == entityCount)
        {
            entityID = 0;
            blockGraph_updateBlockGraphWithList();
        }
        entityList[entityID].turnActive = 1;
    }
    #endif

    return 1.0;
}

GMEXPORT double gameLoopDraw()
{
    camera_drawEvent();
    blockGraph_drawEvent();
    for (int i = 0; i < entityCount; i++)
    {
        entityTypeList[entityList[i].typeID].drawEvent(&entityList[i]);
    }

    return 1.0;
}
