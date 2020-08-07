//point 1 x
//point 1 y
//point 1 z
//point 2 x
//point 2 y
//point 2 z
//point 3 x
//point 3 y
//point 3 z
//point 4 x
//point 4 y
//point 4 z
//blockType
//removable

argument[14] = mm_malloc(18);
square_setPointOne(argument[14],argument[0],argument[1],argument[2]);
square_setPointTwo(argument[14],argument[3],argument[4],argument[5]);
square_setPointThree(argument[14],argument[6],argument[7],argument[8]);
square_setPointFour(argument[14],argument[9],argument[10],argument[11]);
square_setAdjacentOne(argument[14],-1);
square_setAdjacentTwo(argument[14],-1);
square_setAdjacentThree(argument[14],-1);
square_setAdjacentFour(argument[14],-1);
square_setBlockType(argument[14],argument[12]);
square_setRemovable(argument[14],argument[13]);
return argument[14];
