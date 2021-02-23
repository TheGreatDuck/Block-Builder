#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include <windows.h>
#include <winuser.h>
#include "gameMakerLibrary.hpp"
#include "controls.hpp"

controlSet gameControl;

void initGameControl()
{
    gameControl.control_moveUp.gameControl = vk_up;
    gameControl.control_moveUp.gameControlType = controlType_keyboard;
    gameControl.control_moveUp.gameControlControllerID = 0;

    gameControl.control_moveRight.gameControl = vk_right;
    gameControl.control_moveRight.gameControlType = controlType_keyboard;
    gameControl.control_moveRight.gameControlControllerID = 0;

    gameControl.control_moveDown.gameControl = vk_down;
    gameControl.control_moveDown.gameControlType = controlType_keyboard;
    gameControl.control_moveDown.gameControlControllerID = 0;

    gameControl.control_moveLeft.gameControl = vk_left;
    gameControl.control_moveLeft.gameControlType = controlType_keyboard;
    gameControl.control_moveLeft.gameControlControllerID = 0;

    gameControl.control_blockLeft.gameControl = vk_shift;
    gameControl.control_blockLeft.gameControlType = controlType_keyboard;
    gameControl.control_blockLeft.gameControlControllerID = 0;

    gameControl.control_blockRight.gameControl = vk_control;
    gameControl.control_blockRight.gameControlType = controlType_keyboard;
    gameControl.control_blockRight.gameControlControllerID = 0;

    gameControl.control_pause.gameControl = vk_enter;
    gameControl.control_pause.gameControlType = controlType_keyboard;
    gameControl.control_pause.gameControlControllerID = 0;

    gameControl.control_itemOne.gameControl = 'S';
    gameControl.control_itemOne.gameControlType = controlType_keyboard;
    gameControl.control_itemOne.gameControlControllerID = 0;

    gameControl.control_itemTwo.gameControl = 'D';
    gameControl.control_itemTwo.gameControlType = controlType_keyboard;
    gameControl.control_itemTwo.gameControlControllerID = 0;

    gameControl.control_cancel.gameControl = 'C';
    gameControl.control_cancel.gameControlType = controlType_keyboard;
    gameControl.control_cancel.gameControlControllerID = 0;

    gameControl.control_confirm.gameControl = 'X';
    gameControl.control_confirm.gameControlType = controlType_keyboard;
    gameControl.control_confirm.gameControlControllerID = 0;
}

static int isControlPressed(control* controlName)
{
    int keyboardCheck = keyboard_check(controlName->gameControl);
    int controllerCheck = 0;

    #if 0
    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_controller)
        controllerCheck = joystick_check_button(controlName.gameControlControllerID,controlName.gameControl);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadUp)
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 0);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadRight)
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 90);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadDown)
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 180);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadLeft)
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 270);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_xUp)
        controllerCheck = (joystick_xpos(controlName.gameControlControllerID) >= 0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_xDown)
        controllerCheck = (joystick_xpos(controlName.gameControlControllerID) <= -0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_yUp)
        controllerCheck = (joystick_ypos(controlName.gameControlControllerID) >= 0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_yDown)
        controllerCheck = (joystick_ypos(controlName.gameControlControllerID) <= -0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_zUp)
        controllerCheck = (joystick_zpos(controlName.gameControlControllerID) >= 0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_zDown)
        controllerCheck = (joystick_zpos(controlName.gameControlControllerID) <= -0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_rUp)
        controllerCheck = (joystick_rpos(controlName.gameControlControllerID) >= 0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_rDown)
        controllerCheck = (joystick_rpos(controlName.gameControlControllerID) <= -0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_uUp)
        controllerCheck = (joystick_upos(controlName.gameControlControllerID) >= 0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_uDown)
        controllerCheck = (joystick_upos(controlName.gameControlControllerID) <= -0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_vUp)
        controllerCheck = (joystick_vpos(controlName.gameControlControllerID) >= 0.5);

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_vDown)
        controllerCheck = (joystick_vpos(controlName.gameControlControllerID) <= -0.5);
    #endif

    return keyboardCheck || controllerCheck;
}

#define SET_CONTROL(controlName)\
void setGameControl_##controlName()\
{\
    int pressed = isControlPressed(&gameControl.control_##controlName);\
    gameControl.control_##controlName.gameControlPress = (pressed && !gameControl.control_##controlName.gameControlPressed);\
    gameControl.control_##controlName.gameControlPressed = pressed;\
}

SET_CONTROL(cancel)
SET_CONTROL(confirm)
SET_CONTROL(itemTwo)
SET_CONTROL(itemOne)
SET_CONTROL(pause)
SET_CONTROL(blockRight)
SET_CONTROL(blockLeft)
SET_CONTROL(moveLeft)
SET_CONTROL(moveDown)
SET_CONTROL(moveRight)
SET_CONTROL(moveUp)

void updateGameControl()
{
    setGameControl_cancel();
    setGameControl_confirm();
    setGameControl_itemOne();
    setGameControl_itemTwo();
    setGameControl_pause();
    setGameControl_blockLeft();
    setGameControl_blockRight();
    setGameControl_moveUp();
    setGameControl_moveLeft();
    setGameControl_moveRight();
    setGameControl_moveDown();
}
