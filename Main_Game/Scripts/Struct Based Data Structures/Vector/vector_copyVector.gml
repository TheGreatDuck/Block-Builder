argument[1] = mm_malloc(3);
vector_setX(argument[1],vector_getX(argument[0]));
vector_setY(argument[1],vector_getY(argument[0]));
vector_setZ(argument[1],vector_getZ(argument[0]));
return argument[1];
