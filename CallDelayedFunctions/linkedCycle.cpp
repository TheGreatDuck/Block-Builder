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

GMEXPORT double getData(double node)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    return node_pointer->data;
}

GMEXPORT double getNext(double node, double next)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    return (double)(int)node_pointer->next;
}

GMEXPORT double getPrevious(double node, double previous)
{
    linkedNode* node_pointer = (linkedNode*)(int)node;
    return (double)(int)node_pointer->previous;
}
