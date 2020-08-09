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

GMEXPORT double createNode()
{
    linkedNode* node     = (linkedNode*) malloc(sizeof(linkedNode));
    node->data           = 0;
    node->next           = NULL;
    node->previous       = NULL;
    node->dataDestructor = 0;
    return (double)(int)node;
}

GMEXPORT double setData(double node, double data)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    node_pointer->data = data;
    return 1.0;
}

GMEXPORT double setNext(double node, double next)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    node_pointer->next = (linkedNode*)(int)next;
    return 1.0;
}

GMEXPORT double setPrevious(double node, double previous)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    node_pointer->previous = (linkedNode*)(int)previous;
    return 1.0;
}

GMEXPORT double setDataDestructor(double node, double dataDestructor)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    node_pointer->dataDestructor = dataDestructor;
    return 1.0;
}

GMEXPORT double getData(double node)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    return node_pointer->data;
}

GMEXPORT double getNext(double node)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    return (double)(int)node_pointer->next;
}

GMEXPORT double getPrevious(double node)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    return (double)(int)node_pointer->previous;
}

GMEXPORT double getDataDestructor(double node)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    return node_pointer->dataDestructor;
}

GMEXPORT double deleteNode(double node)
{
    //script_execute(getDataDestructor(node), getData(node));
    free((linkedNode*)(int)node);
    return 1.0;
}

typedef struct linkedCycle
{
    linkedNode* current;
    double      dataDestructor;
    double      length;
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

GMEXPORT double removeAfterCurrent(double cycle)
{
    if (linkedCycle_getLength(argument[0]) > 1)
    {
        argument[1] = node_getNext(linkedCycle_getCurrentNode(argument[0]));

        node_setPrevious(node_getNext(argument[1]),node_getPrevious(argument[1]));
        node_setNext(node_getPrevious(argument[1]),node_getNext(argument[1]));

        deleteNode(argument[1]);
    } else if (linkedCycle_getLength(argument[0]) == 1)
    {
        node_deleteNode(linkedCycle_getCurrentNode(argument[0]));
        linkedCycle_setCurrentNode(argument[0], NULL);
    }

    linkedCycle_setLength(argument[0],linkedCycle_getLength(argument[0])-1);
}

GMEXPORT double getLength(double cycle)
{
    return HEAP_SPACE[argument[0]+2];
}

GMEXPORT double getCurrentData(double cycle)
{
    return getData(getCurrentNode(argument[0]));
}

GMEXPORT double next(double cycle)
{
    setCurrentNode(argument[0],node_getNext(getCurrentNode(argument[0])));
}

GMEXPORT double previous(double cycle)
{
    setCurrentNode(cycle,node_getPrevious(getCurrentNode(cycle)));
}

GMEXPORT double getCurrentNode(double cycle)
{
    return HEAP_SPACE[cycle];
}

GMEXPORT double getDataDestructor(double cycle)
{
    return HEAP_SPACE[cycle+1];
}

GMEXPORT double setCurrentNode(double cycle)
{
    HEAP_SPACE[cycle] = argument[1];
}

GMEXPORT double setDataDestructor(double cycle)
{
    HEAP_SPACE[cycle+1] = argument[1];
}

GMEXPORT double setLength(double cycle)
{
    HEAP_SPACE[cycle+2] = argument[1];
}
