#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "combatant.h"

combatant* combatant_createCombatant(double active, double instanceID, double objectType, double objectActivator)
{
    combatant* combat = (combatant*) malloc(sizeof(combatant));

    combat->active = active;
    combat->instanceID = instanceID;
    combat->objectType = objectType;
    combat->objectActivator = objectActivator;

    return combat;
}

void combatant_setActive(combatant* combat, double active)
{
    combat->active = active;
}

void combatant_setInstanceID(combatant* combat, double instanceID)
{
    combat->instanceID = instanceID;
}

void combatant_setObjectType(combatant* combat, double objectType)
{
    combat->objectType = objectType;
}

void combatant_setObjectActivator(combatant* combat, double objectActivator)
{
    combat->objectActivator = objectActivator;
}

double combatant_getActive(combatant* combat)
{
    return combat->active;
}

double combatant_getInstanceID(combatant* combat)
{
    return combat->instanceID;
}

double combatant_getObjectType(combatant* combat)
{
    return combat->objectType;
}

double combatant_getObjectActivator(combatant* combat)
{
    return combat->objectActivator;
}

void combatant_deleteCombatant(combatant* combat)
{
    free(combat);
}
