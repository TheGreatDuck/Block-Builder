argument[1] = triangle_getPointOne(argument[0]);
argument[2] = triangle_getPointTwo(argument[0]);
argument[3] = triangle_getPointThree(argument[0]);

argument[4] = vector_subtractVectors(argument[1],argument[2]);
argument[5] = vector_subtractVectors(argument[1],argument[3]);

argument[6] = vector_crossProduct(argument[4],argument[5]);

mm_free();
