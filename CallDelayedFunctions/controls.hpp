#ifndef CONTROLS_H
#define CONTROLS_H
typedef struct control
{
    unsigned int gameControl;
    unsigned int gameControlType;
    unsigned int gameControlControllerID;
    unsigned int gameControlPress;
    unsigned int gameControlPressed;
} control;

typedef struct controlSet
{
    control control_cancel;
    control control_confirm;
    control control_itemTwo;
    control control_itemOne;
    control control_pause;
    control control_blockRight;
    control control_blockLeft;
    control control_moveLeft;
    control control_moveDown;
    control control_moveRight;
    control control_moveUp;
} controlSet;

#define controlType_keyboard 0
#define controlType_controller 1
#define controlType_dPadUp 2
#define controlType_dPadRight 3
#define controlType_dPadDown 4
#define controlType_dPadLeft 5
#define controlType_xUp 6
#define controlType_xDown 7
#define controlType_yUp 8
#define controlType_yDown 9
#define controlType_zUp 10
#define controlType_zDown 11
#define controlType_rUp 12
#define controlType_rDown 13
#define controlType_uUp 14
#define controlType_uDown 15
#define controlType_vUp 16
#define controlType_vDown 17

extern controlSet gameControl;

void initGameControl();
void updateGameControl();
#endif
