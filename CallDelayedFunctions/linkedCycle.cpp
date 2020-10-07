#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.hpp"
#include "linkedCycle.hpp"

static linkedNode* createNode()
{
    linkedNode* node     = (linkedNode*) malloc(sizeof(linkedNode));
    node->data           = 0;
    node->next           = NULL;
    node->previous       = NULL;
    return node;
}

static void deleteNode(linkedNode* node)
{
    free(node);
}

linkedCycle* createCycle()
{
    linkedCycle* cycle = (linkedCycle*) malloc(sizeof(linkedCycle));
    cycle->current        = NULL;
    cycle->length         = 0;
    return cycle;
}

void insertAfterCurrent(linkedCycle* cycle, void* data)
{
    linkedNode* node = createNode();

    node->data = data;

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

void* getCurrentData(linkedCycle* cycle)
{
    return cycle->current->data;
}

void next(linkedCycle* cycle)
{
    cycle->current = cycle->current->next;
}

void previous(linkedCycle* cycle)
{
    cycle->current = cycle->current->previous;
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
