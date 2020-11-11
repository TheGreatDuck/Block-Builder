#include "vector.hpp"
#include "blockGraph.hpp"
#include "controls.hpp"

#ifndef ENTITY_H
#define ENTITY_H
typedef struct entity_callback_data
{
    /** \brief
     *
     */
    blockGraph* blkGph;

    /** \brief
     *
     */
    int numberOfBlocks3D;


    /** \brief
     *
     */
    void (*d3d_draw_block)(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat);

    /** \brief
     *
     */
    void (*d3d_draw_cylinder)(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int closed, int steps);

    /** \brief
     *
     */
    void (*d3d_draw_cone)(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int closed, int steps);

    /** \brief
     *
     */
    void (*d3d_draw_ellipsoid)(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat, int steps);

    /** \brief
     *
     */
    void (*d3d_draw_wall)(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat);

    /** \brief
     *
     */
    void (*d3d_draw_floor)(double x1, double y1, double z1, double x2, double y2, double z2, double texid, int hrepeat, int vrepeat);


    /** \brief
     *
     */
    void (*d3d_transform_set_identity)();

    /** \brief
     *
     */
    void (*d3d_transform_add_rotation_x)(double direction);

    /** \brief
     *
     */
    void (*d3d_transform_add_rotation_y)(double direction);

    /** \brief
     *
     */
    void (*d3d_transform_add_rotation_z)(double direction);

    /** \brief
     *
     */
    void (*d3d_transform_add_translation)(double x, double y, double z);

    /** \brief
     *
     */
    void (*d3d_transform_add_rotation_axis)(double xa, double ya, double za,double angle);

    /** \brief
     *
     */
    void (*d3d_transform_add_scaling)(double xs, double ys, double zs);


    /** \brief
     *
     */
    double (*sprite_add)(const char* fname, double imgnumb, double removeback, double smooth, double xorig, double yorig);

    /** \brief
     *
     */
    double (*sprite_get_texture)(double spr, double subimg);


    /** \brief
     *
     */
    void (*d3d_primitive_begin)(double);

    /** \brief
     *
     */
    void (*d3d_vertex)(double x, double y, double z);

    /** \brief
     *
     */
    void (*d3d_vertex_color)(double x, double y, double z, double col, double alpha);

    /** \brief
     *
     */
    void (*d3d_primitive_end)();

    /** \brief
     *
     */
    void (*d3d_model_draw)(double ind, double x, double y, double z, double texid);

    /** \brief
     *
     */
    double (*d3d_model_create)();

    /** \brief
     *
     */
    void (*d3d_model_load)(double ind, const char* fname);

    /** \brief
     *
     */
    void (*d3d_model_primitive_begin)(double ind, double kind);

    /** \brief
     *
     */
    void (*d3d_model_vertex_texture)(double ind, double x, double y, double z, double xtex, double ytex);

    /** \brief
     *
     */
    void (*d3d_model_primitive_end)(double ind);

    /** \brief
     *
     */
    void (*d3d_model_destroy)(double ind);


    /** \brief
     *
     */
    void (*d3d_transform_add_block_matrix)(int blockID, int sideFacing, int motion, int movingSide);
} entity_callback_data;

typedef struct entity
{
    /** \brief
     *
     */
    unsigned int currentSpace;

    /** \brief
     *
     */
    unsigned int sideFacing;

    /** \brief
     *
     */
    unsigned int motion;

    /** \brief
     *
     */
    unsigned int movingSide;

    /** \brief
     *
     */
    unsigned int typeID;

    /** \brief
     *
     */
    unsigned int turnActive;

    /** \brief
     *
     */
    int entityID;

    /** \brief
     *
     */
    int alive;

    /** \brief
     *
     */
    void* internalData;
} entity;

typedef void* (__cdecl *CREATE_EVENT)();
typedef void  (__cdecl *STEP_EVENT)(entity*, controlSet gameControl);
typedef void  (__cdecl *DRAW_EVENT)(entity*);
typedef void  (__cdecl *INSTANTIATE_ENTITY)(entity_callback_data* ecd);

typedef struct entityType
{
    /** \brief
     *
     */
    CREATE_EVENT createEvent;

    /** \brief
     *
     */
    STEP_EVENT   stepEvent;

    /** \brief
     *
     */
    DRAW_EVENT   drawEvent;
} entityType;
#endif
