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

GMEXPORT double combatant_createCombatant(double active, double instanceID, double objectType, double objectActivator)
{
    combatant* combat = (combatant*) malloc(sizeof(combatant));

    combat->active = active;
    combat->instanceID = instanceID;
    combat->objectType = objectType;
    combat->objectActivator = objectActivator;

    return (double)(int)combat;
}

GMEXPORT double combatant_setActive(double double_combat, double active)
{
    combatant* combat = (combatant*)(int)double_combat;
    combat->active = active;
    return 0.1;
}

GMEXPORT double combatant_setInstanceID(double double_combat, double instanceID)
{
    combatant* combat = (combatant*)(int)double_combat;
    combat->instanceID = instanceID;
    return 0.1;
}

GMEXPORT double combatant_setObjectType(double double_combat, double objectType)
{
    combatant* combat = (combatant*)(int)double_combat;
    combat->objectType = objectType;
    return 0.1;
}

GMEXPORT double combatant_setObjectActivator(double double_combat, double objectActivator)
{
    combatant* combat = (combatant*)(int)double_combat;
    combat->objectActivator = objectActivator;
    return 0.1;
}

GMEXPORT double combatant_getActive(double double_combat)
{
    combatant* combat = (combatant*)(int)double_combat;
    return combat->active;
}

GMEXPORT double combatant_getInstanceID(double double_combat)
{
    combatant* combat = (combatant*)(int)double_combat;
    return combat->instanceID;
}

GMEXPORT double combatant_getObjectType(double double_combat)
{
    combatant* combat = (combatant*)(int)double_combat;
    return combat->objectType;
}

GMEXPORT double combatant_getObjectActivator(double double_combat)
{
    combatant* combat = (combatant*)(int)double_combat;
    return combat->objectActivator;
}

GMEXPORT double combatant_deleteCombatant(double double_combat)
{
    free((combatant*)(int)double_combat);
}
