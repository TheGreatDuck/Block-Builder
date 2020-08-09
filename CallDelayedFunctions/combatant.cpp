#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"

typedef struct combatant
{
    double active;
    double instanceID;
    double objectType;
    double objectActivator;
} combatant;

GMEXPORT double combatant_createCombatant()
{
    // active
    // instance ID
    // objectType
    // objectActivator

    argument[4] = mm_malloc(4);

    combatant_setActive(argument[4],argument[0]);
    combatant_setInstanceID(argument[4],argument[1]);
    combatant_setObjectType(argument[4],argument[2]);
    combatant_setObjectActivator(argument[4],argument[3]);

    return argument[4];
}

GMEXPORT double combatant_setActive()
{
    HEAP_SPACE[argument[0]] = argument[1];
}

GMEXPORT double combatant_setInstanceID()
{
    HEAP_SPACE[argument[0]+1] = argument[1];
}

GMEXPORT double combatant_setObjectType()
{
    HEAP_SPACE[argument[0]+2] = argument[1];
}

GMEXPORT double combatant_setObjectActivator()
{
    HEAP_SPACE[argument[0]+3] = argument[1];
}

GMEXPORT double combatant_getActive()
{
    return HEAP_SPACE[argument[0]];
}

GMEXPORT double combatant_getInstanceID()
{
    return HEAP_SPACE[argument[0]+1];
}

GMEXPORT double combatant_getObjectType()
{
    return HEAP_SPACE[argument[0]+2];
}

GMEXPORT double combatant_getObjectActivator()
{
    return HEAP_SPACE[argument[0]+3];
}

GMEXPORT double combatant_deleteCombatant()
{
    mm_free(argument[0]);
}
