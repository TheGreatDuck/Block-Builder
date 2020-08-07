var s1;
var s2;
var s3;
var s4;

s1 = blockGraph[argument[0],Block3D_adj1];
s2 = blockGraph[argument[0],Block3D_adj2];
s3 = blockGraph[argument[0],Block3D_adj3];
s4 = blockGraph[argument[0],Block3D_adj4];

var b1;
var b2;
var b3;
var b4;

if (s1 != -1)
{
    b1 = blockGraph[s1,Block3D_type];
} else
{
    b1 = -1;
}

if (s2 != -1)
{
    b2 = blockGraph[s2,Block3D_type];
} else
{
    b2 = -1;
}

if (s3 != -1)
{
    b3 = blockGraph[s3,Block3D_type];
} else
{
    b3 = -1;
}

if (s4 != -1)
{
    b4 = blockGraph[s4,Block3D_type];
} else
{
    b4 = -1;
}

return scr_changeBlock(blockGraph[argument[0],Block3D_type],b1,b2,b3,b4);
