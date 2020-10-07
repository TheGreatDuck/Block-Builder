#ifndef CONTROLS_H
#define CONTROLS_H
typedef struct control
{
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

extern controlSet gameControl;

void initGameControl();

GMEXPORT double setGameControl_cancel(double pressed);
GMEXPORT double setGameControl_confirm(double pressed);
GMEXPORT double setGameControl_itemTwo(double pressed);
GMEXPORT double setGameControl_itemOne(double pressed);
GMEXPORT double setGameControl_pause(double pressed);
GMEXPORT double setGameControl_blockRight(double pressed);
GMEXPORT double setGameControl_blockLeft(double pressed);
GMEXPORT double setGameControl_moveLeft(double pressed);
GMEXPORT double setGameControl_moveDown(double pressed);
GMEXPORT double setGameControl_moveRight(double pressed);
GMEXPORT double setGameControl_moveUp(double pressed);
#endif
