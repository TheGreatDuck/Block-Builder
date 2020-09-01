#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "player.h"
#include "camera.h"

double camera_drawEvent()
{
    d3d_set_projection_ortho(0,0,1280,1024,0);
    //draw_sprite(spr_itemIcons,global.itemOne,64,0);
    //draw_sprite(spr_itemIcons,global.itemTwo,192,0);
    //draw_sprite(spr_selectBlock,global.type,1024 + 64,0);
    //draw_sprite(spr_numbers,floor(global.inventoryBlock[global.type+1]/10),1024 + 64,0);
    //draw_sprite(spr_numbers,floor(global.inventoryBlock[global.type+1])-10*floor(global.inventoryBlock[global.type+1]/10),1024 + 128,0);
    d3d_set_projection_perspective(0,0,1280,1024,0);
    double camX = player.x+12*player.nx - 40*player.dirX;
    double camY = player.y+12*player.ny - 40*player.dirY;
    double camZ = player.z+12*player.nz - 40*player.dirZ;
    double playX = player.x+5*player.nx;
    double playY = player.y+5*player.ny;
    double playZ = player.z+5*player.nz;
    d3d_set_projection(camX,camY,camZ,playX,playY,playZ,player.nx,player.ny,player.nz);
    //d3d_set_projection(-200,0,0,playX,playY,playZ,0,0,1);
    //d3d_light_define_point(1,camX,camY,camZ,10000000,c_white);
    //d3d_light_enable(1,true);
}
