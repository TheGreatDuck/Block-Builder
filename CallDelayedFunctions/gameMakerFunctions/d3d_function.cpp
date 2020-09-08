#include <stdlib.h>
#include <string.h>
#include "../delayed_function_calls.h"

ADD_FUNCTION(d3d_draw_block)
ADD_FUNCTION(d3d_draw_cylinder)
ADD_FUNCTION(d3d_draw_cone)
ADD_FUNCTION(d3d_draw_ellipsoid)
ADD_FUNCTION(d3d_draw_wall)
ADD_FUNCTION(d3d_draw_floor)
ADD_FUNCTION(d3d_transform_set_identity)
ADD_FUNCTION(d3d_transform_add_rotation_x)
ADD_FUNCTION(d3d_transform_add_rotation_y)
ADD_FUNCTION(d3d_transform_add_rotation_z)
ADD_FUNCTION(d3d_transform_add_translation)
ADD_FUNCTION(d3d_transform_add_rotation_axis)
ADD_FUNCTION(d3d_primitive_begin)
ADD_FUNCTION(d3d_vertex)
ADD_FUNCTION(d3d_vertex_color)
ADD_FUNCTION(d3d_primitive_end)
ADD_FUNCTION(d3d_model_draw)
ADD_FUNCTION(d3d_model_create)
ADD_FUNCTION(d3d_model_load)
ADD_FUNCTION(d3d_transform_add_scaling)
ADD_FUNCTION(d3d_set_projection_ortho)
ADD_FUNCTION(d3d_set_projection_perspective)
ADD_FUNCTION(d3d_set_projection)
ADD_FUNCTION(d3d_model_primitive_begin)
ADD_FUNCTION(d3d_model_vertex_texture)
ADD_FUNCTION(d3d_model_primitive_end)
ADD_FUNCTION(d3d_model_destroy)
ADD_FUNCTION(d3d_start)
ADD_FUNCTION(d3d_set_fog)
ADD_FUNCTION(d3d_set_lighting)

void d3d_draw_block(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat)
{
    delayedInput input0;
    delayedInput input1;
    delayedInput input2;
    delayedInput input3;
    delayedInput input4;
    delayedInput input5;
    delayedInput input6;
    delayedInput input7;
    delayedInput input8;

    input0.number = x1;
    input0.type = 0;

    input1.number = y1;
    input1.type = 0;

    input2.number = z1;
    input2.type = 0;

    input3.number = x2;
    input3.type = 0;

    input4.number = y2;
    input4.type = 0;

    input5.number = z2;
    input5.type = 0;

    input6.delayedVariable = texid;
    input6.type          = 2;

    input7.number = hrepeat;
    input7.type = 0;

    input8.number = vrepeat;
    input8.type = 0;

    addDelayedFunctionCall(FP_d3d_draw_block, NULL, 0, input0, input1, input2, input3, input4, input5, input6, input7, input8);
}

void d3d_draw_cylinder(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps)
{
    delayedInput input0;
    delayedInput input1;
    delayedInput input2;
    delayedInput input3;
    delayedInput input4;
    delayedInput input5;
    delayedInput input6;
    delayedInput input7;
    delayedInput input8;
    delayedInput input9;
    delayedInput input10;

    input0.number = x1;
    input0.type = 0;

    input1.number = y1;
    input1.type = 0;

    input2.number = z1;
    input2.type = 0;

    input3.number = x2;
    input3.type = 0;

    input4.number = y2;
    input4.type = 0;

    input5.number = z2;
    input5.type = 0;

    input6.delayedVariable = texid;
    input6.type          = 2;

    input7.number = hrepeat;
    input7.type = 0;

    input8.number = vrepeat;
    input8.type = 0;

    input9.number = closed;
    input9.type = 0;

    input10.number = steps;
    input10.type = 0;

    addDelayedFunctionCall(FP_d3d_draw_cylinder, NULL, 0, input0, input1, input2, input3, input4, input5, input6, input7, input8, input9, input10);
}

