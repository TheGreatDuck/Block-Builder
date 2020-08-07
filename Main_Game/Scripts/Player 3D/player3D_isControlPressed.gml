var controlName;
controlName = argument[0];

keyboardCheck = keyboard_check(global.gameControl[controlName]) && global.gameControlType[controlName] == controlType_keyboard;

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_controller)
{
    controllerCheck = joystick_check_button(global.gameControlControllerID[controlName],global.gameControl[controlName]);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_dPadUp)
{
    controllerCheck = (joystick_pov(global.gameControlControllerID[controlName]) == 0);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_dPadRight)
{
    controllerCheck = (joystick_pov(global.gameControlControllerID[controlName]) == 90);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_dPadDown)
{
    controllerCheck = (joystick_pov(global.gameControlControllerID[controlName]) == 180);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_dPadLeft)
{
    controllerCheck = (joystick_pov(global.gameControlControllerID[controlName]) == 270);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_xUp)
{
    controllerCheck = (joystick_xpos(global.gameControlControllerID[controlName]) >= 0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_xDown)
{
    controllerCheck = (joystick_xpos(global.gameControlControllerID[controlName]) <= -0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_yUp)
{
    controllerCheck = (joystick_ypos(global.gameControlControllerID[controlName]) >= 0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_yDown)
{
    controllerCheck = (joystick_ypos(global.gameControlControllerID[controlName]) <= -0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_zUp)
{
    controllerCheck = (joystick_zpos(global.gameControlControllerID[controlName]) >= 0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_zDown)
{
    controllerCheck = (joystick_zpos(global.gameControlControllerID[controlName]) <= -0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_rUp)
{
    controllerCheck = (joystick_rpos(global.gameControlControllerID[controlName]) >= 0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_rDown)
{
    controllerCheck = (joystick_rpos(global.gameControlControllerID[controlName]) <= -0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_uUp)
{
    controllerCheck = (joystick_upos(global.gameControlControllerID[controlName]) >= 0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_uDown)
{
    controllerCheck = (joystick_upos(global.gameControlControllerID[controlName]) <= -0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_vUp)
{
    controllerCheck = (joystick_vpos(global.gameControlControllerID[controlName]) >= 0.5);
}

if (joystick_exists(global.gameControlControllerID[controlName]) && global.gameControlType[controlName] == controlType_vDown)
{
    controllerCheck = (joystick_vpos(global.gameControlControllerID[controlName]) <= -0.5);
}

return keyboardCheck || controllerCheck;
