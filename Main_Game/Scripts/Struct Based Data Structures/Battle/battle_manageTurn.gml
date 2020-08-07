combatantData = linkedCycle_getCurrentData(battleCycle);

if (combatant_getActive(combatantData) == 0)
{
    if (instance_exists(combatant_getInstanceID(combatantData)))
    {
        //entity is still alive
        combatant_setActive(combatantData,1);
        with (combatant_getInstanceID(combatantData))
        {
            instance_change(objectType,false);
        }
    } else
    {
        //entity was defeated
        linkedCycle_next(battleCycle);
        linkedCycle_removeBeforeCurrent(battleCycle);
    }
} else if (combatant_getActive(combatantData) == 1)
{
    if (instance_number(combatant_getObjectType(combatantData)) == 1)
    {
        with (combatant_getObjectType(combatantData))
        {
            with (obj_battleManager)
            {
                if (other.attackCompleted == true)
                {
                    other.changeBack = true;
                    turnCompleted = true;
                }
            }
        }
        if (turnCompleted)
        {
            combatant_setActive(combatantData,0);
            linkedCycle_next(battleCycle);
            turnCompleted = false;
        }
    }
}
