#ifdef DEFINE_WRAPPERS
ADD_FUNCTION(joystick_exists)
ADD_FUNCTION(joystick_name)
ADD_FUNCTION(joystick_axes)
ADD_FUNCTION(joystick_buttons)
ADD_FUNCTION(joystick_has_pov)
ADD_FUNCTION(joystick_direction)
ADD_FUNCTION(joystick_check_button)
ADD_FUNCTION(joystick_xpos)
ADD_FUNCTION(joystick_ypos)
ADD_FUNCTION(joystick_zpos)
ADD_FUNCTION(joystick_rpos)
ADD_FUNCTION(joystick_upos)
ADD_FUNCTION(joystick_vpos)
ADD_FUNCTION(joystick_pov)
#endif

void joystick_exists(int id, int* result);
#ifdef DEFINE_WRAPPERS
void joystick_exists(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_exists, result, 1, id);
}
#endif

/*void joystick_name(int id, int* result);
#ifdef DEFINE_WRAPPERS
void joystick_name(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_name, result, 1, id);
}
#endif*/

void joystick_axes(int id, int* result);
#ifdef DEFINE_WRAPPERS
void joystick_axes(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_axes, result, 1, id);
}
#endif

void joystick_buttons(int id, int* result);
#ifdef DEFINE_WRAPPERS
void joystick_buttons(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_buttons, result, 1, id);
}
#endif

void joystick_has_pov(int id, int* result);
#ifdef DEFINE_WRAPPERS
void joystick_has_pov(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_has_pov, result, 1, id);
}
#endif

void joystick_direction(int id, int* result);
#ifdef DEFINE_WRAPPERS
void joystick_direction(int id, int* result)
{
    addDelayedFunctionCall(FP_joystick_direction, result, 1, id);
}
#endif

#ifdef DEFINE_WRAPPERS
/*joystick_check_button(id,numb)
joystick_xpos(id)
joystick_ypos(id)
joystick_zpos(id)
joystick_rpos(id)
joystick_upos(id)
joystick_vpos(id)
joystick_pov(id)*/
#endif
