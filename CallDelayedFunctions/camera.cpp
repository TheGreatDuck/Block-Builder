#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "gameMakerLibrary.hpp"
#include "controls.hpp"
#include "camera.hpp"
#include "blockGraph.hpp"
#include "entity.hpp"

extern int spr_selectBlock;

extern entity* entityList;
extern int entityID;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void camera_drawEvent()
{
    d3d_set_projection_ortho(0,0,1280,1024,0);
    #if 0
    draw_sprite(spr_itemIcons,global.itemOne,64,0);
    draw_sprite(spr_itemIcons,global.itemTwo,192,0);
    draw_sprite(&spr_selectBlock,player.type,1024 + 64,0);
    draw_sprite(spr_numbers,floor(global.inventoryBlock[player.type+1]/10),1024 + 64,0);
    draw_sprite(spr_numbers,floor(global.inventoryBlock[player.type+1])-10*floor(global.inventoryBlock[player.type+1]/10),1024 + 128,0);
    #endif
    d3d_set_projection_perspective(0,0,640,512,0);

    vector n   = blkGph->blockGraph[entityList[entityID].currentSpace].normal;
    vector dir = blkGph->blockGraph[entityList[entityID].currentSpace].dir[entityList[entityID].sideFacing];

    vector p   = blkGph->blockGraph[entityList[entityID].currentSpace].motionPoints[entityList[entityID].movingSide][entityList[entityID].motion];

    double camX  = p.x + 12*n.x - 40*dir.x;
    double camY  = p.y + 12*n.y - 40*dir.y;
    double camZ  = p.z + 12*n.z - 40*dir.z;
    double playX = p.x +  5*n.x;
    double playY = p.y +  5*n.y;
    double playZ = p.z +  5*n.z;
    d3d_set_projection(camX,camY,camZ,playX,playY,playZ,n.x,n.y,n.z);
    #if 0
    d3d_light_define_point(1,camX,camY,camZ,10000000,c_white);
    d3d_light_enable(1,true);
    #endif
}

vector cam_m[4];

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void cameraEditor_drawEvent()
{
    d3d_set_projection_perspective(0,0,1280,1024,0);

    double camX  = cam_m[3].x;
    double camY  = cam_m[3].y;
    double camZ  = cam_m[3].z;
    double playX = cam_m[3].x - cam_m[1].x;
    double playY = cam_m[3].y - cam_m[1].y;
    double playZ = cam_m[3].z - cam_m[1].z;
    d3d_set_projection(camX,       camY,       camZ,
                       playX,      playY,      playZ,
                       cam_m[2].x, cam_m[2].y, cam_m[2].z);
    #if 0
    d3d_light_define_point(1,camX,camY,camZ,10000000,c_white);
    d3d_light_enable(1,true);
    #endif
}
