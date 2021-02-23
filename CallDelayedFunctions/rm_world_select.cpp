#include "rm_world_select.hpp"
#include "gameMakerLibrary.hpp"
#include "controls.hpp"
#include "worldMap.hpp"

#define MAIN_MENU_ROOM 0
#define WORLD_SELECT_ROOM 1
#define WORLD_ROOM 2
#define LEVEL_ROOM 3
#define WORLD_EDITOR_SELECT_ROOM 4
#define WORLD_EDITOR_ROOM 5
#define LEVEL_EDITOR_ROOM 6
#define CONFIGURE_CONTROL 7

extern int room;
extern unsigned int worldID;
extern int spr_mapPlayer;
extern unsigned int worldCount;
extern char** worldName;
extern char* program_directory;

void worldSelectStep()
{
    if (gameControl.control_moveUp.gameControlPress)
    {
        if (worldID >= 1)
            worldID--;
    }

    if (gameControl.control_moveDown.gameControlPress)
    {
        if (worldID+1 < worldCount)
            worldID++;
    }

    if (gameControl.control_confirm.gameControlPress)
    {
        room = WORLD_ROOM;
        load_world(worldName[worldID]);
    }
}

void worldSelectDraw()
{
    for (unsigned int id = 0; id < worldCount; id++)
        draw_text(100, 100+id*32, worldName[id]);
    draw_sprite(spr_mapPlayer,0,68,32*worldID + 96);
}
