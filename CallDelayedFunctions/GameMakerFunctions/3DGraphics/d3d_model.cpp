#include <stdlib.h>
#include <string.h>
#include "delayed_function_calls.h"

ADD_FUNCTION(d3d_model_create)
ADD_FUNCTION(d3d_model_destroy)
ADD_FUNCTION(d3d_model_clear)
ADD_FUNCTION(d3d_model_save)
ADD_FUNCTION(d3d_model_load)
ADD_FUNCTION(d3d_model_draw)
ADD_FUNCTION(d3d_model_primitive_begin)
ADD_FUNCTION(d3d_model_vertex)
ADD_FUNCTION(d3d_model_vertex_color)
ADD_FUNCTION(d3d_model_vertex_texture)
ADD_FUNCTION(d3d_model_vertex_texture_color)
ADD_FUNCTION(d3d_model_vertex_normal)
ADD_FUNCTION(d3d_model_vertex_normal_color)
ADD_FUNCTION(d3d_model_vertex_normal_texture)
ADD_FUNCTION(d3d_model_vertex_normal_texture_color)
ADD_FUNCTION(d3d_model_primitive_end)

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
