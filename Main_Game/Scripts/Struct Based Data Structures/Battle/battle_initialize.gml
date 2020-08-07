battleCycle = linkedCycle_createCycle(combatant_deleteCombatant);

with (obj_idleBasic)
{
    with (obj_battleManager)
    {
        linkedCycle_insertAfterCurrent(battleCycle,combatant_createCombatant(0,other.id,other.objectType,other.objectActivator));
    }
}

battleBegun = true;
