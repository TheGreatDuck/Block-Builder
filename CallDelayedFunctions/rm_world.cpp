#include <algorithm>

#include "rm_world.hpp"
#include "gameMakerLibrary.hpp"
#include "controls.hpp"
#include "worldMap.hpp"
#include "blockGraph.hpp"
#include "loadLevel.hpp"
#include "entity.hpp"

#define MAIN_MENU_ROOM 0
#define WORLD_SELECT_ROOM 1
#define WORLD_ROOM 2
#define LEVEL_ROOM 3
#define WORLD_EDITOR_SELECT_ROOM 4
#define WORLD_EDITOR_ROOM 5
#define LEVEL_EDITOR_ROOM 6
#define CONFIGURE_CONTROL 7

extern int room;
extern entity* entityList;
extern int entityID;
extern char** worldName;
extern unsigned int worldID;

extern int spr_mapIcon;
extern int spr_mapPlayer;
extern int spr_mapWestMapPath;
extern int spr_mapEastMapPath;
extern int spr_mapNorthMapPath;
extern int spr_mapSouthMapPath;
extern int spr_mapLock;

void load_entityList(const char* levelLoading);

void worldStep()
{
    if (gameControl.control_moveUp.gameControlPress)
    {
        if (map_player_y >= 1)
        {
            if (map_collision[map_width*(map_player_y-1) + map_player_x] == 0)
                map_player_y--;
        }
    }

    if (gameControl.control_moveRight.gameControlPress)
    {
        if (map_player_x + 1 < map_width)
        {
            if (map_collision[map_width*map_player_y + (map_player_x+1)] == 0)
                map_player_x++;
        }
    }

    if (gameControl.control_moveDown.gameControlPress)
    {
        if (map_player_y + 1 < map_height)
        {
            if (map_collision[map_width*(map_player_y+1) + map_player_x] == 0)
                map_player_y++;
        }
    }

    if (gameControl.control_moveLeft.gameControlPress)
    {
        if (map_player_x >= 1)
        {
            if (map_collision[map_width*map_player_y + (map_player_x-1)] == 0)
                map_player_x--;
        }
    }

    if (gameControl.control_confirm.gameControlPress)
    {
        for (unsigned int levelID = 0; levelID < numberOfLevels; levelID++)
        {
            if (map_levels[levelID].xPos == map_player_x && map_levels[levelID].yPos == map_player_y)
            {
                room = LEVEL_ROOM;

                char levelNumber[2];
                levelNumber[0] = map_levels[levelID].level+'0';
                levelNumber[1] = 0;

                load_level(worldName[worldID], levelNumber);

                blkGph->spr_blockTexture = sprite_add("block.png", 1, 0, 0, 0, 0);
                blkGph->tex_blockTexture = sprite_get_texture(blkGph->spr_blockTexture,0);

                d3d_start();
                d3d_set_fog(1,0,600,1000);
                #if 0
                draw_set_color(c_white);
                texture_set_interpolation(0);
                d3d_set_culling(true);
                #endif
                d3d_set_lighting(0);

                entityID = 0;
                load_entityList(levelNumber);
                entityList[entityID].turnActive = 1;
            }
        }
    }
}

void worldDraw()
{
    unsigned int x_min = std::max(0,(int)map_player_x-10);
    x_min = std::min(map_width-10, x_min);

    unsigned int y_min = std::max(0,(int)map_player_y-8);
    y_min = std::min(map_height-8, y_min);

    unsigned int x_max = x_min+20;
    unsigned int y_max = y_min+16;

    for (unsigned int i = y_min; i < y_max; i++)
    {
        for (unsigned int j = x_min; j < x_max; j++)
        {
            draw_sprite(spr_mapIcon,map_icons[map_width*i + j],32*(j-x_min),32*(i-y_min));
            if (map_path[map_width*i + j] & (1 << 0))
                draw_sprite(spr_mapWestMapPath,0,32*(j-x_min),32*(i-y_min));
            if (map_path[map_width*i + j] & (1 << 1))
                draw_sprite(spr_mapEastMapPath,0,32*(j-x_min),32*(i-y_min));
            if (map_path[map_width*i + j] & (1 << 2))
                draw_sprite(spr_mapNorthMapPath,0,32*(j-x_min),32*(i-y_min));
            if (map_path[map_width*i + j] & (1 << 3))
                draw_sprite(spr_mapSouthMapPath,0,32*(j-x_min),32*(i-y_min));
        }
    }

    for (unsigned int i = 0; i < numberOfLocks; i++)
    {
        if (!(map_locks[i].side & map_levelCompletion[map_locks[i].level]))
            draw_sprite(spr_mapLock,0,32*(map_locks[i].xPos-x_min),32*(map_locks[i].yPos-y_min));
    }

    for (unsigned int i = 0; i < numberOfLevels; i++)
        draw_sprite(spr_mapPlayer,0,32*(map_levels[i].xPos-x_min),32*(map_levels[i].yPos-y_min));

    draw_sprite(spr_mapPlayer,0,32*(map_player_x-x_min),32*(map_player_y-y_min));
}
