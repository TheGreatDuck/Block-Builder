#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"
#include "blockAlchemy.h"
#include "gameLoop.h"
#include "controls.h"
#include "player.h"
#include "camera.h"
#include "loadLevel.h"
#include "entity.h"

int room;
int spr_selectBlock;

#ifdef EDITOR_DLL
entity entityList[10];
entityType entityTypeList[1];
void render();
extern int renderedBlockGraph_ID[640*512];
extern vector cam_m[4];
#endif

#ifdef RELEASE_DLL
entity entityList[1];
entityType entityTypeList[1];
#endif

int entityID;

GMEXPORT double gameLoopInit()
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

    load_level((char*)"C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files", (char*)"YggdrasilQuest", (char*)"1");

    sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\block.png", 1, 0, 0, 0, 0, &blkGph->spr_blockTexture);
    sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);

    sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\selectBlock.png", numberOfBlocks_3D, 0, 0, 0, 0, &spr_selectBlock);

    //sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\block.png", 1, 0, 0, 0, 0, &player.texBody);
    //sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);

    initGameControl();

    d3d_start();
    d3d_set_fog(1,0,600,1000);
    //draw_set_color(c_white);
    //texture_set_interpolation(0);
    //d3d_set_culling(true);
    d3d_set_lighting(0);

    entity_callback_data ecd;
    ecd.numberOfBlocks3D = numberOfBlocks_3D;

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

    instantiate_entity(&ecd);
    entityTypeList[0].createEvent = player3D_createEvent;
    entityTypeList[0].stepEvent   = player3D_stepEvent;
    entityTypeList[0].drawEvent   = player3D_drawEvent;

    #ifdef EDITOR_DLL
    for (int i = 0; i < 10; i++)
    {
        entityList[i].currentSpace = i;
        entityList[i].sideFacing   = 2;
        entityList[i].typeID       = 0;
        entityList[i].internalData = entityTypeList[entityList[i].typeID].createEvent();
        blkGph->blockGraph[i].entityID = i;
    }
    #endif

    #ifdef RELEASE_DLL
    entityList[0].currentSpace = 0;
    entityList[0].sideFacing   = 2;
    entityList[0].typeID       = 0;
    entityList[0].internalData = entityTypeList[entityList[0].typeID].createEvent();
    blkGph->blockGraph[0].entityID = 0;
    #endif

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

    for (int i = 0; i < 10; i++)
    {
        entityList[i].position = blkGph->blockGraph[entityList[i].currentSpace].position;
    }
    #endif

    #ifdef RELEASE_DLL
    blockGraph_updateBlockGraphWithList();
    entityTypeList[entityList[0].typeID].stepEvent(&entityList[0], gameControl);
    #endif

    return 1.0;
}

GMEXPORT double gameLoopDraw()
{
    camera_drawEvent();
    blockGraph_drawEvent();
    #ifdef EDITOR_DLL
    for (int i = 0; i < 10; i++)
    {
        entityTypeList[entityList[i].typeID].drawEvent(&entityList[i]);
    }
    #endif

    #ifdef RELEASE_DLL
    entityTypeList[entityList[0].typeID].drawEvent(&entityList[0]);
    #endif

    return 1.0;
}
