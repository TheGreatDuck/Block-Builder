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

var centerX;
var centerY;
var centerZ;

var side0X;
var side0Y;
var side0Z;

var side1X;
var side1Y;
var side1Z;

var side2X;
var side2Y;
var side2Z;

var side3X;
var side3Y;
var side3Z;

var dir0X;
var dir0Y;
var dir0Z;

var dir1X;
var dir1Y;
var dir1Z;

var dir2X;
var dir2Y;
var dir2Z;

var dir3X;
var dir3Y;
var dir3Z;

var n0;
var n1;
var n2;
var n3;

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

centerX = (p1x + p2x + p3x + p4x)/4;
centerY = (p1y + p2y + p3y + p4y)/4;
centerZ = (p1z + p2z + p3z + p4z)/4;

side0X = (p1x + p3x)/2;
side0Y = (p1y + p3y)/2;
side0Z = (p1z + p3z)/2;

side1X = (p4x + p3x)/2;
side1Y = (p4y + p3y)/2;
side1Z = (p4z + p3z)/2;

side2X = (p2x + p4x)/2;
side2Y = (p2y + p4y)/2;
side2Z = (p2z + p4z)/2;

side3X = (p1x + p2x)/2;
side3Y = (p1y + p2y)/2;
side3Z = (p1z + p2z)/2;

dir0X = side0X - centerX;
dir0Y = side0Y - centerY;
dir0Z = side0Z - centerZ;

dir1X = side1X - centerX;
dir1Y = side1Y - centerY;
dir1Z = side1Z - centerZ;

dir2X = side2X - centerX;
dir2Y = side2Y - centerY;
dir2Z = side2Z - centerZ;

dir3X = side3X - centerX;
dir3Y = side3Y - centerY;
dir3Z = side3Z - centerZ;

n0 = sqrt((dir0X*dir0X) + (dir0Y*dir0Y) + (dir0Z*dir0Z));
n1 = sqrt((dir1X*dir1X) + (dir1Y*dir1Y) + (dir1Z*dir1Z));
n2 = sqrt((dir2X*dir2X) + (dir2Y*dir2Y) + (dir2Z*dir2Z));
n3 = sqrt((dir3X*dir3X) + (dir3Y*dir3Y) + (dir3Z*dir3Z));

dir0X /= n0;
dir0Y /= n0;
dir0Z /= n0;

dir1X /= n1;
dir1Y /= n1;
dir1Z /= n1;

dir2X /= n2;
dir2Y /= n2;
dir2Z /= n2;

dir3X /= n3;
dir3Y /= n3;
dir3Z /= n3;

arc0 = arccos(dir0X*vx + dir0Y*vy + dir0Z*vz);
arc1 = arccos(dir1X*vx + dir1Y*vy + dir1Z*vz);
arc2 = arccos(dir2X*vx + dir2Y*vy + dir2Z*vz);
arc3 = arccos(dir3X*vx + dir3Y*vy + dir3Z*vz);

if (arc0 <= arc1 && arc0 <= arc2 && arc0 <= arc3)
{
    return 0;
}

if (arc1 <= arc0 && arc1 <= arc2 && arc1 <= arc3)
{
    return 1;
}

if (arc2 <= arc0 && arc2 <= arc1 && arc2 <= arc3)
{
    return 2;
}

if (arc3 <= arc0 && arc3 <= arc1 && arc3 <= arc2)
{
    return 3;
}

show_message("something strange");
return -1;
