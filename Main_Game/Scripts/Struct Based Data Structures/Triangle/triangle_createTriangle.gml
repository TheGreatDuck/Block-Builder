//point 1
//point 2
//point 3
//adjacent triangle 1
//adjacent triangle 2
//adjacent triangle 3

argument[6] = mm_malloc(6);
triangle_setPointOne(argument[6],vector_copyVector(argument[0]));
triangle_setPointTwo(argument[6],vector_copyVector(argument[1]));
triangle_setPointThree(argument[6],vector_copyVector(argument[2]));
triangle_setAdjacentOne(argument[6],argument[3]);
triangle_setAdjacentTwo(argument[6],argument[4]);
triangle_setAdjacentThree(argument[6],argument[5]);
