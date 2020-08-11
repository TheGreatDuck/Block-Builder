//spin += 1;
x = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1x]+obj_blockGraph.blockGraph[currentSpace,Block3D_v2x]+obj_blockGraph.blockGraph[currentSpace,Block3D_v3x]+obj_blockGraph.blockGraph[currentSpace,Block3D_v4x])/4;
y = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1y]+obj_blockGraph.blockGraph[currentSpace,Block3D_v2y]+obj_blockGraph.blockGraph[currentSpace,Block3D_v3y]+obj_blockGraph.blockGraph[currentSpace,Block3D_v4y])/4;
z = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1z]+obj_blockGraph.blockGraph[currentSpace,Block3D_v2z]+obj_blockGraph.blockGraph[currentSpace,Block3D_v3z]+obj_blockGraph.blockGraph[currentSpace,Block3D_v4z])/4;

dir1x = obj_blockGraph.blockGraph[currentSpace,Block3D_v3x] - obj_blockGraph.blockGraph[currentSpace,Block3D_v1x];
dir1y = obj_blockGraph.blockGraph[currentSpace,Block3D_v3y] - obj_blockGraph.blockGraph[currentSpace,Block3D_v1y];
dir1z = obj_blockGraph.blockGraph[currentSpace,Block3D_v3z] - obj_blockGraph.blockGraph[currentSpace,Block3D_v1z];

dir2x = obj_blockGraph.blockGraph[currentSpace,Block3D_v4x] - obj_blockGraph.blockGraph[currentSpace,Block3D_v1x];
dir2y = obj_blockGraph.blockGraph[currentSpace,Block3D_v4y] - obj_blockGraph.blockGraph[currentSpace,Block3D_v1y];
dir2z = obj_blockGraph.blockGraph[currentSpace,Block3D_v4z] - obj_blockGraph.blockGraph[currentSpace,Block3D_v1z];

nx = dir1y*dir2z - dir1z*dir2y;
ny = dir1z*dir2x - dir1x*dir2z;
nz = dir1x*dir2y - dir1y*dir2x;

norm = sqrt(nx*nx + ny*ny + nz*nz);
nx /= norm;
ny /= norm;
nz /= norm;

sideX = /*(obj_blockGraph.blockGraph[currentSpace,Block3D_v1x] + obj_blockGraph.blockGraph[currentSpace,Block3D_v3x])/2;*/(obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;
sideY = /*(obj_blockGraph.blockGraph[currentSpace,Block3D_v1y] + obj_blockGraph.blockGraph[currentSpace,Block3D_v3y])/2;*/(obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;
sideZ = /*(obj_blockGraph.blockGraph[currentSpace,Block3D_v1z] + obj_blockGraph.blockGraph[currentSpace,Block3D_v3z])/2;*/(obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;

dirX = sideX-x;
dirY = sideY-y;
dirZ = sideZ-z;

norm = sqrt(dirX*dirX + dirY*dirY + dirZ*dirZ);
dirX /= norm;
dirY /= norm;
dirZ /= norm;

/*sideX = (obj_blockGraph.blockGraph[currentSpace,Block3D_v3x] + obj_blockGraph.blockGraph[currentSpace,Block3D_v4x])/2;//(obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;
sideY = (obj_blockGraph.blockGraph[currentSpace,Block3D_v3y] + obj_blockGraph.blockGraph[currentSpace,Block3D_v4y])/2;//(obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;
sideZ = (obj_blockGraph.blockGraph[currentSpace,Block3D_v3z] + obj_blockGraph.blockGraph[currentSpace,Block3D_v4z])/2;//(obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;

axisX_x = sideX-x;
axisX_y = sideY-y;
axisX_z = sideZ-z;

norm = -sqrt(axisX_x*axisX_x + axisX_y*axisX_y + axisX_z*axisX_z);
axisX_x /= norm;
axisX_y /= norm;
axisX_z /= norm;*/

axisX_x = (dirY*nz - dirZ*ny);
axisX_y = (dirZ*nx - dirX*nz);
axisX_z = (dirX*ny - dirY*nx);

//angle = arccos(nz)*180/pi;