void d3d_draw_cone(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int closed, int steps)
{
    delayedInput input0;
    delayedInput input1;
    delayedInput input2;
    delayedInput input3;
    delayedInput input4;
    delayedInput input5;
    delayedInput input6;
    delayedInput input7;
    delayedInput input8;
    delayedInput input9;
    delayedInput input10;

    input0.number = x1;
    input0.type = 0;

    input1.number = y1;
    input1.type = 0;

    input2.number = z1;
    input2.type = 0;

    input3.number = x2;
    input3.type = 0;

    input4.number = y2;
    input4.type = 0;

    input5.number = z2;
    input5.type = 0;

    input6.delayedVariable = texid;
    input6.type          = 2;

    input7.number = hrepeat;
    input7.type = 0;

    input8.number = vrepeat;
    input8.type = 0;

    input9.number = closed;
    input9.type = 0;

    input10.number = steps;
    input10.type = 0;

    addDelayedFunctionCall(FP_d3d_draw_cone, NULL, 0, input0, input1, input2, input3, input4, input5, input6, input7, input8, input9, input10);
}

void d3d_draw_ellipsoid(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat, int steps)
{
    delayedInput input0;
    delayedInput input1;
    delayedInput input2;
    delayedInput input3;
    delayedInput input4;
    delayedInput input5;
    delayedInput input6;
    delayedInput input7;
    delayedInput input8;
    delayedInput input9;

    input0.number = x1;
    input0.type = 0;

    input1.number = y1;
    input1.type = 0;

    input2.number = z1;
    input2.type = 0;

    input3.number = x2;
    input3.type = 0;

    input4.number = y2;
    input4.type = 0;

    input5.number = z2;
    input5.type = 0;

    input6.delayedVariable = texid;
    input6.type          = 2;

    input7.number = hrepeat;
    input7.type = 0;

    input8.number = vrepeat;
    input8.type = 0;

    input9.number = steps;
    input9.type = 0;

    addDelayedFunctionCall(FP_d3d_draw_ellipsoid, NULL, 0, input0, input1, input2, input3, input4, input5, input6, input7, input8, input9);
}

void d3d_draw_wall(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat)
{
    delayedInput input0;
    delayedInput input1;
    delayedInput input2;
    delayedInput input3;
    delayedInput input4;
    delayedInput input5;
    delayedInput input6;
    delayedInput input7;
    delayedInput input8;

    input0.number = x1;
    input0.type = 0;

    input1.number = y1;
    input1.type = 0;

    input2.number = z1;
    input2.type = 0;

    input3.number = x2;
    input3.type = 0;

    input4.number = y2;
    input4.type = 0;

    input5.number = z2;
    input5.type = 0;

    input6.delayedVariable = texid;
    input6.type          = 2;

    input7.number = hrepeat;
    input7.type = 0;

    input8.number = vrepeat;
    input8.type = 0;

    addDelayedFunctionCall(FP_d3d_draw_wall, NULL, 0, input0, input1, input2, input3, input4, input5, input6, input7, input8);
}

void d3d_draw_floor(double x1, double y1, double z1, double x2, double y2, double z2, int* texid, int hrepeat, int vrepeat)
{
    delayedInput input0;
    delayedInput input1;
    delayedInput input2;
    delayedInput input3;
    delayedInput input4;
    delayedInput input5;
    delayedInput input6;
    delayedInput input7;
    delayedInput input8;

    input0.number = x1;
    input0.type   = 0;

    input1.number = y1;
    input1.type   = 0;

    input2.number = z1;
    input2.type   = 0;

    input3.number = x2;
    input3.type   = 0;

    input4.number = y2;
    input4.type   = 0;

    input5.number = z2;
    input5.type   = 0;

    input6.delayedVariable = texid;
    input6.type            = 2;

    input7.number = hrepeat;
    input7.type   = 0;

    input8.number = vrepeat;
    input8.type   = 0;

    addDelayedFunctionCall(FP_d3d_draw_floor, NULL, 0, input0, input1, input2, input3, input4, input5, input6, input7, input8);
}

void d3d_transform_set_identity()
{
    addDelayedFunctionCall(FP_d3d_transform_set_identity, NULL, 0);
}

void d3d_transform_add_rotation_x(double direction)
{
    delayedInput input0;

    input0.number = direction;
    input0.type   = 0;

    addDelayedFunctionCall(FP_d3d_transform_add_rotation_x, NULL, 0, input0);
}

void d3d_transform_add_rotation_y(double direction)
{
    delayedInput input0;

    input0.number = direction;
    input0.type   = 0;

    addDelayedFunctionCall(FP_d3d_transform_add_rotation_y, NULL, 0, input0);
}

