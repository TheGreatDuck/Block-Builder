#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>
#include "delayed_function_calls.h"
#include "controls.h"

controlSet gameControl;

void initGameControl()
{
    gameControl.control_cancel.gameControlPress = 0;
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
    gameControl.control_moveUp.gameControlPressed = 0;
}

#define SET_CONTROL(controlName)\
GMEXPORT double setGameControl_##controlName(double pressed)\
{\
    gameControl.control_##controlName.gameControlPress = (pressed && !gameControl.control_##controlName.gameControlPressed);\
    gameControl.control_##controlName.gameControlPressed = pressed;\
    return 1.0;\
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
