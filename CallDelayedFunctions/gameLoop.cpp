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

#define MAIN_MENU_ROOM 0
#define WORLD_SELECT_ROOM 1
#define WORLD_ROOM 2
#define LEVEL_ROOM 3
#define WORLD_EDITOR_SELECT_ROOM 4
#define WORLD_EDITOR_ROOM 5
#define LEVEL_EDITOR_ROOM 6

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

GMEXPORT double gameLoopInit(char* external_program_directory)
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

    program_directory = (char*)malloc(strlen(external_program_directory)*sizeof(char));
    strcpy(program_directory,external_program_directory);
    load_worldName();

    for (unsigned int id = 0; id < worldCount; id++)
    {
        blockGraph_initBlockModelAssets(program_directory, worldName[id]);
    }

    sprite_add("selectBlock.png", numberOfBlocks_3D, 0, 0, 0, 0, &spr_selectBlock);
    sprite_add("mapIcons.png", 7, 0, 0, 0, 0, &spr_mapIcon);
    sprite_add("spr_mapLevelComplete.png", 1, 0, 0, 0, 0, &spr_mapPlayer);

    sprite_add("spr_mapWestMapPath.png", 1, 0, 0, 0, 0, &spr_mapWestMapPath);
    sprite_add("spr_mapEastMapPath.png", 1, 0, 0, 0, 0, &spr_mapEastMapPath);
    sprite_add("spr_mapNorthMapPath.png", 1, 0, 0, 0, 0, &spr_mapNorthMapPath);
    sprite_add("spr_mapSouthMapPath.png", 1, 0, 0, 0, 0, &spr_mapSouthMapPath);
    sprite_add("spr_mapLock.png", 1, 0, 0, 0, 0, &spr_mapLock);

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
    if (room == MAIN_MENU_ROOM)
    {
        if (gameControl.control_moveUp.gameControlPressed)
        {
            if (map_player_y >= 1)
                map_player_y--;
        }

        if (gameControl.control_moveDown.gameControlPressed)
        {
            if (map_player_y < 2)
                map_player_y++;
        }

        if (gameControl.control_confirm.gameControlPressed)
        {
            if (map_player_y == 0)
                room = WORLD_SELECT_ROOM;
            if (map_player_y == 1)
                room = WORLD_EDITOR_SELECT_ROOM;
            if (map_player_y == 2)
                game_end();
        }
    } else if (room == WORLD_SELECT_ROOM)
    {
        if (gameControl.control_moveUp.gameControlPressed)
        {
            if (worldID >= 1)
                worldID--;
        }

        if (gameControl.control_moveDown.gameControlPressed)
        {
            if (worldID+1 < worldCount)
                worldID++;
        }

        if (gameControl.control_confirm.gameControlPressed)
        {
            room = WORLD_ROOM;
            load_world(program_directory, worldName[worldID]);
        }
    } else if (room == WORLD_EDITOR_SELECT_ROOM)
    {
        if (gameControl.control_moveUp.gameControlPressed)
        {
            if (worldID >= 1)
                worldID--;
        }

        if (gameControl.control_moveDown.gameControlPressed)
        {
            if (worldID+1 < worldCount)
                worldID++;
        }

        if (gameControl.control_confirm.gameControlPressed)
        {
            room = WORLD_EDITOR_ROOM;
            load_world(program_directory, worldName[worldID]);
        }
    } else if (room == WORLD_ROOM)
    {
        if (gameControl.control_moveUp.gameControlPressed)
        {
            if (map_player_y >= 1)
            {
                if (map_collision[map_width*(map_player_y-1) + map_player_x] == 0)
                    map_player_y--;
            }
        }

        if (gameControl.control_moveRight.gameControlPressed)
        {
            if (map_player_x + 1 < map_width)
            {
                if (map_collision[map_width*map_player_y + (map_player_x+1)] == 0)
                    map_player_x++;
            }
        }

        if (gameControl.control_moveDown.gameControlPressed)
        {
            if (map_player_y + 1 < map_height)
            {
                if (map_collision[map_width*(map_player_y+1) + map_player_x] == 0)
                    map_player_y++;
            }
        }

        if (gameControl.control_moveLeft.gameControlPressed)
        {
            if (map_player_x >= 1)
            {
                if (map_collision[map_width*map_player_y + (map_player_x-1)] == 0)
                    map_player_x--;
            }
        }

        if (gameControl.control_confirm.gameControlPressed)
        {
            for (unsigned int levelID = 0; levelID < numberOfLevels; levelID++)
            {
                if (map_levels[levelID].xPos == map_player_x && map_levels[levelID].yPos == map_player_y)
                {
                    room = LEVEL_ROOM;

                    char levelNumber[2];
                    levelNumber[0] = map_levels[levelID].level+'0';
                    levelNumber[1] = 0;

                    load_level(program_directory, worldName[worldID], levelNumber);

                    sprite_add("block.png", 1, 0, 0, 0, 0, &blkGph->spr_blockTexture);
                    sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);

                    d3d_start();
                    d3d_set_fog(1,0,600,1000);
                    #if 0
                    draw_set_color(c_white);
                    texture_set_interpolation(0);
                    d3d_set_culling(true);
                    #endif
                    d3d_set_lighting(0);

                    load_entityList(levelNumber);
                    entityList[entityID].turnActive = 1;
                }
            }
        }
    } else if (room == WORLD_EDITOR_ROOM)
    {
        if (gameControl.control_moveUp.gameControlPressed && map_player_y >= 1)
            map_player_y--;
        if (gameControl.control_moveRight.gameControlPressed && map_player_x + 1 < map_width)
            map_player_x++;
        if (gameControl.control_moveDown.gameControlPressed && map_player_y + 1 < map_height)
            map_player_y++;
        if (gameControl.control_moveLeft.gameControlPressed && map_player_x >= 1)
            map_player_x--;

        if (gameControl.control_confirm.gameControlPressed)
        {
            if (worldEditorMode == 0)
                map_icons[map_width*map_player_y + map_player_x] = (map_icons[map_width*map_player_y + map_player_x]+1) % 7;
            if (worldEditorMode == 1)
                map_collision[map_width*map_player_y + map_player_x] = (map_collision[map_width*map_player_y + map_player_x]+1) % 2;
            if (worldEditorMode == 2)
                map_path[map_width*map_player_y + map_player_x] = (map_path[map_width*map_player_y + map_player_x]+1) % 16;
        }

        if (gameControl.control_blockLeft.gameControlPressed)
            worldEditorMode = (worldEditorMode+1) % 3;
        if (gameControl.control_blockRight.gameControlPressed)
            worldEditorMode = (worldEditorMode+1) % 3;
        if (gameControl.control_cancel.gameControlPressed)
            save_world(program_directory, worldName[worldID]);
    } else if (room == LEVEL_ROOM)
    {
        if (entityList[entityID].turnActive == 1)
        {
            entityTypeList[worldID][entityList[entityID].typeID].stepEvent(&entityList[entityID], gameControl);
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

        // TEMP FIX ONLY!!!!!!!!!!!!!!!!
        double double_x = 0;
        double double_y = 0;

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
    }

    return 1.0;
}

