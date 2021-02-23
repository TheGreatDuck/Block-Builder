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
#include "rm_world.hpp"
#include "rm_world_editor_select.hpp"
#include "rm_world_editor.hpp"
#include "rm_configure_control.hpp"

#define MAIN_MENU_ROOM 0
#define WORLD_SELECT_ROOM 1
#define WORLD_ROOM 2
#define LEVEL_ROOM 3
#define WORLD_EDITOR_SELECT_ROOM 4
#define WORLD_EDITOR_ROOM 5
#define LEVEL_EDITOR_ROOM 6
#define LEVEL_EDITOR_GEO_ROOM 7
#define CONFIGURE_CONTROL 8

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
unsigned int worldCount;
char** worldName;
unsigned int worldID;

void load_entityList(const char* levelLoading)
{
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName[worldID]) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\entityList.el"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName[worldID]) + strlen("\\Level ") + strlen(levelLoading) + strlen("\\entityList.el"));
    strcat(fileName,"Worlds\\");
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
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\") + strlen(typeName) + strlen(".dll"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\") + strlen(typeName) + strlen(".dll"));
    strcat(fileName,"Worlds\\");
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
    char* fileName = (char*)alloca((strlen("Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\entityTypeList.etl"))*sizeof(char));
    memset(fileName, 0, strlen("Worlds\\") + strlen(worldName[loadedWorld]) + strlen("\\EntityData\\entityTypeList.etl"));
    strcat(fileName,"Worlds\\");
    strcat(fileName,worldName[loadedWorld]);
    strcat(fileName,"\\EntityData\\entityTypeList.etl");
    FILE* file = fopen(fileName, "r");

    fscanf(file, "%u\n", &(entityTypeCount[loadedWorld]));

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
    FILE* file = fopen("Worlds\\worldName.txt", "r");

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

GMEXPORT double gameLoopInit(char* external_program_directory)
{
    //#ifdef EDITOR_DLL
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
    //#endif

    load_worldName();

    for (unsigned int id = 0; id < worldCount; id++)
    {
        blockGraph_initBlockModelAssets(worldName[id]);
    }

    spr_selectBlock = sprite_add("selectBlock.png", numberOfBlocks_3D, 0, 0, 0, 0);
    spr_mapIcon = sprite_add("mapIcons.png", 7, 0, 0, 0, 0);
    spr_mapPlayer = sprite_add("spr_mapLevelComplete.png", 1, 0, 0, 0, 0);

    spr_mapWestMapPath = sprite_add("spr_mapWestMapPath.png", 1, 0, 0, 0, 0);
    spr_mapEastMapPath = sprite_add("spr_mapEastMapPath.png", 1, 0, 0, 0, 0);
    spr_mapNorthMapPath = sprite_add("spr_mapNorthMapPath.png", 1, 0, 0, 0, 0);
    spr_mapSouthMapPath = sprite_add("spr_mapSouthMapPath.png", 1, 0, 0, 0, 0);
    spr_mapLock = sprite_add("spr_mapLock.png", 1, 0, 0, 0, 0);

    #if 0
    sprite_add("block.png", 1, 0, 0, 0, 0, &player.texBody);
    sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);
    #endif

    initGameControl();
    for (unsigned int id = 0; id < worldCount; id++)
        load_entityTypeList(id);
    map_player_y = 0;
    return 1.0;
}

GMEXPORT double gameLoopBeginStep()
{
    return 1.0;
}

