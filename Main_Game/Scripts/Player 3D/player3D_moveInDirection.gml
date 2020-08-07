var sideMoving;

sideMoving = argument[0];
proposedSpace = obj_blockGraph.blockGraph[currentSpace,Block3D_adj1 + sideMoving];

if (proposedSpace != -1)
{
    if ((obj_blockGraph.blockGraph[proposedSpace,Block3D_type] > 3 && obj_blockGraph.blockGraph[proposedSpace,Block3D_type] < 7) || (obj_blockGraph.blockGraph[proposedSpace,Block3D_type] > 7 && obj_blockGraph.blockGraph[proposedSpace,Block3D_type] < 11))
    {
        sideX = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((sideMoving mod 3) + sign(sideMoving))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1x + 3*((((sideMoving+1) mod 4) mod 3) + sign(((sideMoving+1) mod 4)))])/2;
        sideY = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((sideMoving mod 3) + sign(sideMoving))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1y + 3*((((sideMoving+1) mod 4) mod 3) + sign(((sideMoving+1) mod 4)))])/2;
        sideZ = (obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((sideMoving mod 3) + sign(sideMoving))] + obj_blockGraph.blockGraph[currentSpace,Block3D_v1z + 3*((((sideMoving+1) mod 4) mod 3) + sign(((sideMoving+1) mod 4)))])/2;
        movingSpace = proposedSpace;
        movingSideOne = sideMoving;
        movingSideTwo = blockGraph_getSideWithPoint(proposedSpace,sideX,sideY,sideZ);
        if ((sideFacing - sideMoving + 4) mod 4 == 0)//up
        {
            sideFacingAfter = (movingSideTwo + 2) mod 4;
        } else if ((sideFacing - sideMoving + 4) mod 4 == 3)//left
        {
            sideFacingAfter = (movingSideTwo + 1) mod 4;
        } else if ((sideFacing - sideMoving + 4) mod 4 == 1)//right
        {
            sideFacingAfter = (movingSideTwo + 3) mod 4;
        } else if ((sideFacing - sideMoving + 4) mod 4 == 2)//down
        {
            sideFacingAfter = (movingSideTwo + 0) mod 4;
        }
        moving = 1;
    } else
    {
        moving = 0;
    }
} else
{
    moving = 0;
}
