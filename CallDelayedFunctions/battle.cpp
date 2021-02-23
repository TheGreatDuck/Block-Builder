#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.hpp"
#include "linkedCycle.hpp"
#include "entity.hpp"

#if 0
typedef struct battleManager
{
    linkedCycle* battleCycle;
} battleManager;

void battle_manageTurn(battleManager* battle)
{
    entity* entityData = (entity*)getCurrentData(battle->battleCycle);

    if (entityData == NULL)
    {
        blockGraph_updateBlockGraphWithList();
        next(battle->battleCycle);
        entityData = (entity*)getCurrentData(battle->battleCycle);
        if (entityData != NULL)
            entityData->turnActive = 1;

    }

    if (entityData->turnActive)
    {
        entityTypeList[worldID][entityData->typeID].stepEvent(entityData, gameControl);
    } else
    {
        next(battle->battleCycle);
        entityData = (entity*)getCurrentData(battle->battleCycle);
        if (entityData != NULL)
            entityData->turnActive = 1;
        if (entityData->alive)
        {
            //entity is still alive
            entityTypeList[worldID][entityData->typeID].stepEvent(entityData, gameControl);
        } else
        {
            //entity was defeated
            next(battle->battleCycle);
            if (entityData != NULL)
            {
                removeBeforeCurrent(battle->battleCycle);
            }
        }
    }
}

void battle_initialize(battleManager* battle)
{
    battle->battleCycle = createCycle();

    with (obj_idleBasic)
    {
        with (obj_battleManager)
        {
            insertAfterCurrent(battleCycle,combatant_createCombatant(0,other.id,other.objectType,other.objectActivator));
        }
    }
}
#endif