GMEXPORT double gameLoopStep()
{
    if (room == CONFIGURE_CONTROL)
        configureControlBeginStep();

    updateGameControl();

    if (room == MAIN_MENU_ROOM)
        mainMenuStep();
    else if (room == WORLD_SELECT_ROOM)
        worldSelectStep();
    else if (room == WORLD_EDITOR_SELECT_ROOM)
        worldEditorSelectStep();
    else if (room == WORLD_ROOM)
        worldStep();
    else if (room == WORLD_EDITOR_ROOM)
        worldEditorStep();
    else if (room == LEVEL_ROOM)
    {
        if (entityList[entityID].turnActive == 1)
            entityTypeList[worldID][entityList[entityID].typeID].stepEvent(&entityList[entityID], gameControl);
        else
        {
            entityID++;
            if (entityID == entityCount)
            {
                entityID = 0;
                blockGraph_updateBlockGraphWithList();
            }
            entityList[entityID].turnActive = 1;
        }
    } else if (room == LEVEL_EDITOR_ROOM)
    {
        if (gameControl.control_moveUp.gameControlPressed)
            cam_m[3].y -= 1;
        if (gameControl.control_moveRight.gameControlPressed)
            cam_m[3].x += 1;
        if (gameControl.control_moveDown.gameControlPressed)
            cam_m[3].y += 1;
        if (gameControl.control_moveLeft.gameControlPressed)
            cam_m[3].x -= 1;
        if (gameControl.control_blockRight.gameControlPressed)
            cam_m[3].z -= 1;
        if (gameControl.control_blockLeft.gameControlPressed)
            cam_m[3].z += 1;

        render();

        int x = *mouse_x;
        int y = *mouse_y;

        if (mouse_check_button_pressed(1))
        {
            if (y < 512 && x < 640 && y >= 0 && x >= 0)
            {
                if (renderedBlockGraph_ID[y*640 + x] != -1)
                    entityID = blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].entityID;
                else
                    entityID = -1;
            } else
                entityID = -1;
        }

        if (mouse_check_button(1) && entityID != -1)
        {
            if (y < 512 && x < 640 && y >= 0 && x >= 0)
            {
                if (renderedBlockGraph_ID[y*640 + x] != -1)
                {
                    if (blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].entityID == -1)
                    {
                        blkGph->blockGraph[entityList[entityID].currentSpace].entityID = -1;
                        blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].entityID  = entityID;
                        entityList[entityID].currentSpace = renderedBlockGraph_ID[y*640 + x];
                    }
                }
            }
        }

        if (mouse_check_button_released(1))
            entityID = -1;
    } else if (room == LEVEL_EDITOR_GEO_ROOM)
    {
        if (entityID == -1)
        {
            if (gameControl.control_moveUp.gameControlPressed)
                cam_m[3].y -= 1;
            if (gameControl.control_moveRight.gameControlPressed)
                cam_m[3].x += 1;
            if (gameControl.control_moveDown.gameControlPressed)
                cam_m[3].y += 1;
            if (gameControl.control_moveLeft.gameControlPressed)
                cam_m[3].x -= 1;
            if (gameControl.control_blockRight.gameControlPressed)
                cam_m[3].z -= 1;
            if (gameControl.control_blockLeft.gameControlPressed)
                cam_m[3].z += 1;
        } else
        {
            block3D block = blkGph->blockGraph[entityID];
            if (gameControl.control_moveUp.gameControlPressed)
                entityID = blockGraph_addBlock(block.v[0]+(block.v[1] - block.v[0]),
                                               block.v[1]+(block.v[1] - block.v[0]),
                                               block.v[2]+(block.v[1] - block.v[0]),
                                               block.v[3]+(block.v[1] - block.v[0]));
            if (gameControl.control_moveRight.gameControlPressed)
                entityID = blockGraph_addBlock(block.v[0]+(block.v[0] - block.v[2]),
                                               block.v[1]+(block.v[0] - block.v[2]),
                                               block.v[2]+(block.v[0] - block.v[2]),
                                               block.v[3]+(block.v[0] - block.v[2]));
            if (gameControl.control_moveDown.gameControlPressed)
                entityID = blockGraph_addBlock(block.v[0]+(block.v[0] - block.v[1]),
                                               block.v[1]+(block.v[0] - block.v[1]),
                                               block.v[2]+(block.v[0] - block.v[1]),
                                               block.v[3]+(block.v[0] - block.v[1]));
            if (gameControl.control_moveLeft.gameControlPressed)
                entityID = blockGraph_addBlock(block.v[0]+(block.v[2] - block.v[0]),
                                               block.v[1]+(block.v[2] - block.v[0]),
                                               block.v[2]+(block.v[2] - block.v[0]),
                                               block.v[3]+(block.v[2] - block.v[0]));
        }

        render();

        int x = *mouse_x;
        int y = *mouse_y;

        if (mouse_check_button_pressed(1))
        {
            if (y < 512 && x < 640 && y >= 0 && x >= 0)
                entityID = renderedBlockGraph_ID[y*640 + x];
        }

        if (mouse_check_button_pressed(2))
        {
            if (y < 512 && x < 640 && y >= 0 && x >= 0)
            {
                if (renderedBlockGraph_ID[y*640 + x] != -1)
                {
                    blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].type = (blkGph->blockGraph[renderedBlockGraph_ID[y*640 + x]].type+1) % (int)numberOfBlocks_3D;
                    blockGraph_create3DModel();
                }
            }
        }
    } else if (room == CONFIGURE_CONTROL)
        configureControlStep();

    return 1.0;
}

GMEXPORT double gameLoopDraw()
{
    if (room == MAIN_MENU_ROOM)
        mainMenuDraw();
    else if (room == WORLD_SELECT_ROOM)
        worldSelectDraw();
    else if (room == WORLD_EDITOR_SELECT_ROOM)
        worldEditorSelectDraw();
    else if (room == WORLD_ROOM)
        worldDraw();
    else if (room == WORLD_EDITOR_ROOM)
        worldEditorDraw();
    else if (room == LEVEL_ROOM)
    {
        camera_drawEvent();
        blockGraph_drawEvent();
        for (unsigned int i = 0; i < entityCount; i++)
            entityTypeList[worldID][entityList[i].typeID].drawEvent(&entityList[i]);
    } else if (room == LEVEL_EDITOR_GEO_ROOM)
    {
        cameraEditor_drawEvent();
        blockGraph_drawEvent();
    } else if (room == LEVEL_EDITOR_ROOM)
    {
        cameraEditor_drawEvent();
        blockGraph_drawEvent();
        for (unsigned int i = 0; i < entityCount; i++)
            entityTypeList[worldID][entityList[i].typeID].drawEvent(&entityList[i]);
    } else if (room == CONFIGURE_CONTROL)
        configureControlDraw();

    return 1.0;
}