GMEXPORT double gameLoopDraw()
{
    if (room == MAIN_MENU_ROOM)
    {
        draw_text(100, 100, "World select");
        draw_text(100, 132, "Editor");
        draw_text(100, 164, "Quit Game");
        draw_sprite(&spr_mapPlayer,0,68,32*map_player_y + 100 - 4);
    } else if (room == WORLD_SELECT_ROOM)
    {
        for (unsigned int id = 0; id < worldCount; id++)
            draw_text(100, 100+id*32, worldName[id]);
        draw_sprite(&spr_mapPlayer,0,68,32*worldID + 96);
    } else if (room == WORLD_EDITOR_SELECT_ROOM)
    {
        for (unsigned int id = 0; id < worldCount; id++)
            draw_text(100, 100+id*32, worldName[id]);
        draw_sprite(&spr_mapPlayer,0,68,32*worldID + 96);
    } else if (room == WORLD_ROOM)
    {
        unsigned int x_min = 0;
        unsigned int y_min = 0;
        if (map_player_x >= 10)
            x_min = map_player_x - 10;
        if (map_player_y >= 10)
            y_min = map_player_y - 10;
        unsigned int x_max = x_min+20;
        unsigned int y_max = y_min+20;

        for (unsigned int i = y_min; i < y_max; i++)
        {
            for (unsigned int j = x_min; j < x_max; j++)
            {
                draw_sprite(&spr_mapIcon,map_icons[map_width*i + j],32*(j-x_min),32*(i-y_min));
                if (map_path[map_width*i + j] & (1 << 0))
                    draw_sprite(&spr_mapWestMapPath,0,32*(j-x_min),32*(i-y_min));
                if (map_path[map_width*i + j] & (1 << 1))
                    draw_sprite(&spr_mapEastMapPath,0,32*(j-x_min),32*(i-y_min));
                if (map_path[map_width*i + j] & (1 << 2))
                    draw_sprite(&spr_mapNorthMapPath,0,32*(j-x_min),32*(i-y_min));
                if (map_path[map_width*i + j] & (1 << 3))
                    draw_sprite(&spr_mapSouthMapPath,0,32*(j-x_min),32*(i-y_min));
            }
        }

        for (unsigned int i = 0; i < numberOfLocks; i++)
        {
            if (!(map_locks[i].side & map_levelCompletion[map_locks[i].level]))
                draw_sprite(&spr_mapLock,0,32*(map_locks[i].xPos-x_min),32*(map_locks[i].yPos-y_min));
        }

        for (unsigned int i = 0; i < numberOfLevels; i++)
            draw_sprite(&spr_mapPlayer,0,32*(map_levels[i].xPos-x_min),32*(map_levels[i].yPos-y_min));

        draw_sprite(&spr_mapPlayer,0,32*(map_player_x-x_min),32*(map_player_y-y_min));
    } else if (room == WORLD_EDITOR_ROOM)
    {
        unsigned int x_min = 0;
        unsigned int y_min = 0;
        if (map_player_x >= 10)
            x_min = map_player_x - 10;
        if (map_player_y >= 10)
            y_min = map_player_y - 10;
        unsigned int x_max = x_min+20;
        unsigned int y_max = y_min+20;

        for (unsigned int i = y_min; i < y_max; i++)
        {
            for (unsigned int j = x_min; j < x_max; j++)
            {
                if (worldEditorMode == 0)
                    draw_sprite(&spr_mapIcon,map_icons[map_width*i + j],32*(j-x_min),32*(i-y_min));
                if (worldEditorMode == 1)
                    draw_sprite(&spr_mapIcon,map_collision[map_width*i + j],32*(j-x_min),32*(i-y_min));
                if (worldEditorMode == 2)
                    draw_sprite(&spr_mapIcon,map_icons[map_width*i + j],32*(j-x_min),32*(i-y_min));

                if (map_path[map_width*i + j] & (1 << 0))
                    draw_sprite(&spr_mapWestMapPath,0,32*(j-x_min),32*(i-y_min));
                if (map_path[map_width*i + j] & (1 << 1))
                    draw_sprite(&spr_mapEastMapPath,0,32*(j-x_min),32*(i-y_min));
                if (map_path[map_width*i + j] & (1 << 2))
                    draw_sprite(&spr_mapNorthMapPath,0,32*(j-x_min),32*(i-y_min));
                if (map_path[map_width*i + j] & (1 << 3))
                    draw_sprite(&spr_mapSouthMapPath,0,32*(j-x_min),32*(i-y_min));
            }
        }

        for (unsigned int i = 0; i < numberOfLocks; i++)
        {
            if (!(map_locks[i].side & map_levelCompletion[map_locks[i].level]))
                draw_sprite(&spr_mapLock,0,32*(map_locks[i].xPos-x_min),32*(map_locks[i].yPos-y_min));
        }

        for (unsigned int i = 0; i < numberOfLevels; i++)
            draw_sprite(&spr_mapPlayer,0,32*(map_levels[i].xPos-x_min),32*(map_levels[i].yPos-y_min));

        draw_sprite(&spr_mapPlayer,0,32*(map_player_x-x_min),32*(map_player_y-y_min));
    } else if (room == LEVEL_ROOM)
    {
        camera_drawEvent();
        blockGraph_drawEvent();
        for (unsigned int i = 0; i < entityCount; i++)
            entityTypeList[worldID][entityList[i].typeID].drawEvent(&entityList[i]);
    } else if (room == LEVEL_EDITOR_ROOM)
    {
        cameraEditor_drawEvent();
        blockGraph_drawEvent();
        for (unsigned int i = 0; i < entityCount; i++)
            entityTypeList[worldID][entityList[i].typeID].drawEvent(&entityList[i]);
    }

    return 1.0;
}
