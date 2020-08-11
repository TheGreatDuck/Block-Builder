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

sideX = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;
sideY = /*(obj_blockGraph.blockGraph[currentSpace,Block3D_v1y] + obj_blockGraph.blockGraph[currentSpace,Block3D_v3y])/2;*/(obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;
sideZ = /*(obj_blockGraph.blockGraph[currentSpace,Block3D_v1z] + obj_blockGraph.blockGraph[currentSpace,Block3D_v3z])/2;*/(obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((sideFacing mod 3) + sign(sideFacing))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((((sideFacing+1) mod 4) mod 3) + sign((sideFacing+1) mod 4))])/2;

dirX = sideX-x;
dirY = sideY-y;
dirZ = sideZ-z;

norm = sqrt(dirX*dirX + dirY*dirY + dirZ*dirZ);
dirX /= norm;
dirY /= norm;
dirZ /= norm;

axisX_x = (dirY*nz - dirZ*ny);
axisX_y = (dirZ*nx - dirX*nz);
axisX_z = (dirX*ny - dirY*nx);

if (global.gameControlPressed[control_moveUp])
{
    if (moving == 0)
    {
        player3D_moveInDirection((sideFacing + 0) mod 4);
    }
}

if (global.gameControlPressed[control_moveRight])
{
    if (moving == 0)
    {
        player3D_moveInDirection((sideFacing + 1) mod 4);
    }
}

if (global.gameControlPressed[control_moveDown])
{
    if (moving == 0)
    {
        player3D_moveInDirection((sideFacing + 2) mod 4);
    }
}

if (global.gameControlPressed[control_moveLeft])
{
    if (moving == 0)
    {
        player3D_moveInDirection((sideFacing + 3) mod 4);
    }
}

if (global.gameControlPress[control_blockLeft])
{
    global.type = (global.type - 1 + (numberOfBlocks_3D - 1)) mod (numberOfBlocks_3D-1);
    blockLeftPressed = true;
}

if (global.gameControlPress[control_blockRight])
{
    global.type = (global.type + 1 + (numberOfBlocks_3D - 1)) mod (numberOfBlocks_3D-1);
    blockRightPressed = true;
}

if (global.gameControlPress[control_pause])
{
    global.gameControlPress[control_pause] = false;
    room_persistent=true;
    global.returnTo=room;
    d3d_end();
    room_goto(rm_menu);
}

if (global.gameControlPress[control_itemOne])
{
    global.gameControlPress[control_itemOne] = false;
    if (global.itemOne == 1)
    {
        instance_create(x,y,obj_blockEditor3D);
        obj_blockEditor3D.currentSpace = currentSpace;
        instance_change(obj_player3DStalling,false);
    }
}

if (global.gameControlPress[control_itemTwo])
{
    global.gameControlPress[control_itemTwo] = false;
    if (global.itemTwo == 1)
    {
        instance_create(x,y,obj_blockEditor3D);
        obj_blockEditor3D.currentSpace = currentSpace;
        instance_change(obj_player3DStalling,false);
    }
}

if (moving == 1)
{
    motion += 1;
    
    movingSide = (motion <= 4)*movingSideOne + (motion > 4)*movingSideTwo;
    
    sideX = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((movingSide mod 3) + sign(movingSide))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((((movingSide+1) mod 4) mod 3) + sign(((movingSide+1) mod 4)))])/2;
    sideY = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((movingSide mod 3) + sign(movingSide))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((((movingSide+1) mod 4) mod 3) + sign(((movingSide+1) mod 4)))])/2;
    sideZ = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((movingSide mod 3) + sign(movingSide))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((((movingSide+1) mod 4) mod 3) + sign(((movingSide+1) mod 4)))])/2;
    
    x = (motion <= 4)*((4-motion)*x + motion*sideX)/4 + (motion > 4)*((motion-5)*x + (9-motion)*sideX)/4;
    y = (motion <= 4)*((4-motion)*y + motion*sideY)/4 + (motion > 4)*((motion-5)*y + (9-motion)*sideY)/4;
    z = (motion <= 4)*((4-motion)*z + motion*sideZ)/4 + (motion > 4)*((motion-5)*z + (9-motion)*sideZ)/4;
    
    if (motion == 4)
    {
        currentSpace = movingSpace;
        sideFacing = sideFacingAfter;
    }
    
    if (motion == 8)
    {
        if (obj_blockGraph.blockGraph[currentSpace,Block3D_type] == 5)
        {
            player3D_moveInDirection((movingSide + 2) mod 4);
        } else
        {
            moving = 0;
        }
        
        motion = 0;
    }
}