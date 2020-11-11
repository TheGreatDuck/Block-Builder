#include <string.h>
#include <malloc.h>
#include "rm_configure_control.hpp"
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


/** \brief
 *
 */
extern int room;


/** \brief
 *
 */
int keyboard_lastkey;

/** \brief
 *
 */
int enter_key_check;

/** \brief
 *
 */
int enter_key_check_now;

/** \brief
 *
 */
int enter_key_check_held;

/** \brief
 *
 */
int left_key_check;

/** \brief
 *
 */
int left_key_check_now;

/** \brief
 *
 */
int left_key_check_held;

/** \brief
 *
 */
int right_key_check;

/** \brief
 *
 */
int right_key_check_now;

/** \brief
 *
 */
int right_key_check_held;

/** \brief
 *
 */
int space_key_check;

/** \brief
 *
 */
int space_key_check_now;

/** \brief
 *
 */
int space_key_check_held;


/** \brief
 *
 */
int waiting;

/** \brief
 *
 */
int timer;

/** \brief
 *
 */
int selection;

/** \brief
 *
 */
int numberOfControls = 11;

control* controlArray[11] = {&gameControl.control_moveUp, &gameControl.control_moveRight, &gameControl.control_moveDown, &gameControl.control_moveLeft, &gameControl.control_blockLeft, &gameControl.control_blockRight, &gameControl.control_pause, &gameControl.control_itemOne, &gameControl.control_itemTwo, &gameControl.control_confirm, &gameControl.control_cancel};
const char* controlText[11] = {"Set Move Up", "Set Move Right", "Set Move Down", "Set Move Left", "Set Block Left", "Set Block Right", "Set Pause", "Set Item One", "Set Item Two", "Set Confirm", "Set Cancel"};

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void configureControlBeginStep()
{
    keyboard_lastkey = get_keyboard_lastkey();
    set_keyboard_lastkey(0);

    enter_key_check = keyboard_check(vk_enter);
    left_key_check  = keyboard_check(vk_left);
    right_key_check = keyboard_check(vk_right);
    space_key_check = keyboard_check(vk_space);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void configureControlStep()
{
    if (waiting)
    {
        timer -= 1;
        if (keyboard_lastkey != 0)
        {
            controlArray[selection]->gameControl = keyboard_lastkey;
            controlArray[selection]->gameControlType = controlType_keyboard;
            waiting = false;
        }

        /*for (int k = 0; k < 2; k++)
        {
            if (joystick_exists(k))
            {
                for (i = 1; i <= 32; i += 1)
                {
                    if (joystick_check_button(k,i) && waiting)
                    {
                        global.gameControl[selection] = i;
                        global.gameControlType[selection] = controlType_controller;
                        global.gameControlControllerID[selection] = k;
                        waiting = false;
                    }
                }

                if (joystick_pov(k) == 0 && waiting)
                {
                    global.gameControlType[selection] = controlType_dPadUp;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_pov(k) == 90 && waiting)
                {
                    global.gameControlType[selection] = controlType_dPadRight;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_pov(k) == 180 && waiting)
                {
                    global.gameControlType[selection] = controlType_dPadDown;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_pov(k) == 270 && waiting)
                {
                    global.gameControlType[selection] = controlType_dPadLeft;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_xpos(k) >= 0.5 && joystick_xpos(k) < 1 && waiting)
                {
                    global.gameControlType[selection] = controlType_xUp;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_xpos(k) <= -0.5 && joystick_xpos(k) > -1 && waiting)
                {
                    global.gameControlType[selection] = controlType_xDown;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_ypos(k) >= 0.5 && joystick_ypos(k) < 1 && waiting)
                {
                    global.gameControlType[selection] = controlType_yUp;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_ypos(k) <= -0.5 && joystick_ypos(k) > -1 && waiting)
                {
                    global.gameControlType[selection] = controlType_yDown;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_zpos(k) >= 0.5 && joystick_zpos(k) < 1 && waiting)
                {
                    global.gameControlType[selection] = controlType_zUp;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_zpos(k) <= -0.5 && joystick_zpos(k) > -1 && waiting)
                {
                    global.gameControlType[selection] = controlType_zDown;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_rpos(k) >= 0.5 && joystick_rpos(k) < 1 && waiting)
                {
                    global.gameControlType[selection] = controlType_rUp;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_rpos(k) <= -0.5 && joystick_rpos(k) > -1 && waiting)
                {
                    global.gameControlType[selection] = controlType_rDown;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_upos(k) >= 0.5 && joystick_upos(k) < 1 && waiting)
                {
                    global.gameControlType[selection] = controlType_uUp;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_upos(k) <= -0.5 && joystick_upos(k) > -1 && waiting)
                {
                    global.gameControlType[selection] = controlType_uDown;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_vpos(k) >= 0.5 && joystick_vpos(k) < 1 && waiting)
                {
                    global.gameControlType[selection] = controlType_vUp;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }

                if (joystick_vpos(k) <= -0.5 && joystick_vpos(k) > -1 && waiting)
                {
                    global.gameControlType[selection] = controlType_vDown;
                    global.gameControlControllerID[selection] = k;
                    waiting = false;
                }
            }
        }*/

        if (timer == 0)
        {
            waiting = false;
        }
    } else
    {
        enter_key_check_now = enter_key_check && !enter_key_check_held;
        left_key_check_now  = left_key_check  && !left_key_check_held;
        right_key_check_now = right_key_check && !right_key_check_held;
        space_key_check_now = space_key_check && !space_key_check_held;

        enter_key_check_held = enter_key_check;
        left_key_check_held  = left_key_check;
        right_key_check_held = right_key_check;
        space_key_check_held = space_key_check;

        if (enter_key_check_now)
        {
            waiting = true;
            timer = 150;
            keyboard_lastkey = 0;
        }

        if (left_key_check_now)
        {
            selection -= 1;
            selection *= 1 - (selection < 0);
        }

        if (right_key_check_now)
        {
            selection += 1;
            if (selection >= numberOfControls)
            {
                selection = numberOfControls-1;
            }
        }

        if (space_key_check_now)
        {
            room = MAIN_MENU_ROOM;
        }
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
static const char* get_key_text(int key)
{
    if (key == 13)
        return "Keyboard Key Enter";
    else if (key == 16)
        return "Keyboard Key Shift";
    else if (key == 17)
        return "Keyboard Key Control";
    else if (key == 18)
        return "Keyboard Key Alt";
    else if (key == 37)
        return "Keyboard Key Left";
    else if (key == 38)
        return "Keyboard Key Up";
    else if (key == 39)
        return "Keyboard Key Right";
    else if (key == 40)
        return "Keyboard Key Down";
    else if (key == 48)
        return "Keyboard Key 0";
    else if (key == 49)
        return "Keyboard Key 1";
    else if (key == 50)
        return "Keyboard Key 2";
    else if (key == 51)
        return "Keyboard Key 3";
    else if (key == 52)
        return "Keyboard Key 4";
    else if (key == 53)
        return "Keyboard Key 5";
    else if (key == 54)
        return "Keyboard Key 6";
    else if (key == 55)
        return "Keyboard Key 7";
    else if (key == 56)
        return "Keyboard Key 8";
    else if (key == 57)
        return "Keyboard Key 9";
    else if (key == 65)
        return "Keyboard Key A";
    else if (key == 66)
        return "Keyboard Key B";
    else if (key == 67)
        return "Keyboard Key C";
    else if (key == 68)
        return "Keyboard Key D";
    else if (key == 69)
        return "Keyboard Key E";
    else if (key == 70)
        return "Keyboard Key F";
    else if (key == 71)
        return "Keyboard Key G";
    else if (key == 72)
        return "Keyboard Key H";
    else if (key == 73)
        return "Keyboard Key I";
    else if (key == 74)
        return "Keyboard Key J";
    else if (key == 75)
        return "Keyboard Key K";
    else if (key == 76)
        return "Keyboard Key L";
    else if (key == 77)
        return "Keyboard Key M";
    else if (key == 78)
        return "Keyboard Key N";
    else if (key == 79)
        return "Keyboard Key O";
    else if (key == 80)
        return "Keyboard Key P";
    else if (key == 81)
        return "Keyboard Key Q";
    else if (key == 82)
        return "Keyboard Key R";
    else if (key == 83)
        return "Keyboard Key S";
    else if (key == 84)
        return "Keyboard Key T";
    else if (key == 85)
        return "Keyboard Key U";
    else if (key == 86)
        return "Keyboard Key V";
    else if (key == 87)
        return "Keyboard Key W";
    else if (key == 88)
        return "Keyboard Key X";
    else if (key == 89)
        return "Keyboard Key Y";
    else if (key == 90)
        return "Keyboard Key Z";
    else
        return "Unknown Keyboard Key";
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void configureControlDraw()
{
    char timer_text[4];
    if (timer > 99)
    {
        timer_text[0] = (timer/100) + '0';
        timer_text[1] = (timer/10 - 10*(timer/100)) + '0';
        timer_text[2] = (timer - 10*(timer/10)) + '0';
        timer_text[3] = 0;
    } else if (timer > 9)
    {
        timer_text[0] = (timer/10) + '0';
        timer_text[1] = (timer - 10*(timer/10)) + '0';
        timer_text[2] = 0;
    } else
    {
        timer_text[0] = timer + '0';
        timer_text[1] = 0;
    }

    draw_text(0,0,timer_text);
    draw_text(0,64,"Use arrow keys to select control.#Press enter to configure.#Press space when done to exit menu.");

    draw_text(256,208, controlText[selection]);

    if (controlArray[selection]->gameControlType == controlType_keyboard)
        draw_text(256,208+64, get_key_text(controlArray[selection]->gameControl));

    /*if (global.gameControlType[selection] == controlType_controller)
    {
        draw_text(x,y+64,"Controller Button " + string(global.gameControl[selection]));
    }

    if (global.gameControlType[selection] == controlType_controller)
    {
        draw_text(x,y+64,"Controller Button " + string(global.gameControl[selection]));
    }*/

    if (controlArray[selection]->gameControlType == controlType_dPadDown)
        draw_text(256,208+64,"D Pad Down");
    if (controlArray[selection]->gameControlType == controlType_dPadRight)
        draw_text(256,208+64,"D Pad Right");
    if (controlArray[selection]->gameControlType == controlType_dPadLeft)
        draw_text(256,208+64,"D Pad Left");
    if (controlArray[selection]->gameControlType == controlType_dPadUp)
        draw_text(256,208+64,"D Pad Up");
    if (controlArray[selection]->gameControlType == controlType_xUp)
        draw_text(256,208+64,"Joystick X axis Up");
    if (controlArray[selection]->gameControlType == controlType_xDown)
        draw_text(256,208+64,"Joystick X axis Down");
    if (controlArray[selection]->gameControlType == controlType_yUp)
        draw_text(256,208+64,"Joystick Y axis Up");
    if (controlArray[selection]->gameControlType == controlType_yDown)
        draw_text(256,208+64,"Joystick Y axis Down");
    if (controlArray[selection]->gameControlType == controlType_zUp)
        draw_text(256,208+64,"Joystick Z axis Up");
    if (controlArray[selection]->gameControlType == controlType_zDown)
        draw_text(256,208+64,"Joystick Z axis Down");
    if (controlArray[selection]->gameControlType == controlType_rUp)
        draw_text(256,208+64,"Joystick R axis Up");
    if (controlArray[selection]->gameControlType == controlType_rDown)
        draw_text(256,208+64,"Joystick R axis Down");
    if (controlArray[selection]->gameControlType == controlType_uUp)
        draw_text(256,208+64,"Joystick U axis Up");
    if (controlArray[selection]->gameControlType == controlType_uDown)
        draw_text(256,208+64,"Joystick U axis Down");
    if (controlArray[selection]->gameControlType == controlType_vUp)
        draw_text(256,208+64,"Joystick V axis Up");
    if (controlArray[selection]->gameControlType == controlType_vDown)
        draw_text(256,208+64,"Joystick V axis Down");
}
