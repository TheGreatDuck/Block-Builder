#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "blockGraph.h"
#include "gameLoop.h"
#include "player.h"
#include "camera.h"
#include "loadLevel.h"
#include "controls.h"

int room;

GMEXPORT double gameLoopInit()
{
    player.currentSpace = 240;
    player.sideFacing = 0;
    player.sideFacingAfter = 0;
    player.moving = 0;
    player.motion = 0;
    player.movingSpace = 0;
    player.movingSideOne = 0;
    player.movingSideTwo = 0;

    load_level("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files", "YggdrasilQuest", "1");

    //sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\block.png", 1, 0, 0, 0, 0, &blkGph->spr_blockTexture);
    //sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);

    //sprite_add("C:\\Program Files (x86)\\Microsoft Games\\Age of Mythology\\1025\\data\\Savegame\\7-24-2020 hideout\\Block Builder Checkouting\\Block_Builder_3D\\Block-Builder\\Build Files\\block.png", 1, 0, 0, 0, 0, &player.texBody);
    //sprite_get_texture(&blkGph->spr_blockTexture,0,&blkGph->tex_blockTexture);

    initGameControl();

    //d3d_start();
    //d3d_set_fog(1,0,600,1000);
    //draw_set_color(c_white);
    //texture_set_interpolation(0);
    //d3d_set_culling(true);
    //d3d_set_lighting(0);

    return 1.0;
}

GMEXPORT double gameLoopStep()
{
    blockGraph_updateBlockGraphWithList();
    player3D_stepEvent();

    return 1.0;
}

GMEXPORT double gameLoopDraw()
{
    camera_drawEvent();
    blockGraph_drawEvent();
    player3D_drawEvent();
    return 1.0;
}
