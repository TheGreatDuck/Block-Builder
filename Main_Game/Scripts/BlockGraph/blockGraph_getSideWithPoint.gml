var p1x;
var p1y;
var p1z;

var p2x;
var p2y;
var p2z;

var p3x;
var p3y;
var p3z;

var p4x;
var p4y;
var p4z;

var vx;
var vy;
var vz;

p1x = obj_blockGraph.blockGraph[argument[0],Block3D_v1x];
p1y = obj_blockGraph.blockGraph[argument[0],Block3D_v1y];
p1z = obj_blockGraph.blockGraph[argument[0],Block3D_v1z];

p2x = obj_blockGraph.blockGraph[argument[0],Block3D_v2x];
p2y = obj_blockGraph.blockGraph[argument[0],Block3D_v2y];
p2z = obj_blockGraph.blockGraph[argument[0],Block3D_v2z];

p3x = obj_blockGraph.blockGraph[argument[0],Block3D_v3x];
p3y = obj_blockGraph.blockGraph[argument[0],Block3D_v3y];
p3z = obj_blockGraph.blockGraph[argument[0],Block3D_v3z];

p4x = obj_blockGraph.blockGraph[argument[0],Block3D_v4x];
p4y = obj_blockGraph.blockGraph[argument[0],Block3D_v4y];
p4z = obj_blockGraph.blockGraph[argument[0],Block3D_v4z];

vx = argument[1];
vy = argument[2];
vz = argument[3];

if ((p1x + p3x)/2 == vx && (p1y + p3y)/2 == vy && (p1z + p3z)/2 == vz)
{
    return 0;
}

if ((p4x + p3x)/2 == vx && (p4y + p3y)/2 == vy && (p4z + p3z)/2 == vz)
{
    return 1;
}

if ((p2x + p4x)/2 == vx && (p2y + p4y)/2 == vy && (p2z + p4z)/2 == vz)
{
    return 2;
}

if ((p1x + p2x)/2 == vx && (p1y + p2y)/2 == vy && (p1z + p2z)/2 == vz)
{
    return 3;
}

return -1;
