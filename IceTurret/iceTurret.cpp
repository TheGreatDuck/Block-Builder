#define GMEXPORT extern "C" __declspec(dllexport)
#define ENTITY_DLL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "vector.h"
#include "iceTurret.h"
#include "entity.h"

blockGraph* blkGph;
int numberOfBlocks_3D;

void (*d3d_draw_block)(double, double, double, double, double, double, double, double, double);
void (*d3d_draw_cylinder)(double, double, double, double, double, double, double, double, double, double, double);
void (*d3d_draw_cone)(double, double, double, double, double, double, double, double, double, double, double);
void (*d3d_draw_ellipsoid)(double, double, double, double, double, double, double, double, double, double);
void (*d3d_draw_wall)(double, double, double, double, double, double, double, double, double);
void (*d3d_draw_floor)(double, double, double, double, double, double, double, double, double);

void (*d3d_transform_set_identity)();
void (*d3d_transform_add_rotation_x)(double direction);
void (*d3d_transform_add_rotation_y)(double direction);
void (*d3d_transform_add_rotation_z)(double direction);
void (*d3d_transform_add_translation)(double x, double y, double z);
void (*d3d_transform_add_rotation_axis)(double xa, double ya, double za,double angle);
void (*d3d_transform_add_scaling)(double xs, double ys, double zs);

double (*sprite_add)(const char* fname, double imgnumb, double removeback, double smooth, double xorig, double yorig);
double (*sprite_get_texture)(double spr, double subimg);

void (*d3d_primitive_begin)(double);
void (*d3d_vertex)(double x, double y, double z);
void (*d3d_vertex_color)(double x, double y, double z, double col, double alpha);
void (*d3d_primitive_end)();
void (*d3d_model_draw)(double ind, double x, double y, double z, double texid);
double (*d3d_model_create)();
void (*d3d_model_load)(double ind, const char* fname);
void (*d3d_model_primitive_begin)(double ind, double kind);
void (*d3d_model_vertex_texture)(double ind, double x, double y, double z, double xtex, double ytex);
void (*d3d_model_primitive_end)(double ind);
void (*d3d_model_destroy)(double ind);

void (*d3d_transform_add_block_matrix)(int blockID, int sideFacing, int motion, int movingSide);

typedef struct iceTurret3D
{
    unsigned int sideFacingAfter;
    unsigned int moving;
    unsigned int motion;
    unsigned int movingSpace;
    unsigned int movingSideOne;
    unsigned int movingSideTwo;

    unsigned int attackSelected;
    unsigned int attackType;

    int texBody1;
    int texBody2;
    int texEye;
} iceTurret3D;

GMEXPORT void instantiate_entity(entity_callback_data* ecd)
{
    numberOfBlocks_3D = ecd->numberOfBlocks3D;
    blkGph = ecd->blkGph;

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

    d3d_transform_add_block_matrix = ecd->d3d_transform_add_block_matrix;
}

static void moveInDirection(int sideMoving, entity* e)
{
    iceTurret3D* ice = (iceTurret3D*)e->internalData;
    int proposedSpace = blkGph->blockGraph[e->currentSpace].adj[sideMoving];

    if (proposedSpace != -1)
    {
        if (blkGph->blockGraph[proposedSpace].entityID == -1)
        {
            vector side = blkGph->blockGraph[e->currentSpace].side[sideMoving];

            ice->movingSpace   = proposedSpace;
            ice->movingSideOne = sideMoving;
            ice->movingSideTwo = blkGph->blockGraph[e->currentSpace].adjSide[sideMoving];

            if ((e->sideFacing - sideMoving + 4) % 4 == 0)//up
            {
                ice->sideFacingAfter = (ice->movingSideTwo + 2) % 4;
            } else if ((e->sideFacing - sideMoving + 4) % 4 == 3)//left
            {
                ice->sideFacingAfter = (ice->movingSideTwo + 1) % 4;
            } else if ((e->sideFacing - sideMoving + 4) % 4 == 1)//right
            {
                ice->sideFacingAfter = (ice->movingSideTwo + 3) % 4;
            } else if ((e->sideFacing - sideMoving + 4) % 4 == 2)//down
            {
                ice->sideFacingAfter = (ice->movingSideTwo + 0) % 4;
            }
            ice->moving = 1;
        } else
        {
            ice->moving = 0;
        }
    } else
    {
        ice->moving = 0;
    }
}

