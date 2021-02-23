#include <algorithm>

#include "rm_world_editor.hpp"
#include "gameMakerLibrary.hpp"
#include "controls.hpp"
#include "worldMap.hpp"
#include "blockGraph.hpp"
#include "loadLevel.hpp"
#include "entity.hpp"
#include "guiButton.hpp"
#include "guiScrollBar.hpp"

#define MAIN_MENU_ROOM 0
#define WORLD_SELECT_ROOM 1
#define WORLD_ROOM 2
#define LEVEL_ROOM 3
#define WORLD_EDITOR_SELECT_ROOM 4
#define WORLD_EDITOR_ROOM 5
#define LEVEL_EDITOR_ROOM 6
#define LEVEL_EDITOR_GEO_ROOM 7
#define CONFIGURE_CONTROL 8

extern int room;
//extern entity* entityList;
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
unsigned int worldEditorMode;

guiButton* guiMode;
guiButton* guiSave;
guiScrollBar* guiVScrollBar;
guiScrollBar* guiHScrollBar;

static void save_world()
{
    save_world(worldName[worldID]);
}

static void change_mode()
{
    worldEditorMode = (worldEditorMode+1) % 4;
}

void worldEditorEnter()
{
    room = WORLD_EDITOR_ROOM;
    load_world(worldName[worldID]);
    guiMode  = new guiButton(0,0,96,32,&change_mode,"change mode");
    guiSave  = new guiButton(96,0,48,32,&save_world,"save");
    guiVScrollBar = new guiScrollBar(608,32,32,448,0,map_height-14,14,&map_player_y, false);
    guiHScrollBar = new guiScrollBar(0,480,608,32,0,map_width-19,19,&map_player_x, true);
}

void worldEditorStep()
{
    int mx = *mouse_x;
    int my = *mouse_y;

    mx = mx/32;
    my = my/32;

    if (mouse_check_button_pressed(1) == 1 && my > 0 && mx < 19 && my < 15)
    {
        unsigned int x_min = map_player_x;
        x_min = std::min(map_width-19, x_min);

        unsigned int y_min = std::max(0,(int)map_player_y);
        y_min = std::min(map_height-14, y_min);

        mx += x_min;
        my += y_min-1;

        if (worldEditorMode == 0)
            map_icons[map_width*my + mx] = (map_icons[map_width*my + mx]+1) % 7;
        if (worldEditorMode == 1)
            map_collision[map_width*my + mx] = (map_collision[map_width*my + mx]+1) % 2;
        if (worldEditorMode == 2)
            map_path[map_width*my + mx] = (map_path[map_width*my + mx]+1) % 16;
        if (worldEditorMode == 3)
        {
            for (unsigned int levelID = 0; levelID < numberOfLevels; levelID++)
            {
                if (map_levels[levelID].xPos == mx && map_levels[levelID].yPos == my)
                {
                    room = LEVEL_EDITOR_GEO_ROOM;

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

                    entityID = -1;
                    //load_entityList(levelNumber);
                    //entityList[entityID].turnActive = 1;
                }
            }
        }
    }

    guiMode->step_event();
    guiSave->step_event();
    guiVScrollBar->step_event();
    guiHScrollBar->step_event();
}

void worldEditorDraw()
{
    unsigned int x_min = std::min(map_width-19, map_player_x);
    unsigned int y_min = std::min(map_height-14, map_player_y);

    unsigned int x_max = x_min+19;
    unsigned int y_max = y_min+14;

    for (unsigned int i = y_min; i < y_max; i++)
    {
        for (unsigned int j = x_min; j < x_max; j++)
        {
            if (worldEditorMode == 0)
                draw_sprite(spr_mapIcon,map_icons[map_width*i + j],32*(j-x_min),32*(i-y_min)+32);
            if (worldEditorMode == 1)
                draw_sprite(spr_mapIcon,map_collision[map_width*i + j],32*(j-x_min),32*(i-y_min)+32);
            if (worldEditorMode == 2)
                draw_sprite(spr_mapIcon,map_icons[map_width*i + j],32*(j-x_min),32*(i-y_min)+32);

            if (map_path[map_width*i + j] & (1 << 0))
                draw_sprite(spr_mapWestMapPath,0,32*(j-x_min),32*(i-y_min)+32);
            if (map_path[map_width*i + j] & (1 << 1))
                draw_sprite(spr_mapEastMapPath,0,32*(j-x_min),32*(i-y_min)+32);
            if (map_path[map_width*i + j] & (1 << 2))
                draw_sprite(spr_mapNorthMapPath,0,32*(j-x_min),32*(i-y_min)+32);
            if (map_path[map_width*i + j] & (1 << 3))
                draw_sprite(spr_mapSouthMapPath,0,32*(j-x_min),32*(i-y_min)+32);
        }
    }

    for (unsigned int i = 0; i < numberOfLocks; i++)
    {
        if (!(map_locks[i].side & map_levelCompletion[map_locks[i].level]))
            draw_sprite(spr_mapLock,0,32*(map_locks[i].xPos-x_min),32*(map_locks[i].yPos-y_min)+32);
    }

    for (unsigned int i = 0; i < numberOfLevels; i++)
        draw_sprite(spr_mapPlayer,0,32*(map_levels[i].xPos-x_min),32*(map_levels[i].yPos-y_min)+32);

    guiMode->draw_event();
    guiSave->draw_event();
    guiVScrollBar->draw_event();
    guiHScrollBar->draw_event();
}
