#include "vector.h"
#include "entity.h"

GMEXPORT void  instantiate_entity(entity_callback_data* ecd);
GMEXPORT void* createEvent();
GMEXPORT void  drawEvent(entity* e);
GMEXPORT void  stepEvent(entity* e, controlSet gameControl);
