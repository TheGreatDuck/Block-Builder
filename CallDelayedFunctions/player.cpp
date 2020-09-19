#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "blockGraph.h"

int numberOfBlocks_3D;

void (*d3d_draw_block)(double, double, double, double, double, double, int*, int, int);
void (*d3d_draw_cylinder)(double, double, double, double, double, double, int*, int, int, int, int);
void (*d3d_draw_cone)(double, double, double, double, double, double, int*, int, int, int, int);
void (*d3d_draw_ellipsoid)(double, double, double, double, double, double, int*, int, int, int);
void (*d3d_draw_wall)(double, double, double, double, double, double, int*, int, int);
void (*d3d_draw_floor)(double, double, double, double, double, double, int*, int, int);

void (*d3d_transform_set_identity)();
void (*d3d_transform_add_rotation_x)(double direction);
void (*d3d_transform_add_rotation_y)(double direction);
void (*d3d_transform_add_rotation_z)(double direction);
void (*d3d_transform_add_translation)(double x, double y, double z);
void (*d3d_transform_add_rotation_axis)(double xa, double ya, double za,double angle);
void (*d3d_transform_add_scaling)(double xs, double ys, double zs);

void (*sprite_add)(const char* fname, double imgnumb, double removeback, double smooth, double xorig, double yorig, int* ind);
void (*sprite_get_texture)(int* spr, double subimg, int* returnValue);

void (*d3d_primitive_begin)(double);
void (*d3d_vertex)(double x, double y, double z);
void (*d3d_vertex_color)(double x, double y, double z, double col, double alpha);
void (*d3d_primitive_end)();
void (*d3d_model_draw)(int* ind, double x, double y, double z, int* texid);
void (*d3d_model_create)(int* ind);
void (*d3d_model_load)(int* ind, const char* fname);
void (*d3d_model_primitive_begin)(int* ind, double kind);
void (*d3d_model_vertex_texture)(int* ind, double x, double y, double z, double xtex, double ytex);
void (*d3d_model_primitive_end)(int* ind);
void (*d3d_model_destroy)(double ind);

typedef struct control
{
    unsigned int gameControlPress;
    unsigned int gameControlPressed;
} control;

typedef struct controlSet
{
    control control_cancel;
    control control_confirm;
    control control_itemTwo;
    control control_itemOne;
    control control_pause;
    control control_blockRight;
    control control_blockLeft;
    control control_moveLeft;
    control control_moveDown;
    control control_moveRight;
    control control_moveUp;
} controlSet;

#include "player.h"
#include "entity.h"

typedef struct player3D
{
    unsigned int type;
    unsigned int blockLeftPressed;
    unsigned int blockRightPressed;

    unsigned int sideFacingAfter;
    unsigned int moving;
    unsigned int motion;
    unsigned int movingSpace;
    unsigned int movingSideOne;
    unsigned int movingSideTwo;

    int texBody;
    int texEye;
} player3D;

void instantiate_entity(entity_callback_data* ecd)
{
    numberOfBlocks_3D = ecd->numberOfBlocks3D;

    d3d_draw_block     = ecd->d3d_draw_block;
    d3d_draw_cylinder  = ecd->d3d_draw_cylinder;
    d3d_draw_cone      = ecd->d3d_draw_cone;
    d3d_draw_ellipsoid = ecd->d3d_draw_ellipsoid;
    d3d_draw_wall      = ecd->d3d_draw_wall;
    d3d_draw_floor     = ecd->d3d_draw_floor;

    d3d_transform_set_identity      = ecd->d3d_transform_set_identity;
    d3d_transform_add_rotation_x    = ecd->d3d_transform_add_rotation_x;
    d3d_transform_add_rotation_y    = ecd->d3d_transform_add_rotation_y;
    d3d_transform_add_rotation_z    = ecd->d3d_transform_add_rotation_z;
    d3d_transform_add_translation   = ecd->d3d_transform_add_translation;
    d3d_transform_add_rotation_axis = ecd->d3d_transform_add_rotation_axis;
    d3d_transform_add_scaling       = ecd->d3d_transform_add_scaling;

    sprite_add         = ecd->sprite_add;
    sprite_get_texture = ecd->sprite_get_texture;

    d3d_primitive_begin       = ecd->d3d_primitive_begin;
    d3d_vertex                = ecd->d3d_vertex;
    d3d_vertex_color          = ecd->d3d_vertex_color;
    d3d_primitive_end         = ecd->d3d_primitive_end;
    d3d_model_draw            = ecd->d3d_model_draw;
    d3d_model_create          = ecd->d3d_model_create;
    d3d_model_load            = ecd->d3d_model_load;
    d3d_model_primitive_begin = ecd->d3d_model_primitive_begin;
    d3d_model_vertex_texture  = ecd->d3d_model_vertex_texture;
    d3d_model_primitive_end   = ecd->d3d_model_primitive_end;
    d3d_model_destroy         = ecd->d3d_model_destroy;
}

