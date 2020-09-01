#include <stdlib.h>
#include <string.h>
#include "delayed_function_calls.h"

#define GMEXPORT extern "C" __declspec(dllexport)

typedef struct
{
    double number;
    char*  text;
    int*   delayedVariable;
    int    type;
} delayedInput;

typedef struct delayedFunctionCall
{
    delayedInput                input[14];
    int                         function;
    int*                        delayedOutput;
    int                         hasOutput;
    struct delayedFunctionCall* next;
} delayedFunctionCall;

static delayedFunctionCall* functionQueueStart;
static delayedFunctionCall* functionQueueEnd;

GMEXPORT double removeDelayedFunctionCall()
{
    if (functionQueueStart)
    {
        delayedFunctionCall* temp = functionQueueStart;
        functionQueueStart = functionQueueStart->next;
        for (int i = 0; i < 14; i++)
        {
            if (temp->input[i].type == 1)
            {
                free(temp->input[i].text);
            }
        }
        free(temp);
        if (temp == functionQueueEnd)
        {
            functionQueueEnd   = NULL;
            functionQueueStart = NULL;
        }
    }
    return 1.0;
}

GMEXPORT double getInputDelayedVariable(double input)
{
    return *functionQueueStart->input[(int)input].delayedVariable;
}

GMEXPORT char* getInputText(double input)
{
    return functionQueueStart->input[(int)input].text;
}

GMEXPORT double getInputNumber(double input)
{
    return functionQueueStart->input[(int)input].number;
}

GMEXPORT double getInputType(double input)
{
    return functionQueueStart->input[(int)input].type;
}

GMEXPORT double getFunction()
{
    return functionQueueStart->function;
}

GMEXPORT double setDelayedOutput(double value)
{
    *functionQueueStart->delayedOutput = value;
    return value;
}

GMEXPORT double getHasOutput()
{
    return functionQueueStart->hasOutput;
}