void d3d_transform_add_rotation_z(double direction)
{
    delayedInput input0;

    input0.number = direction;
    input0.type   = 0;

    addDelayedFunctionCall(FP_d3d_transform_add_rotation_z, NULL, 0, input0);
}

void d3d_transform_add_translation(double x, double y, double z)
{
    delayedInput input0;

    input0.number = x;
    input0.type   = 0;

    delayedInput input1;

    input1.number = y;
    input1.type   = 0;

    delayedInput input2;

    input2.number = z;
    input2.type   = 0;

    addDelayedFunctionCall(FP_d3d_transform_add_translation, NULL, 0, input0, input1, input2);
}

void d3d_transform_add_rotation_axis(double xa, double ya, double za, double angle)
{
    delayedInput input0;

    input0.number = xa;
    input0.type   = 0;

    delayedInput input1;

    input1.number = ya;
    input1.type   = 0;

    delayedInput input2;

    input2.number = za;
    input2.type   = 0;

    delayedInput input3;

    input3.number = angle;
    input3.type   = 0;

    addDelayedFunctionCall(FP_d3d_transform_add_rotation_axis, NULL, 0, input0, input1, input2, input3);
}

void d3d_primitive_begin(double kind)
{
    delayedInput input0;

    input0.number = kind;
    input0.type   = 0;

    addDelayedFunctionCall(FP_d3d_primitive_begin, NULL, 0, input0);
}

void d3d_vertex(double x, double y, double z)
{
    delayedInput input0;

    input0.number = x;
    input0.type   = 0;

    delayedInput input1;

    input1.number = y;
    input1.type   = 0;

    delayedInput input2;

    input2.number = z;
    input2.type   = 0;

    addDelayedFunctionCall(FP_d3d_vertex, NULL, 0, input0, input1, input2);
}

void d3d_vertex_color(double x, double y, double z, double col, double alpha)
{
    delayedInput input0;

    input0.number = x;
    input0.type   = 0;

    delayedInput input1;

    input1.number = y;
    input1.type   = 0;

    delayedInput input2;

    input2.number = z;
    input2.type   = 0;

    delayedInput input3;

    input3.number = col;
    input3.type   = 0;

    delayedInput input4;

    input4.number = alpha;
    input4.type   = 0;

    addDelayedFunctionCall(FP_d3d_vertex_color, NULL, 0, input0, input1, input2, input3, input4);
}

void d3d_primitive_end()
{
    addDelayedFunctionCall(FP_d3d_primitive_end, NULL, 0);
}

void d3d_model_draw(int* ind, double x, double y, double z, int* texid)
{
    delayedInput input0;

    input0.delayedVariable = ind;
    input0.type            = 2;

    delayedInput input1;

    input1.number = x;
    input1.type   = 0;

    delayedInput input2;

    input2.number = y;
    input2.type   = 0;

    delayedInput input3;

    input3.number = z;
    input3.type   = 0;

    delayedInput input4;

    input4.delayedVariable = texid;
    input4.type            = 2;

    addDelayedFunctionCall(FP_d3d_model_draw, NULL, 0, input0, input1, input2, input3, input4);
}

void d3d_model_create(int* ind)
{
    addDelayedFunctionCall(FP_d3d_model_create, ind, 1);
}

void d3d_model_load(int* ind, const char* fname)
{
    delayedInput input0;

    input0.delayedVariable = ind;
    input0.type            = 2;

    delayedInput input1;

    input1.text = (char*) malloc(strlen(fname) + 1);
    strcpy(input1.text, fname);
    input1.type = 1;

    addDelayedFunctionCall(FP_d3d_model_load, NULL, 0, input0, input1);
}

void d3d_transform_add_scaling(double xs, double ys, double zs)
{
    delayedInput input0;

    input0.number = xs;
    input0.type   = 0;

    delayedInput input1;

    input1.number = ys;
    input1.type   = 0;

    delayedInput input2;

    input2.number = zs;
    input2.type   = 0;

    addDelayedFunctionCall(FP_d3d_transform_add_scaling, 0, 0, input0, input1, input2);
}

