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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
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

    #if 0
    gameControl[control_moveUp] = ord('W');
    gameControl[control_moveLeft] = ord('A');
    gameControl[control_moveRight] = ord('D');
    gameControl[control_moveDown] = ord('S');
    #endif

    /*gameControl.control_cancel.gameControlPress = 0;
    gameControl.control_confirm.gameControlPress = 0;
    gameControl.control_itemTwo.gameControlPress = 0;
    gameControl.control_itemOne.gameControlPress = 0;
    gameControl.control_pause.gameControlPress = 0;
    gameControl.control_blockRight.gameControlPress = 0;
    gameControl.control_blockLeft.gameControlPress = 0;
    gameControl.control_moveLeft.gameControlPress = 0;
    gameControl.control_moveDown.gameControlPress = 0;
    gameControl.control_moveRight.gameControlPress = 0;
    gameControl.control_moveUp.gameControlPress = 0;

    gameControl.control_cancel.gameControlPressed = 0;
    gameControl.control_confirm.gameControlPressed = 0;
    gameControl.control_itemTwo.gameControlPressed = 0;
    gameControl.control_itemOne.gameControlPressed = 0;
    gameControl.control_pause.gameControlPressed = 0;
    gameControl.control_blockRight.gameControlPressed = 0;
    gameControl.control_blockLeft.gameControlPressed = 0;
    gameControl.control_moveLeft.gameControlPressed = 0;
    gameControl.control_moveDown.gameControlPressed = 0;
    gameControl.control_moveRight.gameControlPressed = 0;
    gameControl.control_moveUp.gameControlPressed = 0;*/
}

#define SET_CONTROL(controlName)\
double setGameControl_##controlName(double double_pressed)\
{\
    int pressed = double_pressed;\
    gameControl.control_##controlName.gameControlPress = (pressed && !gameControl.control_##controlName.gameControlPressed);\
    gameControl.control_##controlName.gameControlPressed = pressed;\
    return 1.0;\
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(cancel)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(confirm)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(itemTwo)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(itemOne)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(pause)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(blockRight)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(blockLeft)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(moveLeft)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(moveDown)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(moveRight)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
SET_CONTROL(moveUp)

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
static void isControlPressed(control* controlName)
{
    controlName->keyboardCheck = keyboard_check(controlName->gameControl);
    //int controllerCheck;

    /*if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_controller)
    {
        controllerCheck = joystick_check_button(controlName.gameControlControllerID,controlName.gameControl);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadUp)
    {
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 0);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadRight)
    {
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 90);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadDown)
    {
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 180);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_dPadLeft)
    {
        controllerCheck = (joystick_pov(controlName.gameControlControllerID) == 270);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_xUp)
    {
        controllerCheck = (joystick_xpos(controlName.gameControlControllerID) >= 0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_xDown)
    {
        controllerCheck = (joystick_xpos(controlName.gameControlControllerID) <= -0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_yUp)
    {
        controllerCheck = (joystick_ypos(controlName.gameControlControllerID) >= 0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_yDown)
    {
        controllerCheck = (joystick_ypos(controlName.gameControlControllerID) <= -0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_zUp)
    {
        controllerCheck = (joystick_zpos(controlName.gameControlControllerID) >= 0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_zDown)
    {
        controllerCheck = (joystick_zpos(controlName.gameControlControllerID) <= -0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_rUp)
    {
        controllerCheck = (joystick_rpos(controlName.gameControlControllerID) >= 0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_rDown)
    {
        controllerCheck = (joystick_rpos(controlName.gameControlControllerID) <= -0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_uUp)
    {
        controllerCheck = (joystick_upos(controlName.gameControlControllerID) >= 0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_uDown)
    {
        controllerCheck = (joystick_upos(controlName.gameControlControllerID) <= -0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_vUp)
    {
        controllerCheck = (joystick_vpos(controlName.gameControlControllerID) >= 0.5);
    }

    if (joystick_exists(controlName.gameControlControllerID) && controlName.gameControlType == controlType_vDown)
    {
        controllerCheck = (joystick_vpos(controlName.gameControlControllerID) <= -0.5);
    }*/

    //return keyboardCheck || controllerCheck;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void updateGameControlBeginStep()
{
    isControlPressed(&gameControl.control_cancel);
    isControlPressed(&gameControl.control_confirm);
    isControlPressed(&gameControl.control_itemOne);
    isControlPressed(&gameControl.control_itemTwo);
    isControlPressed(&gameControl.control_pause);
    isControlPressed(&gameControl.control_blockLeft);
    isControlPressed(&gameControl.control_blockRight);
    isControlPressed(&gameControl.control_moveUp);
    isControlPressed(&gameControl.control_moveLeft);
    isControlPressed(&gameControl.control_moveRight);
    isControlPressed(&gameControl.control_moveDown);
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void updateGameControlStep()
{
    setGameControl_cancel(gameControl.control_cancel.keyboardCheck);
    setGameControl_confirm(gameControl.control_confirm.keyboardCheck);
    setGameControl_itemOne(gameControl.control_itemOne.keyboardCheck);
    setGameControl_itemTwo(gameControl.control_itemTwo.keyboardCheck);
    setGameControl_pause(gameControl.control_pause.keyboardCheck);
    setGameControl_blockLeft(gameControl.control_blockLeft.keyboardCheck);
    setGameControl_blockRight(gameControl.control_blockRight.keyboardCheck);
    setGameControl_moveUp(gameControl.control_moveUp.keyboardCheck);
    setGameControl_moveLeft(gameControl.control_moveLeft.keyboardCheck);
    setGameControl_moveRight(gameControl.control_moveRight.keyboardCheck);
    setGameControl_moveDown(gameControl.control_moveDown.keyboardCheck);
}
