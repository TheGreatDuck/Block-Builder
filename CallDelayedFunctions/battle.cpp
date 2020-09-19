#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "combatant.h"
#include "linkedCycle.h"

typedef struct battleManager
{
    linkedCycle* battleCycle;
} battleManager;

void battle_manageTurn(battleManager* battle)
{
    combatant* combatantData = (combatant*)(int)getCurrentData(battle->battleCycle);

    if (combatant_getActive(combatantData) == 0)
    {
        if (1)//instance_exists(combatant_getInstanceID(combatantData)))
        {
            //entity is still alive
            combatant_setActive(combatantData,1);
            /*with (combatant_getInstanceID(combatantData))
            {
                instance_change(objectType,false);
            }*/
        } else
        {
            //entity was defeated
            next(battle->battleCycle);
            //removeBeforeCurrent(battle->battleCycle);
        }
    } else if (combatant_getActive(combatantData) == 1)
    {
        if (1)//instance_number(combatant_getObjectType(combatantData)) == 1)
        {
            int turnCompleted = 0;
            /*with (combatant_getObjectType(combatantData))
            {
                with (obj_battleManager)
                {
                    if (other.attackCompleted == true)
                    {
                        other.changeBack = true;
                        turnCompleted = true;
                    }
                }
            }*/
            if (turnCompleted)
            {
                combatant_setActive(combatantData,0);
                next(battle->battleCycle);
            }
        }
    }
}

void battle_initialize(battleManager* battle)
{
    battle->battleCycle = createCycle(1.0);//combatant_deleteCombatant);

    /*with (obj_idleBasic)
    {
        with (obj_battleManager)
        {
            insertAfterCurrent(battleCycle,combatant_createCombatant(0,other.id,other.objectType,other.objectActivator));
        }
    }*/
}