void d3d_set_projection_ortho(double x, double y, double w, double h, double angle)
{
    delayedInput input0;

    input0.number = x;
    input0.type   = 0;

    delayedInput input1;

    input1.number = y;
    input1.type   = 0;

    delayedInput input2;

    input2.number = w;
    input2.type   = 0;

    delayedInput input3;

    input3.number = h;
    input3.type   = 0;

    delayedInput input4;

    input4.number = angle;
    input4.type   = 0;

    addDelayedFunctionCall(FP_d3d_set_projection_ortho, 0, 0, input0, input1, input2, input3, input4);
}

void d3d_set_projection_perspective(double x, double y, double w, double h, double angle)
{
    delayedInput input0;

    input0.number = x;
    input0.type   = 0;

    delayedInput input1;

    input1.number = y;
    input1.type   = 0;

    delayedInput input2;

    input2.number = w;
    input2.type   = 0;

    delayedInput input3;

    input3.number = h;
    input3.type   = 0;

    delayedInput input4;

    input4.number = angle;
    input4.type   = 0;

    addDelayedFunctionCall(FP_d3d_set_projection_perspective, 0, 0, input0, input1, input2, input3, input4);
}

void d3d_set_projection(double xfrom, double yfrom, double zfrom, double xto, double yto, double zto, double xup, double yup, double zup)
{
    delayedInput input0;

    input0.number = xfrom;
    input0.type   = 0;

    delayedInput input1;

    input1.number = yfrom;
    input1.type   = 0;

    delayedInput input2;

    input2.number = zfrom;
    input2.type   = 0;

    delayedInput input3;

    input3.number = xto;
    input3.type   = 0;

    delayedInput input4;

    input4.number = yto;
    input4.type   = 0;

    delayedInput input5;

    input5.number = zto;
    input5.type   = 0;

    delayedInput input6;

    input6.number = xup;
    input6.type   = 0;

    delayedInput input7;

    input7.number = yup;
    input7.type   = 0;

    delayedInput input8;

    input8.number = zup;
    input8.type   = 0;

    addDelayedFunctionCall(FP_d3d_set_projection, 0, 0, input0, input1, input2, input3, input4, input5, input6, input7, input8);
}

void d3d_model_primitive_begin(int* ind, double kind)
{
    delayedInput input0;

    input0.delayedVariable = ind;
    input0.type            = 2;

    delayedInput input1;

    input1.number = kind;
    input1.type   = 0;

    addDelayedFunctionCall(FP_d3d_model_primitive_begin, 0, 0, input0, input1);
}

void d3d_model_vertex_texture(int* ind, double x, double y, double z, double xtex, double ytex)
{
    delayedInput input0;

    input0.delayedVariable = ind;
    input0.type            = 2;

    delayedInput input1;

    input1.number = x;
    input1.type   = 0;

    delayedInput input2;

    input2.number = y;
    input2.type   = 0;

    delayedInput input3;

    input3.number = z;
    input3.type   = 0;

    delayedInput input4;

    input4.number = xtex;
    input4.type   = 0;

    delayedInput input5;

    input5.number = ytex;
    input5.type   = 0;

    addDelayedFunctionCall(FP_d3d_model_vertex_texture, 0, 0, input0, input1, input2, input3, input4, input5);
}

void d3d_model_primitive_end(int* ind)
{
    delayedInput input0;

    input0.delayedVariable = ind;
    input0.type            = 2;

    addDelayedFunctionCall(FP_d3d_model_primitive_end, 0, 0, input0);
}

void d3d_model_destroy(double ind)
{
    delayedInput input0;

    input0.number = ind;
    input0.type   = 0;

    addDelayedFunctionCall(FP_d3d_model_destroy, 0, 0, input0);
}

void d3d_start()
{
    addDelayedFunctionCall(FP_d3d_start, 0, 0);
}

void d3d_set_fog(double enable, double color, double start, double end)
{
    delayedInput input0;

    input0.number = enable;
    input0.type   = 0;

    delayedInput input1;

    input1.number = color;
    input1.type   = 0;

    delayedInput input2;

    input2.number = start;
    input2.type   = 0;

    delayedInput input3;

    input3.number = end;
    input3.type   = 0;

    addDelayedFunctionCall(FP_d3d_set_fog, 0, 0, input0, input1, input2, input3);
}

void d3d_set_lighting(double enable)
{
    delayedInput input0;

    input0.number = enable;
    input0.type   = 0;

    addDelayedFunctionCall(FP_d3d_set_lighting, 0, 0, input0);
}
