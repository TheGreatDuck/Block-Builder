#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "vector.h"

#define GMEXPORT extern "C" __declspec(dllexport)

typedef struct block3D
{
    int type;
    int entityID;

    vector v[4];
    vector n[4];

    vector position;
    vector side[4];
    vector axisX[4];
    vector dir[4];
    vector normal;

    int removable;

    int adj[4];
    int adjSide[4];
} block3D;

typedef struct blockGraph
{
    unsigned int numberOfBlockModels;
    block3D* blockGraph;
    unsigned int numberOfModels;
    int* surfaceModel;
    int  fillerModel;
    int* blockGraphDirtyBit;
    unsigned int blockUpdateListLength;
    unsigned int* blockUpdateList;
    unsigned int blockUpdateListTempLength;
    unsigned int* blockUpdateListTemp;
    int spr_blockTexture;
    int tex_blockTexture;
} blockGraph;

blockGraph* blkGph_local;
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

void (*d3d_transform_add_block_matrix)(int blockID, int sideFacing);

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

#include "exampleEntity.h"
#include "entity.h"

GMEXPORT void instantiate_entity(entity_callback_data* ecd)
{
    numberOfBlocks_3D = ecd->numberOfBlocks3D;
    blkGph_local = ecd->blkGph;

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

GMEXPORT void drawEvent(entity* e)
{

}

GMEXPORT void stepEvent(entity* e, controlSet gameControl)
{
    e->turnActive = 0;
}

GMEXPORT void* createEvent()
{
    return NULL;
}
