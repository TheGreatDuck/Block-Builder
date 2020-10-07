#include <stdlib.h>
#include <string.h>
#include <queue>
#include "delayed_function_calls.hpp"

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
} delayedFunctionCall;

std::queue<delayedFunctionCall> functionQueue;

GMEXPORT double removeDelayedFunctionCall()
{
    if (!functionQueue.empty())
    {
        delayedFunctionCall temp = functionQueue.front();
        functionQueue.pop();
        for (int i = 0; i < 14; i++)
        {
            if (temp.input[i].type == 1)
                free(temp.input[i].text);
        }
    }
    return 1.0;
}

GMEXPORT double getInputDelayedVariable(double input)
{
    return *(functionQueue.front().input[(int)input].delayedVariable);
}

GMEXPORT char* getInputText(double input)
{
    return functionQueue.front().input[(int)input].text;
}

GMEXPORT double getInputNumber(double input)
{
    return functionQueue.front().input[(int)input].number;
}

GMEXPORT double getInputType(double input)
{
    return functionQueue.front().input[(int)input].type;
}

GMEXPORT double getFunction()
{
    return functionQueue.front().function;
}

GMEXPORT double setDelayedOutput(double value)
{
    *(functionQueue.front().delayedOutput) = value;
    return value;
}

GMEXPORT double getHasOutput()
{
    return functionQueue.front().hasOutput;
}

GMEXPORT double isThereDelayedFunctionCall()
{
    return !functionQueue.empty();
}

static delayedInput convertToDelayedInput(double input)
{
    delayedInput returnValue;
    returnValue.number = input;
    returnValue.type = 0;
    return returnValue;
}

static delayedInput convertToDelayedInput(const char* input)
{
    delayedInput returnValue;
    returnValue.text = (char*) malloc((strlen(input) + 1)*sizeof(char));
    strcpy(returnValue.text, input);
    returnValue.type = 1;
    return returnValue;
}

static delayedInput convertToDelayedInput(int* input)
{
    delayedInput returnValue;
    returnValue.delayedVariable = input;
    returnValue.type = 2;
    return returnValue;
}

template <typename T> void addDelayedFunctionCall_helper(int argument, T input)
{
    functionQueue.back().input[argument] = convertToDelayedInput(input);
}

template <typename T, typename... Input> void addDelayedFunctionCall_helper(int argument, T input0, Input... input)
{
    functionQueue.back().input[argument] = convertToDelayedInput(input0);
    argument++;
    addDelayedFunctionCall_helper(argument, input...);
}

static void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput)
{
    delayedFunctionCall call;
    memset(&call, 0, sizeof(delayedFunctionCall));
    functionQueue.push(call);
    functionQueue.back().function      = function;
    functionQueue.back().delayedOutput = delayedOutput;
    functionQueue.back().hasOutput     = hasOutput;
}

template <typename... Input> void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, Input... input)
{
    addDelayedFunctionCall(function, delayedOutput, hasOutput);
    addDelayedFunctionCall_helper(0, input...);
}

#define ADD_FUNCTION(name)\
static int FP_##name;\
GMEXPORT double export_##name(double functionPointer);\
GMEXPORT double export_##name(double functionPointer)\
{\
    FP_##name = functionPointer;\
    return functionPointer;\
}

#define DEFINE_WRAPPERS 1
#include "gameMakerLibrary.hpp"

ADD_FUNCTION(sprite_get_texture)
ADD_FUNCTION(sprite_add)
ADD_FUNCTION(draw_sprite)

void sprite_get_texture(int* spr, double subimg, int* returnValue)
{
    addDelayedFunctionCall(FP_sprite_get_texture, returnValue, 1, spr, subimg);
}

void sprite_add(const char* fname, double imgnumb, double removeback, double smooth, double xorig, double yorig, int* ind)
{
    addDelayedFunctionCall(FP_sprite_add, ind, 1, fname, imgnumb, removeback, smooth, xorig, yorig);
}

void draw_sprite(int* spr, double subimg, double x, double y)
{
    addDelayedFunctionCall(FP_draw_sprite, NULL, 0, spr, subimg, x, y);
}
