argument[2] = vector_getY(argument[0])*vector_getZ(argument[1]) - vector_getZ(argument[0])*vector_getY(argument[1]);
argument[3] = vector_getZ(argument[0])*vector_getX(argument[1]) - vector_getX(argument[0])*vector_getZ(argument[1]);
argument[4] = vector_getX(argument[0])*vector_getY(argument[1]) - vector_getY(argument[0])*vector_getX(argument[1]);

return vector_createVector(argument[2],argument[3],argument[4]);
