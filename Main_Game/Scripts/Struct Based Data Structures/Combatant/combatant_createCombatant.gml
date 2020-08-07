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
