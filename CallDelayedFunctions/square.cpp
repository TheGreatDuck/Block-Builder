#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"

typedef struct square
{
    double point_1_x;
    double point_1_y;
    double point_1_z;
    double point_2_x;
    double point_2_y;
    double point_2_z;
    double point_3_x;
    double point_3_y;
    double point_3_z;
    double point_4_x;
    double point_4_y;
    double point_4_z;
    double blockType;
    double removable;
} square;

GMEXPORT double square_createSquare()
{
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
}

GMEXPORT double square_setPointOne()
{
HEAP_SPACE[argument[0]] = argument[1];
HEAP_SPACE[argument[0]+1] = argument[2];
HEAP_SPACE[argument[0]+2] = argument[3];
}

GMEXPORT double square_setPointTwo()
{
HEAP_SPACE[argument[0]+3] = argument[1];
HEAP_SPACE[argument[0]+4] = argument[2];
HEAP_SPACE[argument[0]+5] = argument[3];
}

GMEXPORT double square_setPointThree()
{
HEAP_SPACE[argument[0]+6] = argument[1];
HEAP_SPACE[argument[0]+7] = argument[2];
HEAP_SPACE[argument[0]+8] = argument[3];
}

GMEXPORT double square_setPointFour()
{
HEAP_SPACE[argument[0]+9] = argument[1];
HEAP_SPACE[argument[0]+10] = argument[2];
HEAP_SPACE[argument[0]+11] = argument[3];
}

GMEXPORT double square_setAdjacentOne()
{
HEAP_SPACE[argument[0]+12] = argument[1];
}

GMEXPORT double square_setAdjacentTwo()
{
HEAP_SPACE[argument[0]+13] = argument[1];
}

GMEXPORT double square_setAdjacentThree()
{
HEAP_SPACE[argument[0]+14] = argument[1];
}

GMEXPORT double square_setAdjacentFour()
{
HEAP_SPACE[argument[0]+15] = argument[1];
}

GMEXPORT double square_setBlockType()
{
HEAP_SPACE[argument[0]+16] = argument[1];
}

GMEXPORT double square_setRemovable()
{
HEAP_SPACE[argument[0]+17] = argument[1];
}

GMEXPORT double square_getPointOne_x()
{
return HEAP_SPACE[argument[0]];
}

GMEXPORT double square_getPointOne_y()
{
return HEAP_SPACE[argument[0]+1];
}

GMEXPORT double square_getPointOne_z()
{
return HEAP_SPACE[argument[0]+2];
}

GMEXPORT double square_getPointTwo_x()
{
return HEAP_SPACE[argument[0]+3];
}

GMEXPORT double square_getPointTwo_y()
{
return HEAP_SPACE[argument[0]+4];
}

GMEXPORT double square_getPointTwo_z()
{
return HEAP_SPACE[argument[0]+5];
}

GMEXPORT double square_getPointThree_x()
{
return HEAP_SPACE[argument[0]+6];
}

GMEXPORT double square_getPointThree_y()
{
return HEAP_SPACE[argument[0]+7];
}

GMEXPORT double square_getPointThree_z()
{
return HEAP_SPACE[argument[0]+8];
}

GMEXPORT double square_getPointFour_x()
{
return HEAP_SPACE[argument[0]+9];
}

GMEXPORT double square_getPointFour_y()
{
return HEAP_SPACE[argument[0]+10];
}

GMEXPORT double square_getPointFour_z()
{
return HEAP_SPACE[argument[0]+11];
}

GMEXPORT double square_getAdjacentOne()
{
return HEAP_SPACE[argument[0]+12];
}

GMEXPORT double square_getAdjacentTwo()
{
return HEAP_SPACE[argument[0]+13];
}

GMEXPORT double square_getAdjacentThree()
{
return HEAP_SPACE[argument[0]+14];
}

GMEXPORT double square_getAdjacentFour()
{
return HEAP_SPACE[argument[0]+15];
}

GMEXPORT double square_getBlockType()
{
return HEAP_SPACE[argument[0]+16];
}

GMEXPORT double square_getRemovable()
{
return HEAP_SPACE[argument[0]+17];
}

GMEXPORT double square_blockArithmetic()
{
var s1;
var s2;
var s3;
var s4;

s1 = square_getAdjacentOne(argument[0]);
s2 = square_getAdjacentTwo(argument[0]);
s3 = square_getAdjacentThree(argument[0]);
s4 = square_getAdjacentFour(argument[0]);

var b1;
var b2;
var b3;
var b4;

if (s1 != -1)
{
    b1 = square_getBlockType(s1);
} else
{
    b1 = -1;
}

if (s2 != -1)
{
    b2 = square_getBlockType(s2);
} else
{
    b2 = -1;
}

if (s3 != -1)
{
    b3 = square_getBlockType(s3);
} else
{
    b3 = -1;
}

if (s4 != -1)
{
    b4 = square_getBlockType(s4);
} else
{
    b4 = -1;
}

return scr_changeBlock(square_getBlockType(argument[0]),b1,b2,b3,b4);
}
