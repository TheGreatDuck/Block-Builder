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

delayedInput convertToDelayedInput(double input)
{
    delayedInput returnValue;
    returnValue.number = input;
    returnValue.type = 0;
}

delayedInput convertToDelayedInput(char* input)
{
    delayedInput returnValue;
    returnValue.text = (char*) malloc(strlen(input) + 1);
    strcpy(returnValue.text, input);
    returnValue.type = 1;
}

delayedInput convertToDelayedInput(int* input)
{
    delayedInput returnValue;
    returnValue.delayedVariable = input;
    returnValue.type = 2;
}

template <typename T>
static void addDelayedFunctionCall_helper(int argument, T input)
{
    functionQueueEnd->input[argument] = convertToDelayedInput(input);
}

template <typename T, typename... Input>
static void addDelayedFunctionCall_helper(int argument, T input0, Input... input)
{
    functionQueueEnd->input[argument] = convertToDelayedInput(input0);
    argument++;
    addDelayedFunctionCall_helper(argument, input...)
}

void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput)
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

template <typename... Input>
void addDelayedFunctionCall(int function, int* delayedOutput, int hasOutput, Input... input)
{
    addDelayedFunctionCall(function, delayedOutput, hasOutput);
    addDelayedFunctionCall_helper(0, input...);
}

#define ADD_FUNCTION(name)\
static int FP_##name;\
GMEXPORT double export_##name(double functionPointer)\
{\
    FP_##name = functionPointer;\
    return functionPointer;\
}

ADD_FUNCTION(sprite_get_texture)
ADD_FUNCTION(sprite_add)

void sprite_get_texture(int* spr, double subimg, int* returnValue)
{
    addDelayedFunctionCall(FP_sprite_get_texture, returnValue, 1, spr, subimg);
}

void sprite_add(const char* fname, int imgnumb, int removeback, int smooth, int xorig, int yorig, int* ind)
{
    addDelayedFunctionCall(FP_sprite_add, ind, 1, fname, imgnumb, removeback, smooth, xorig, yorig);
}