GMEXPORT void drawEvent(entity* e)
{
    iceTurret3D* ice = (iceTurret3D*)e->internalData;
    d3d_transform_set_identity();
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing, e->motion, e->movingSide);
    d3d_draw_cylinder(-2,-2,0,2,2,4,ice->texBody2,1,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(0,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing, e->motion, e->movingSide);
    d3d_draw_ellipsoid(-2,-2,-2,2,2,2,ice->texBody2,1,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_rotation_z(180);
    d3d_transform_add_rotation_x(45);
    d3d_transform_add_translation(0,1.5,5.5);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing, e->motion, e->movingSide);
    d3d_draw_ellipsoid(-0.75,-0.75,-0.75,0.75,0.75,0.75,ice->texEye,1,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_rotation_x(-45);
    d3d_transform_add_translation(0,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing, e->motion, e->movingSide);
    d3d_draw_cone(-1,-1,0,1,1,3,ice->texBody1,1,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_rotation_axis(-1/2,sqrt(3)/2,0,45);
    d3d_transform_add_translation(0,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing, e->motion, e->movingSide);
    d3d_draw_cone(-1,-1,0,1,1,3,ice->texBody1,1,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_rotation_axis(1/2,sqrt(3)/2,0,45);
    d3d_transform_add_translation(0,0,4);
    d3d_transform_add_block_matrix(e->currentSpace, e->sideFacing, e->motion, e->movingSide);
    d3d_draw_cone(-1,-1,0,1,1,3,ice->texBody1,1,1,true,60);

    d3d_transform_set_identity();
}

GMEXPORT void stepEvent(entity* e, controlSet gameControl)
{
    iceTurret3D* ice = (iceTurret3D*)e->internalData;
    if (!ice->attackSelected)
    {
        ice->attackType = rand() % 1;
        ice->attackSelected = 1;
    }

    if (ice->attackType == 0)
    {
        while (ice->moving == 0)
        {
            moveInDirection(rand() % 4, e);
        }

        if (ice->moving == 1)
        {
            ice->motion += 1;

            if (ice->motion < 4)
            {
                e->movingSide = ice->movingSideOne;
                e->motion = ice->motion;
            } else
            {
                e->movingSide = ice->movingSideTwo;
                e->motion = 8-ice->motion;
            }

            if (ice->motion == 4)
            {
                blkGph->blockGraph[ice->movingSpace].entityID = blkGph->blockGraph[e->currentSpace].entityID;
                blkGph->blockGraph[e->currentSpace].entityID = -1;
                e->currentSpace = ice->movingSpace;
                e->sideFacing = ice->sideFacingAfter;
            }

            if (ice->motion == 8)
            {
                if (blkGph->blockGraph[e->currentSpace].type == 5)
                {
                    moveInDirection((e->movingSide + 2) % 4, e);
                    if (ice->moving == 0)
                    {
                        e->turnActive = 0;
                        ice->attackSelected = 0;
                    }
                } else
                {
                    ice->moving = 0;
                    e->turnActive = 0;
                    ice->attackSelected = 0;
                }

                ice->motion = 0;
            }
        }
    }

    /*if (attackType == 1)
    {
        aD_x = 0;
        aD_y = 0;
        while (aD_x == 0 && aD_y == 0)
        {
            aD_x = irandom(2)-1;
            aD_y = irandom(2)-1;
        }

        projectile = instance_create(x+aD_x*64,y+aD_y*64,obj_iceball);
        projectile.hspeed = aD_x*8;
        projectile.vspeed = aD_y*8;

        attackType = -1;
    }

    if (instance_number(obj_iceball) == 0 && attackType == -1 && hspeed == 0 && vspeed == 0)
    {
        attackCompleted = true;
    }

    if (attackType == -1 && (x mod 64 == 0) && (y mod 64 == 0) && (hspeed != 0 || vspeed != 0))
    {
        hspeed = 0;
        vspeed = 0;
    }

    if (changeBack)
    {
        attackSelected = false;
        attackCompleted = false;
        changeBack = false;
        instance_change(obj_iceTurretIdle,false);
    }*/
}

GMEXPORT void* createEvent()
{
    iceTurret3D* ice = (iceTurret3D*)malloc(sizeof(iceTurret3D));
    ice->sideFacingAfter = 0;
    ice->moving = 0;
    ice->motion = 0;
    ice->movingSpace = 0;
    ice->movingSideOne = 0;
    ice->movingSideTwo = 0;

    ice->attackSelected = 0;
    ice->attackType = 0;

    ice->texBody1 = 0;
    ice->texBody2 = 0;
    ice->texEye = 0;

    //sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\block.png", 1, 0, 0, 0, 0, &player->texBody);
    //sprite_get_texture(&player->texBody,0,&player->texBody);

    //player->texEye = player->texBody;

    return ice;
}
