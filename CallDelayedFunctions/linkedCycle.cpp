#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "linkedCycle.h"

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

linkedCycle* createCycle(double dataDestructor)
{
    linkedCycle* cycle = (linkedCycle*) malloc(sizeof(linkedCycle));
    cycle->current        = NULL;
    cycle->dataDestructor = dataDestructor;
    cycle->length         = 0;
    return cycle;
}

void insertAfterCurrent(linkedCycle* cycle, double data)
{
    linkedNode* node = createNode();

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

void removeAfterCurrent(linkedCycle* cycle)
{
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

int getLength(linkedCycle* cycle)
{
    return cycle->length;
}

double getCurrentData(linkedCycle* cycle)
{
    return cycle->current->data;
}

double next(linkedCycle* cycle)
{
    cycle->current = cycle->current->next;
}

linkedNode* getCurrentNode(linkedCycle* cycle)
{
    return cycle->current;
}

void setCurrentNode(linkedCycle* cycle, linkedNode* node)
{
    cycle->current = node;
}

void setLength(linkedCycle* cycle, double length)
{
    cycle->length = length;
}
