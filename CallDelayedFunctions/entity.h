#include "vector.h"

#ifndef ENTITY_H
#define ENTITY_H
typedef struct entity
{
    unsigned int currentSpace;
    unsigned int sideFacing;
    unsigned int typeID;
    vector position;
    void* internalData;
} entity;

typedef struct entityType
{
    void* (*createEvent)();
    void  (*stepEvent)(entity*, controlSet gameControl);
    void  (*drawEvent)(entity*);
} entityType;

typedef struct entity_callback_data
{
    int numberOfBlocks3D;

    void (*d3d_draw_block)(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat);
    void (*d3d_draw_cylinder)(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps);
    void (*d3d_draw_cone)(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps);
    void (*d3d_draw_ellipsoid)(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int steps);
    void (*d3d_draw_wall)(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat);
    void (*d3d_draw_floor)(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat);

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
} entity_callback_data;
#endif
