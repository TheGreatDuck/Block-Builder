#include <stdlib.h>
#include <string.h>
#include <queue>
#include <pthread.h>
#include "delayed_function_calls.hpp"
#include "gameLoop.hpp"

typedef struct
{
    /** \brief
     *
     */
    double number;

    /** \brief
     *
     */
    char*  text;

    /** \brief
     *
     */
    int    type;
} delayedInput;

typedef struct delayedFunctionCall
{
    /** \brief
     *
     */
    delayedInput                input[14];

    /** \brief
     *
     */
    int                         function;

    /** \brief
     *
     */
    double*                     delayedOutput;

    /** \brief
     *
     */
    int                         hasOutput;
} delayedFunctionCall;

std::queue<delayedFunctionCall> functionQueue;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT char* getInputText(double input)
{
    return functionQueue.front().input[(int)input].text;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getInputNumber(double input)
{
    return functionQueue.front().input[(int)input].number;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getInputType(double input)
{
    return functionQueue.front().input[(int)input].type;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getFunction()
{
    return functionQueue.front().function;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double setDelayedOutput(double value)
{
    *(functionQueue.front().delayedOutput) = value;
    return value;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double getHasOutput()
{
    return functionQueue.front().hasOutput;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double isThereDelayedFunctionCall()
{
    return !functionQueue.empty();
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
static delayedInput convertToDelayedInput(double input)
{
    delayedInput returnValue;
    returnValue.number = input;
    returnValue.type = 0;
    return returnValue;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
static delayedInput convertToDelayedInput(const char* input)
{
    delayedInput returnValue;
    returnValue.text = (char*) malloc((strlen(input) + 1)*sizeof(char));
    strcpy(returnValue.text, input);
    returnValue.type = 1;
    return returnValue;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
template <typename T> void addDelayedFunctionCall_helper(int argument, delayedFunctionCall* call, T input)
{
    call->input[argument] = convertToDelayedInput(input);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
template <typename T, typename... Input> void addDelayedFunctionCall_helper(int argument, delayedFunctionCall* call, T input0, Input... input)
{
    call->input[argument] = convertToDelayedInput(input0);
    argument++;
    addDelayedFunctionCall_helper(argument, call, input...);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
static double addDelayedFunctionCall(int function, int hasOutput)
{
    delayedFunctionCall call;
    memset(&call, 0, sizeof(delayedFunctionCall));
    double delayedOutput = 0;
    call.function      = function;
    call.delayedOutput = &delayedOutput;
    call.hasOutput     = hasOutput;
    functionQueue.push(call);

    if (call.hasOutput)
    {
        while (isThereDelayedFunctionCall() && !is_dll_function_call_complete())
        {

        }
    }

    return delayedOutput;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
template <typename... Input> double addDelayedFunctionCall(int function, int hasOutput, Input... input)
{
    delayedFunctionCall call;
    memset(&call, 0, sizeof(delayedFunctionCall));
    double delayedOutput = 0;
    call.function      = function;
    call.delayedOutput = &delayedOutput;
    call.hasOutput     = hasOutput;

    addDelayedFunctionCall_helper(0, &call, input...);
    functionQueue.push(call);

    if (call.hasOutput)
    {
        while (isThereDelayedFunctionCall() && !is_dll_function_call_complete())
        {

        }
    }

    return delayedOutput;
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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double sprite_get_texture(double spr, double subimg)
{
    return addDelayedFunctionCall(FP_sprite_get_texture, 1, spr, subimg);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
double sprite_add(const char* fname, double imgnumb, double removeback, double smooth, double xorig, double yorig)
{
    return addDelayedFunctionCall(FP_sprite_add, 1, fname, imgnumb, removeback, smooth, xorig, yorig);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void draw_sprite(double spr, double subimg, double x, double y)
{
    addDelayedFunctionCall(FP_draw_sprite, 0, spr, subimg, x, y);
}

typedef double (*dll_called_function)();

volatile dll_called_function function_to_call;
volatile delayedInput dll_input[14];
volatile int function_returned;
volatile double function_return_value;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void *dll_function_call_loop(void *vargp)
{
    while (1)
    {
        if (function_returned == 0)
        {
            if (function_to_call == (void*)gameLoopInit)
                function_return_value = gameLoopInit(dll_input[0].text);
            else if (function_to_call == (void*)gameLoopBeginStep)
                function_return_value = gameLoopBeginStep();
            else if (function_to_call == (void*)gameLoopStep)
                function_return_value = gameLoopStep();
            else if (function_to_call == (void*)gameLoopDraw)
                function_return_value = gameLoopDraw();

            function_returned = 1;
            function_to_call = NULL;
        }
    }
    return NULL;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double prime_argument_real(double index, double value)
{
    dll_input[(int)index].number = value;
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double prime_argument_string(double index, char* value)
{
    dll_input[(int)index].text = (char*) malloc((strlen(value) + 1)*sizeof(char));
    strcpy(dll_input[(int)index].text, value);
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double call_dll_function(double function_pointer)
{
    function_to_call = (dll_called_function)(int)function_pointer;
    function_returned = 0;

    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double is_dll_function_call_complete()
{
    return function_returned;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
GMEXPORT double init_dll_function_call_loop()
{
    function_returned = 1;
    function_to_call = NULL;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, dll_function_call_loop, NULL);

    return 0;
}