static void player3D_moveInDirection(int sideMoving, entity* e)
{
    player3D* player = (player3D*)e->internalData;
    int proposedSpace = blkGph->blockGraph[e->currentSpace].adj[sideMoving];

    if (proposedSpace != -1)
    {
        if ((blkGph->blockGraph[proposedSpace].type > 3 && blkGph->blockGraph[proposedSpace].type < 7) || (blkGph->blockGraph[proposedSpace].type > 7 && blkGph->blockGraph[proposedSpace].type < 11))
        {
            vector side = blkGph->blockGraph[e->currentSpace].side[sideMoving];

            player->movingSpace   = proposedSpace;
            player->movingSideOne = sideMoving;
            player->movingSideTwo = blkGph->blockGraph[e->currentSpace].adjSide[sideMoving];

            if ((e->sideFacing - sideMoving + 4) % 4 == 0)//up
            {
                player->sideFacingAfter = (player->movingSideTwo + 2) % 4;
            } else if ((e->sideFacing - sideMoving + 4) % 4 == 3)//left
            {
                player->sideFacingAfter = (player->movingSideTwo + 1) % 4;
            } else if ((e->sideFacing - sideMoving + 4) % 4 == 1)//right
            {
                player->sideFacingAfter = (player->movingSideTwo + 3) % 4;
            } else if ((e->sideFacing - sideMoving + 4) % 4 == 2)//down
            {
                player->sideFacingAfter = (player->movingSideTwo + 0) % 4;
            }
            player->moving = 1;
        } else
        {
            player->moving = 0;
        }
    } else
    {
        player->moving = 0;
    }
}

static void player3D_moveInDirectionWithoutCollision(int sideMoving, entity* e)
{
    player3D* player = (player3D*)e->internalData;
    int proposedSpace = blkGph->blockGraph[e->currentSpace].adj[sideMoving];

    if (proposedSpace != -1)
    {
        vector side = blkGph->blockGraph[e->currentSpace].side[sideMoving];

        player->movingSpace   = proposedSpace;
        player->movingSideOne = sideMoving;
        player->movingSideTwo = blkGph->blockGraph[e->currentSpace].adjSide[sideMoving];

        if ((e->sideFacing - sideMoving + 4) % 4 == 0)//up
        {
            player->sideFacingAfter = (player->movingSideTwo + 2) % 4;
        } else if ((e->sideFacing - sideMoving + 4) % 4 == 3)//left
        {
            player->sideFacingAfter = (player->movingSideTwo + 1) % 4;
        } else if ((e->sideFacing - sideMoving + 4) % 4 == 1)//right
        {
            player->sideFacingAfter = (player->movingSideTwo + 3) % 4;
        } else if ((e->sideFacing - sideMoving + 4) % 4 == 2)//down
        {
            player->sideFacingAfter = (player->movingSideTwo + 0) % 4;
        }
        player->moving = 1;
    } else
    {
        player->moving = 0;
    }
}

void player3D_drawEvent(entity* e)
{
    player3D* player = (player3D*)e->internalData;

    d3d_transform_set_identity();
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-1,-1,2,1,1,5,&player->texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player->texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_cylinder(-0.5,-0.5,0,0.5,0.5,2,&player->texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player->texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_cylinder(-0.5,-0.5,0,0.5,0.5,2,&player->texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,2.5);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player->texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,2.5);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_cylinder(-0.5,-0.5,-2,0.5,0.5,0,&player->texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,2.5);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player->texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,2.5);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_cylinder(-0.5,-0.5,-2,0.5,0.5,0,&player->texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(0,0,6);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-1,-1,-1,1,1,1,&player->texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(0,0,6);
    d3d_transform_add_translation(-0.25,1,0.25);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-0.125,-0.125,-0.125,0.125,0.125,0.125,&player->texEye,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(0,0,6);
    d3d_transform_add_translation(0.25,1,0.25);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing);
    d3d_transform_add_translation(e->position.x, e->position.y, e->position.z);
    d3d_draw_ellipsoid(-0.125,-0.125,-0.125,0.125,0.125,0.125,&player->texEye,2,1,60);

    d3d_transform_set_identity();
}

