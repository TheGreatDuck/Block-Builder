typedef struct combatant
{
    double active;
    double instanceID;
    double objectType;
    double objectActivator;
} combatant;

combatant* combatant_createCombatant(double active, double instanceID, double objectType, double objectActivator);
void combatant_setActive(combatant* combat, double active);
void combatant_setInstanceID(combatant* combat, double instanceID);
void combatant_setObjectType(combatant* combat, double objectType);
void combatant_setObjectActivator(combatant* combat, double objectActivator);
double combatant_getActive(combatant* combat);
double combatant_getInstanceID(combatant* combat);
double combatant_getObjectType(combatant* combat);
double combatant_getObjectActivator(combatant* combat);
void combatant_deleteCombatant(combatant* combat);
