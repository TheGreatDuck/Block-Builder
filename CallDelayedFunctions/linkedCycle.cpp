#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"

typedef struct linkedNode
{
    double      data;
    struct linkedNode* next;
    struct linkedNode* previous;
    double      dataDestructor;
} linkedNode;

static linkedNode* createNode()
{
    linkedNode* node     = (linkedNode*) malloc(sizeof(linkedNode));
    node->data           = 0;
    node->next           = NULL;
    node->previous       = NULL;
    node->dataDestructor = 0;
    return node;
}

static void deleteNode(linkedNode* node)
{
    //script_execute(node->dataDestructor, node->data);
    free(node);
}

typedef struct linkedCycle
{
    linkedNode* current;
    double      dataDestructor;
    int         length;
} linkedCycle;

GMEXPORT double createCycle(double dataDestructor)
{
    linkedCycle* cycle = (linkedCycle*) malloc(sizeof(linkedCycle));
    cycle->current        = NULL;
    cycle->dataDestructor = dataDestructor;
    cycle->length         = 0;
    return (double)(int)cycle;
}

GMEXPORT double insertAfterCurrent(double double_cycle, double data)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;
    linkedNode* node = (linkedNode*)(int)createNode();

    node->data = data;
    node->dataDestructor = cycle->dataDestructor;

    if (cycle->length == 0)
    {
        node->next     = node;
        node->previous = node;
        cycle->current = node;
    } else
    {
        linkedNode* current = cycle->current;
        linkedNode* next    = current->next;

        current->next  = node;
        next->previous = node;

        node->previous = current;
        node->next     = next;
    }

    cycle->length += 1;
}

GMEXPORT double removeAfterCurrent(double double_cycle)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;

    if (cycle->length > 1)
    {
        linkedNode* next = cycle->current->next;
        next->next->previous = next->previous;
        next->previous->next = next->next;
        deleteNode(next);
    } else if (cycle->length == 1)
    {
        deleteNode(cycle->current);
        cycle->current = NULL;
    }

    cycle->length -= 1;
}

GMEXPORT double getLength(double double_cycle)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;
    return cycle->length;
}

GMEXPORT double getCurrentData(double double_cycle)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;
    return cycle->current->data;
}

GMEXPORT double next(double double_cycle)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;
    cycle->current = cycle->current->next;
    return 1.0;
}

GMEXPORT double getCurrentNode(double double_cycle)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;
    return (double)(int)cycle->current;
}

GMEXPORT double setCurrentNode(double double_cycle, double node)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;
    cycle->current = (linkedNode*)(int)node;
    return 1.0;
}

GMEXPORT double setLength(double double_cycle, double length)
{
    linkedCycle* cycle = (linkedCycle*)(int)double_cycle;
    cycle->length = length;
    return 1.0;
}
