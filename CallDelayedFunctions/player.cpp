#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include <cmath>
#include "delayed_function_calls.h"
#include "blockGraph.h"
#include "blockAlchemy.h"
#include "controls.h"
#include "player.h"

GMEXPORT double d3d_transform_add_rotation_matrix(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
    double rot_x;
    double rot_y;
    double rot_z;
    double rot_angle;

    if ((a11 + a22 + a33 - 1)/2 > 1)
    {
        rot_angle = 0;
    } else if ((a11 + a22 + a33 - 1)/2 < -1)
    {
        rot_angle = M_PI;
    } else
    {
        rot_angle = acos((a11 + a22 + a33 - 1)/2);
    }

    if (sin(rot_angle) != 0)
    {
        rot_x = (a32 - a23)/(2*sin(rot_angle));
        rot_y = (a13 - a31)/(2*sin(rot_angle));
        rot_z = (a21 - a12)/(2*sin(rot_angle));
    } else if (cos(rot_angle) == 1)
    {
        rot_x = 0;
        rot_y = 0;
        rot_z = 1;
    } else
    {
        double rot_norm;
        rot_x = 2*a11 + 2;
        rot_y = a12 + a21;
        rot_z = a13 + a31;
        rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
        if (rot_norm == 0)
        {
            rot_x = a21 + a12;
            rot_y = 2*a22 + 2;
            rot_z = a32 + a23;
            rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
        }

        if (rot_norm == 0)
        {
            rot_x = a31 + a13;
            rot_y = a32 + a23;
            rot_z = 2*a33 + 2;
            rot_norm = sqrt(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
        }
        rot_x /= rot_norm;
        rot_y /= rot_norm;
        rot_z /= rot_norm;
    }

    rot_angle = (2*(rot_angle == M_PI) - 1)*rot_angle*(180/M_PI);
    d3d_transform_add_rotation_axis(rot_x,rot_y,rot_z,rot_angle);
}

player3D player;

GMEXPORT double player3D_moveInDirection(double double_sideMoving)
{
    int sideMoving = (int)double_sideMoving;

    int proposedSpace = blkGph->blockGraph[player.currentSpace].adj[sideMoving];

    if (proposedSpace != -1)
    {
        if ((blkGph->blockGraph[proposedSpace].type > 3 && blkGph->blockGraph[proposedSpace].type < 7) || (blkGph->blockGraph[proposedSpace].type > 7 && blkGph->blockGraph[proposedSpace].type < 11))
        {
            vector side;
            side.x = 0;
            side.y = 0;
            side.z = 0;

            if (sideMoving == 0)
            {
                side = (blkGph->blockGraph[player.currentSpace].v[1] + blkGph->blockGraph[player.currentSpace].v[3])/2;
            } else if (sideMoving == 1)
            {
                side = (blkGph->blockGraph[player.currentSpace].v[3] + blkGph->blockGraph[player.currentSpace].v[4])/2;
            } else if (sideMoving == 2)
            {
                side = (blkGph->blockGraph[player.currentSpace].v[4] + blkGph->blockGraph[player.currentSpace].v[2])/2;
            } else if (sideMoving == 3)
            {
                side = (blkGph->blockGraph[player.currentSpace].v[2] + blkGph->blockGraph[player.currentSpace].v[1])/2;
            }

            player.movingSpace = proposedSpace;
            player.movingSideOne = sideMoving;
            player.movingSideTwo = blockGraph_getSideWithPoint(proposedSpace,side.x,side.y,side.z);

            if ((player.sideFacing - sideMoving + 4) % 4 == 0)//up
            {
                player.sideFacingAfter = (player.movingSideTwo + 2) % 4;
            } else if ((player.sideFacing - sideMoving + 4) % 4 == 3)//left
            {
                player.sideFacingAfter = (player.movingSideTwo + 1) % 4;
            } else if ((player.sideFacing - sideMoving + 4) % 4 == 1)//right
            {
                player.sideFacingAfter = (player.movingSideTwo + 3) % 4;
            } else if ((player.sideFacing - sideMoving + 4) % 4 == 2)//down
            {
                player.sideFacingAfter = (player.movingSideTwo + 0) % 4;
            }
            player.moving = 1;
        } else
        {
            player.moving = 0;
        }
    } else
    {
        player.moving = 0;
    }

    return 1.0;
}

GMEXPORT double player3D_moveInDirectionWithoutCollision(double double_sideMoving)
{
    int sideMoving = (int)double_sideMoving;

    int proposedSpace = blkGph->blockGraph[player.currentSpace].adj[sideMoving];

    if (proposedSpace != -1)
    {
        double sideX = 0;
        double sideY = 0;
        double sideZ = 0;

        if (sideMoving == 0)
        {
            sideX = (blkGph->blockGraph[player.currentSpace].v[1].x + blkGph->blockGraph[player.currentSpace].v[3].x)/2;
            sideY = (blkGph->blockGraph[player.currentSpace].v[1].y + blkGph->blockGraph[player.currentSpace].v[3].y)/2;
            sideZ = (blkGph->blockGraph[player.currentSpace].v[1].z + blkGph->blockGraph[player.currentSpace].v[3].z)/2;
        } else if (sideMoving == 1)
        {
            sideX = (blkGph->blockGraph[player.currentSpace].v[3].x + blkGph->blockGraph[player.currentSpace].v[4].x)/2;
            sideY = (blkGph->blockGraph[player.currentSpace].v[3].y + blkGph->blockGraph[player.currentSpace].v[4].y)/2;
            sideZ = (blkGph->blockGraph[player.currentSpace].v[3].z + blkGph->blockGraph[player.currentSpace].v[4].z)/2;
        } else if (sideMoving == 2)
        {
            sideX = (blkGph->blockGraph[player.currentSpace].v[4].x + blkGph->blockGraph[player.currentSpace].v[2].x)/2;
            sideY = (blkGph->blockGraph[player.currentSpace].v[4].y + blkGph->blockGraph[player.currentSpace].v[2].y)/2;
            sideZ = (blkGph->blockGraph[player.currentSpace].v[4].z + blkGph->blockGraph[player.currentSpace].v[2].z)/2;
        } else if (sideMoving == 3)
        {
            sideX = (blkGph->blockGraph[player.currentSpace].v[2].x + blkGph->blockGraph[player.currentSpace].v[1].x)/2;
            sideY = (blkGph->blockGraph[player.currentSpace].v[2].y + blkGph->blockGraph[player.currentSpace].v[1].y)/2;
            sideZ = (blkGph->blockGraph[player.currentSpace].v[2].z + blkGph->blockGraph[player.currentSpace].v[1].z)/2;
        }

        player.movingSpace = proposedSpace;
        player.movingSideOne = sideMoving;
        player.movingSideTwo = blockGraph_getSideWithPoint(proposedSpace,sideX,sideY,sideZ);

        if ((player.sideFacing - sideMoving + 4) % 4 == 0)//up
        {
            player.sideFacingAfter = (player.movingSideTwo + 2) % 4;
        } else if ((player.sideFacing - sideMoving + 4) % 4 == 3)//left
        {
            player.sideFacingAfter = (player.movingSideTwo + 1) % 4;
        } else if ((player.sideFacing - sideMoving + 4) % 4 == 1)//right
        {
            player.sideFacingAfter = (player.movingSideTwo + 3) % 4;
        } else if ((player.sideFacing - sideMoving + 4) % 4 == 2)//down
        {
            player.sideFacingAfter = (player.movingSideTwo + 0) % 4;
        }
        player.moving = 1;
    } else
    {
        player.moving = 0;
    }
}

GMEXPORT double player3D_drawEvent()
{
    d3d_transform_set_identity();
    d3d_transform_add_rotation_matrix(player.axisX.x, player.dir.x, player.n.x,
                                      player.axisX.y, player.dir.y, player.n.y,
                                      player.axisX.z, player.dir.z, player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x, player.position.y, player.position.z);
    d3d_draw_ellipsoid(-1,-1,2,1,1,5,&player.texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,4);
    d3d_transform_add_rotation_matrix(player.axisX.x, player.dir.x, player.n.x,
                                      player.axisX.y, player.dir.y, player.n.y,
                                      player.axisX.z, player.dir.z, player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x, player.position.y, player.position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player.texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,4);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_cylinder(-0.5,-0.5,0,0.5,0.5,2,&player.texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,4);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player.texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,4);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_cylinder(-0.5,-0.5,0,0.5,0.5,2,&player.texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,2.5);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player.texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(-1,0,2.5);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(
                                 player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_cylinder(-0.5,-0.5,-2,0.5,0.5,0,&player.texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,2.5);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_ellipsoid(-0.5,-0.5,-0.5,0.5,0.5,0.5,&player.texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(1,0,2.5);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_cylinder(-0.5,-0.5,-2,0.5,0.5,0,&player.texBody,2,1,true,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(0,0,6);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_ellipsoid(-1,-1,-1,1,1,1,&player.texBody,2,1,60);

    d3d_transform_set_identity();
    d3d_transform_add_translation(0,0,6);
    d3d_transform_add_translation(-0.25,1,0.25);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_ellipsoid(-0.125,-0.125,-0.125,0.125,0.125,0.125,&player.texEye,2,1,60);


    d3d_transform_set_identity();
    d3d_transform_add_translation(0,0,6);
    d3d_transform_add_translation(0.25,1,0.25);
    d3d_transform_add_rotation_matrix(player.axisX.x,player.dir.x,player.n.x,
                                      player.axisX.y,player.dir.y,player.n.y,
                                      player.axisX.z,player.dir.z,player.n.z);
    d3d_transform_add_rotation_z(player.spin);
    d3d_transform_add_translation(player.position.x,player.position.y,player.position.z);
    d3d_draw_ellipsoid(-0.125,-0.125,-0.125,0.125,0.125,0.125,&player.texEye,2,1,60);

    d3d_transform_set_identity();
}

GMEXPORT double player3D_stepEvent()
{
    //spin += 1;
    player.position = (blkGph->blockGraph[player.currentSpace].v[1] + blkGph->blockGraph[player.currentSpace].v[2] + blkGph->blockGraph[player.currentSpace].v[3] + blkGph->blockGraph[player.currentSpace].v[4])/4;

    vector dir1 = blkGph->blockGraph[player.currentSpace].v[3] - blkGph->blockGraph[player.currentSpace].v[1];
    vector dir2 = blkGph->blockGraph[player.currentSpace].v[4] - blkGph->blockGraph[player.currentSpace].v[1];

    player.n.x = dir1.y*dir2.z - dir1.z*dir2.y;
    player.n.y = dir1.z*dir2.x - dir1.x*dir2.z;
    player.n.z = dir1.x*dir2.y - dir1.y*dir2.x;

    double norm = sqrt(player.n*player.n);
    player.n = (1/norm)*player.n;

    vector side;
    side.x = 0;
    side.y = 0;
    side.z = 0;

    if (player.sideFacing == 0)
    {
        side = (blkGph->blockGraph[player.currentSpace].v[1] + blkGph->blockGraph[player.currentSpace].v[3])/2;
    } else if (player.sideFacing == 1)
    {
        side = (blkGph->blockGraph[player.currentSpace].v[3] + blkGph->blockGraph[player.currentSpace].v[4])/2;
    } else if (player.sideFacing == 2)
    {
        side = (blkGph->blockGraph[player.currentSpace].v[4] + blkGph->blockGraph[player.currentSpace].v[2])/2;
    } else if (player.sideFacing == 3)
    {
        side = (blkGph->blockGraph[player.currentSpace].v[2] + blkGph->blockGraph[player.currentSpace].v[1])/2;
    }

    player.dir = side-player.position;

    norm = sqrt(player.dir*player.dir);
    player.dir = (1/norm)*player.dir;

    player.axisX.x = (player.dir.y*player.n.z - player.dir.z*player.n.y);
    player.axisX.y = (player.dir.z*player.n.x - player.dir.x*player.n.z);
    player.axisX.z = (player.dir.x*player.n.y - player.dir.y*player.n.x);

    if (gameControl.control_moveUp.gameControlPressed)
    {
        if (player.moving == 0)
        {
            player3D_moveInDirection((player.sideFacing + 0) % 4);
        }
    }

    if (gameControl.control_moveRight.gameControlPressed)
    {
        if (player.moving == 0)
        {
            player3D_moveInDirection((player.sideFacing + 1) % 4);
        }
    }

    if (gameControl.control_moveDown.gameControlPressed)
    {
        if (player.moving == 0)
        {
            player3D_moveInDirection((player.sideFacing + 2) % 4);
        }
    }

    if (gameControl.control_moveLeft.gameControlPressed)
    {
        if (player.moving == 0)
        {
            player3D_moveInDirection((player.sideFacing + 3) % 4);
        }
    }

    if (gameControl.control_blockLeft.gameControlPress)
    {
        player.type = (player.type - 1 + ((int)numberOfBlocks_3D - 1)) % ((int)numberOfBlocks_3D-1);
        player.blockLeftPressed = 1;
    }

    if (gameControl.control_blockRight.gameControlPress)
    {
        player.type = (player.type + 1 + ((int)numberOfBlocks_3D - 1)) % ((int)numberOfBlocks_3D-1);
        player.blockRightPressed = 1;
    }

    if (gameControl.control_pause.gameControlPress)
    {
        gameControl.control_pause.gameControlPress = 0;
        //room_persistent=true;
        //global.returnTo=room;
        //d3d_end();
        //room_goto(rm_menu);
    }

    if (gameControl.control_itemOne.gameControlPress)
    {
        gameControl.control_itemOne.gameControlPress = 0;
        /*if (global.itemOne == 1)
        {
            instance_create(player.x,player.y,obj_blockEditor3D);
            obj_blockEditor3D.currentSpace = currentSpace;
            instance_change(obj_player3DStalling,false);
        }*/
    }

    if (gameControl.control_itemTwo.gameControlPress)
    {
        gameControl.control_itemTwo.gameControlPress = 0;
        /*if (global.itemTwo == 1)
        {
            instance_create(x,y,obj_blockEditor3D);
            obj_blockEditor3D.currentSpace = currentSpace;
            instance_change(obj_player3DStalling,false);
        }*/
    }

    if (player.moving == 1)
    {
        player.motion += 1;

        int movingSide = (player.motion <= 4)*player.movingSideOne + (player.motion > 4)*player.movingSideTwo;

        if (player.sideFacing == 0)
        {
            side = (blkGph->blockGraph[player.currentSpace].v[1] + blkGph->blockGraph[player.currentSpace].v[3])/2;
        } else if (player.sideFacing == 1)
        {
            side = (blkGph->blockGraph[player.currentSpace].v[3] + blkGph->blockGraph[player.currentSpace].v[4])/2;
        } else if (player.sideFacing == 2)
        {
            side = (blkGph->blockGraph[player.currentSpace].v[4] + blkGph->blockGraph[player.currentSpace].v[2])/2;
        } else if (player.sideFacing == 3)
        {
            side = (blkGph->blockGraph[player.currentSpace].v[2] + blkGph->blockGraph[player.currentSpace].v[1])/2;
        }

        player.position = (player.motion <= 4)*((4-player.motion)*player.position + player.motion*side)/4 + (player.motion > 4)*((player.motion-5)*player.position + (9-player.motion)*side)/4;

        if (player.motion == 4)
        {
            player.currentSpace = player.movingSpace;
            player.sideFacing = player.sideFacingAfter;
        }

        if (player.motion == 8)
        {
            if (blkGph->blockGraph[player.currentSpace].type == 5)
            {
                player3D_moveInDirection((movingSide + 2) % 4);
            } else
            {
                player.moving = 0;
            }

            player.motion = 0;
        }
    }
}