void player3D_stepEvent(entity* e, controlSet gameControl)
{
    player3D* player = (player3D*)e->internalData;
    e->position = blkGph->blockGraph[e->currentSpace].position;

    if (gameControl.control_moveUp.gameControlPressed)
    {
        if (player->moving == 0)
        {
            player3D_moveInDirection((e->sideFacing + 0) % 4, e);
        }
    }

    if (gameControl.control_moveRight.gameControlPressed)
    {
        if (player->moving == 0)
        {
            player3D_moveInDirection((e->sideFacing + 1) % 4, e);
        }
    }

    if (gameControl.control_moveDown.gameControlPressed)
    {
        if (player->moving == 0)
        {
            player3D_moveInDirection((e->sideFacing + 2) % 4, e);
        }
    }

    if (gameControl.control_moveLeft.gameControlPressed)
    {
        if (player->moving == 0)
        {
            player3D_moveInDirection((e->sideFacing + 3) % 4, e);
        }
    }

    if (gameControl.control_blockLeft.gameControlPress)
    {
        player->type = (player->type - 1 + (numberOfBlocks_3D - 1)) % (numberOfBlocks_3D-1);
        player->blockLeftPressed = 1;
    }

    if (gameControl.control_blockRight.gameControlPress)
    {
        player->type = (player->type + 1 + (numberOfBlocks_3D - 1)) % (numberOfBlocks_3D-1);
        player->blockRightPressed = 1;
    }

    if (gameControl.control_pause.gameControlPress)
    {
        gameControl.control_pause.gameControlPress = 0;
        //room_persistent=true;
        //global.returnTo=room;
        //d3d_end();
        //room_goto(rm_menu);
    }

    if (gameControl.control_itemOne.gameControlPress)
    {
        gameControl.control_itemOne.gameControlPress = 0;
        //if (global.itemOne == 1)
        //{
            //instance_create(player->x,player->y,obj_blockEditor3D);
            //obj_blockEditor3D.currentSpace = currentSpace;
            //instance_change(obj_player3DStalling,false);
        //}
    }

    if (gameControl.control_itemTwo.gameControlPress)
    {
        gameControl.control_itemTwo.gameControlPress = 0;
        /*if (global.itemTwo == 1)
        {
            instance_create(x,y,obj_blockEditor3D);
            obj_blockEditor3D.currentSpace = currentSpace;
            instance_change(obj_player3DStalling,false);
        }*/
    }

    if (player->moving == 1)
    {
        player->motion += 1;

        int movingSide = (player->motion <= 4)*player->movingSideOne + (player->motion > 4)*player->movingSideTwo;

        vector side = blkGph->blockGraph[e->currentSpace].side[movingSide];

        e->position = (player->motion <= 4)*((4-player->motion)*e->position + player->motion*side)/4 + (player->motion > 4)*((player->motion-5)*e->position + (9-player->motion)*side)/4;

        if (player->motion == 4)
        {
            e->currentSpace = player->movingSpace;
            e->sideFacing = player->sideFacingAfter;
        }

        if (player->motion == 8)
        {
            if (blkGph->blockGraph[e->currentSpace].type == 5)
            {
                player3D_moveInDirection((movingSide + 2) % 4, e);
            } else
            {
                player->moving = 0;
            }

            player->motion = 0;
        }
    }
}

void* player3D_createEvent()
{
    player3D* player = (player3D*)malloc(sizeof(player3D));
    player->sideFacingAfter = 0;
    player->moving = 0;
    player->motion = 0;
    player->movingSpace = 0;
    player->movingSideOne = 0;
    player->movingSideTwo = 0;
    player->texBody = 0;
    player->texEye = 0;
    player->type = 0;
    player->blockLeftPressed = 0;
    player->blockRightPressed = 0;

    //sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\block.png", 1, 0, 0, 0, 0, &player->texBody);
    //sprite_get_texture(&player->texBody,0,&player->texBody);

    //player->texEye = player->texBody;

    return player;
}