GMEXPORT double isThereDelayedFunctionCall()
{
    return functionQueueStart != NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
    }

    functionQueueEnd->function      = function;
    functionQueueEnd->delayedOutput = delayedOutput;
    functionQueueEnd->hasOutput     = hasOutput;
    functionQueueEnd->next          = NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
    }

    functionQueueEnd->input[0] = input0;

    functionQueueEnd->function      = function;
    functionQueueEnd->delayedOutput = delayedOutput;
    functionQueueEnd->hasOutput     = hasOutput;
    functionQueueEnd->next          = NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
    }

    functionQueueEnd->input[0] = input0;
    functionQueueEnd->input[1] = input1;

    functionQueueEnd->function      = function;
    functionQueueEnd->delayedOutput = delayedOutput;
    functionQueueEnd->hasOutput     = hasOutput;
    functionQueueEnd->next          = NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
    }

    functionQueueEnd->input[0] = input0;
    functionQueueEnd->input[1] = input1;
    functionQueueEnd->input[2] = input2;

    functionQueueEnd->function      = function;
    functionQueueEnd->delayedOutput = delayedOutput;
    functionQueueEnd->hasOutput     = hasOutput;
    functionQueueEnd->next          = NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
    }

    functionQueueEnd->input[0] = input0;
    functionQueueEnd->input[1] = input1;
    functionQueueEnd->input[2] = input2;
    functionQueueEnd->input[3] = input3;

    functionQueueEnd->function      = function;
    functionQueueEnd->delayedOutput = delayedOutput;
    functionQueueEnd->hasOutput     = hasOutput;
    functionQueueEnd->next          = NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
    }

    functionQueueEnd->input[0] = input0;
    functionQueueEnd->input[1] = input1;
    functionQueueEnd->input[2] = input2;
    functionQueueEnd->input[3] = input3;
    functionQueueEnd->input[4] = input4;

    functionQueueEnd->function      = function;
    functionQueueEnd->delayedOutput = delayedOutput;
    functionQueueEnd->hasOutput     = hasOutput;
    functionQueueEnd->next          = NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
    }

    functionQueueEnd->input[0] = input0;
    functionQueueEnd->input[1] = input1;
    functionQueueEnd->input[2] = input2;
    functionQueueEnd->input[3] = input3;
    functionQueueEnd->input[4] = input4;
    functionQueueEnd->input[5] = input5;

    functionQueueEnd->function      = function;
    functionQueueEnd->delayedOutput = delayedOutput;
    functionQueueEnd->hasOutput     = hasOutput;
    functionQueueEnd->next          = NULL;
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[6] = input6;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6, delayedInput input7)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[7] = input7;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5, input6);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6, delayedInput input7, delayedInput input8)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[8] = input8;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5, input6, input7);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6, delayedInput input7, delayedInput input8, delayedInput input9)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[9] = input9;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5, input6, input7, input8);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6, delayedInput input7, delayedInput input8, delayedInput input9, delayedInput input10)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[10] = input10;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5, input6, input7, input8, input9);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6, delayedInput input7, delayedInput input8, delayedInput input9, delayedInput input10, delayedInput input11)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[11] = input11;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5, input6, input7, input8, input9, input10);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6, delayedInput input7, delayedInput input8, delayedInput input9, delayedInput input10, delayedInput input11, delayedInput input12)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[12] = input12;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5, input6, input7, input8, input9, input10, input11);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, delayedInput input0, delayedInput input1, delayedInput input2, delayedInput input3, delayedInput input4, delayedInput input5, delayedInput input6, delayedInput input7, delayedInput input8, delayedInput input9, delayedInput input10, delayedInput input11, delayedInput input12, delayedInput input13)
{
    if (functionQueueEnd == NULL)
    {
        functionQueueEnd = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd, 0, sizeof(delayedFunctionCall));
        functionQueueStart = functionQueueEnd;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    } else if (functionQueueEnd->next == NULL)
    {
        functionQueueEnd->next = (delayedFunctionCall*) malloc(sizeof(delayedFunctionCall));
        memset(functionQueueEnd->next, 0, sizeof(delayedFunctionCall));
        functionQueueEnd = functionQueueEnd->next;
         // flag the next pointer to prevent
         // duplicate creation
        functionQueueEnd->next = (delayedFunctionCall*)1;
    }

    functionQueueEnd->input[13] = input13;
    addDelayedFunctionCall(function, delayedOutput, hasOutput, input0, input1, input2, input3, input4, input5, input6, input7, input8, input9, input10, input11, input12);
}

#define ADD_FUNCTION(name)\
static int FP_##name;\
GMEXPORT double export_##name(double functionPointer)\
{\
    FP_##name = functionPointer;\
    return functionPointer;\
}

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
ADD_FUNCTION(sprite_get_texture)
ADD_FUNCTION(d3d_primitive_begin)
ADD_FUNCTION(d3d_vertex)
ADD_FUNCTION(d3d_vertex_color)
ADD_FUNCTION(d3d_primitive_end)
ADD_FUNCTION(d3d_model_draw)
ADD_FUNCTION(d3d_model_create)
ADD_FUNCTION(d3d_model_load)
ADD_FUNCTION(sprite_add)
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

void sprite_get_texture(int* spr, double subimg, int* returnValue)
{
    delayedInput input0;

    input0.delayedVariable = spr;
    input0.type            = 2;

    delayedInput input1;

    input1.number = subimg;
    input1.type   = 0;

    addDelayedFunctionCall(FP_sprite_get_texture, returnValue, 1, input0, input1);
}

void sprite_add(const char* fname, int imgnumb, int removeback, int smooth, int xorig, int yorig, int* ind)
{
    delayedInput input0;

    input0.text = (char*) malloc(strlen(fname) + 1);
    strcpy(input0.text, fname);
    input0.type = 1;

    delayedInput input1;

    input1.number = imgnumb;
    input1.type   = 0;

    delayedInput input2;

    input2.number = removeback;
    input2.type   = 0;

    delayedInput input3;

    input3.number = smooth;
    input3.type   = 0;

    delayedInput input4;

    input4.number = xorig;
    input4.type   = 0;

    delayedInput input5;

    input5.number = yorig;
    input5.type   = 0;

    addDelayedFunctionCall(FP_sprite_add, ind, 1, input0, input1, input2, input3, input4, input5);
}
