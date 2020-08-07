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
