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
    double camX = player.position.x+12*player.n.x - 40*player.dir.x;
    double camY = player.position.y+12*player.n.y - 40*player.dir.y;
    double camZ = player.position.z+12*player.n.z - 40*player.dir.z;
    double playX = player.position.x+5*player.n.x;
    double playY = player.position.y+5*player.n.y;
    double playZ = player.position.z+5*player.n.z;
    d3d_set_projection(camX,camY,camZ,playX,playY,playZ,player.n.x,player.n.y,player.n.z);
    //d3d_set_projection(-200,0,0,playX,playY,playZ,0,0,1);
    //d3d_light_define_point(1,camX,camY,camZ,10000000,c_white);
    //d3d_light_enable(1,true);
}
