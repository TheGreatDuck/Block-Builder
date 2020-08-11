#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"

typedef struct player3D
{
    unsigned int currentSpace;
} player3D;

GMEXPORT double player3D_moveInDirection(double double_player, double sideMoving)
{
    player3D* player = (player3D*)(int)double_player;

    int proposedSpace = -1;

    if (sideMoving == 0)
    {
        proposedSpace = blkGph->blockGraph[player->currentSpace].adj1;
    } else if (sideMoving == 1)
    {
        proposedSpace = blkGph->blockGraph[player->currentSpace].adj2;
    } else if (sideMoving == 2)
    {
        proposedSpace = blkGph->blockGraph[player->currentSpace].adj3;
    } else if (sideMoving == 3)
    {
        proposedSpace = blkGph->blockGraph[player->currentSpace].adj4;
    }

    if (proposedSpace != -1)
    {
        if ((blkGph->blockGraph[proposedSpace].type > 3 && blkGph->blockGraph[proposedSpace].type < 7) || (blkGph->blockGraph[proposedSpace].type > 7 && blkGph->blockGraph[proposedSpace].type < 11))
        {
            double sideX = (blkGph->blockGraph[player->currentSpace,Block3D_v1x + 3*((sideMoving % 3) + sign(sideMoving))] + blkGph->blockGraph[player->currentSpace,Block3D_v1x + 3*((((sideMoving+1) % 4) % 3) + sign(((sideMoving+1) % 4)))])/2;
            double sideY = (blkGph->blockGraph[player->currentSpace,Block3D_v1y + 3*((sideMoving % 3) + sign(sideMoving))] + blkGph->blockGraph[player->currentSpace,Block3D_v1y + 3*((((sideMoving+1) % 4) % 3) + sign(((sideMoving+1) % 4)))])/2;
            double sideZ = (blkGph->blockGraph[player->currentSpace,Block3D_v1z + 3*((sideMoving % 3) + sign(sideMoving))] + blkGph->blockGraph[player->currentSpace,Block3D_v1z + 3*((((sideMoving+1) % 4) % 3) + sign(((sideMoving+1) % 4)))])/2;
            movingSpace = proposedSpace;
            movingSideOne = sideMoving;
            movingSideTwo = blockGraph_getSideWithPoint(proposedSpace,sideX,sideY,sideZ);
            if ((sideFacing - sideMoving + 4) % 4 == 0)//up
            {
                sideFacingAfter = (movingSideTwo + 2) % 4;
            } else if ((sideFacing - sideMoving + 4) % 4 == 3)//left
            {
                sideFacingAfter = (movingSideTwo + 1) % 4;
            } else if ((sideFacing - sideMoving + 4) % 4 == 1)//right
            {
                sideFacingAfter = (movingSideTwo + 3) % 4;
            } else if ((sideFacing - sideMoving + 4) % 4 == 2)//down
            {
                sideFacingAfter = (movingSideTwo + 0) % 4;
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
}
