#include "rm_main_menu.hpp"
#include "gameMakerLibrary.hpp"
#include "controls.hpp"

#define MAIN_MENU_ROOM 0
#define WORLD_SELECT_ROOM 1
#define WORLD_ROOM 2
#define LEVEL_ROOM 3
#define WORLD_EDITOR_SELECT_ROOM 4
#define WORLD_EDITOR_ROOM 5
#define LEVEL_EDITOR_ROOM 6
#define CONFIGURE_CONTROL 7

extern int room;
extern int spr_mapPlayer;

unsigned int menu_position;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mainMenuStep()
{
    if (gameControl.control_moveUp.gameControlPress)
    {
        if (menu_position >= 1)
            menu_position--;
    }

    if (gameControl.control_moveDown.gameControlPress)
    {
        if (menu_position < 3)
            menu_position++;
    }

    if (gameControl.control_confirm.gameControlPress)
    {
        if (menu_position == 0)
            room = WORLD_SELECT_ROOM;
        if (menu_position == 1)
            room = WORLD_EDITOR_SELECT_ROOM;
        if (menu_position == 2)
            room = CONFIGURE_CONTROL;
        if (menu_position == 3)
            game_end();
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mainMenuDraw()
{
    draw_text(100, 100, "World select");
    draw_text(100, 132, "Editor");
    draw_text(100, 164, "Configure Controls");
    draw_text(100, 192, "Quit Game");
    draw_sprite(spr_mapPlayer,0,68,32*menu_position + 100 - 4);
}
