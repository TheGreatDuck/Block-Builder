#ifdef DEFINE_WRAPPERS
ADD_FUNCTION(get_mouse_x)
ADD_FUNCTION(get_mouse_y)
ADD_FUNCTION(get_mouse_button)
ADD_FUNCTION(get_mouse_lastbutton)
ADD_FUNCTION(mouse_check_button)
ADD_FUNCTION(mouse_check_button_pressed)
ADD_FUNCTION(mouse_check_button_released)
ADD_FUNCTION(mouse_wheel_up)
ADD_FUNCTION(mouse_wheel_down)
#endif

void get_mouse_x(int* coord);
#ifdef DEFINE_WRAPPERS
void get_mouse_x(int* coord)
{
    addDelayedFunctionCall(FP_get_mouse_x, coord, 1);
}
#endif

void get_mouse_y(int* coord);
#ifdef DEFINE_WRAPPERS
void get_mouse_y(int* coord)
{
    addDelayedFunctionCall(FP_get_mouse_y, coord, 1);
}
#endif

void get_mouse_button(int* button);
#ifdef DEFINE_WRAPPERS
void get_mouse_button(int* button)
{
    addDelayedFunctionCall(FP_get_mouse_button, button, 1);
}
#endif

void get_mouse_lastbutton(int* button);
#ifdef DEFINE_WRAPPERS
void get_mouse_lastbutton(int* button)
{
    addDelayedFunctionCall(FP_get_mouse_lastbutton, button, 1);
}
#endif

void mouse_check_button(double numb, int* returnValue);
#ifdef DEFINE_WRAPPERS
void mouse_check_button(double numb, int* returnValue)
{
    addDelayedFunctionCall(FP_mouse_check_button, returnValue, 1, numb);
}
#endif

void mouse_check_button_pressed(double numb, int* returnValue);
#ifdef DEFINE_WRAPPERS
void mouse_check_button_pressed(double numb, int* returnValue)
{
    addDelayedFunctionCall(FP_mouse_check_button_pressed, returnValue, 1, numb);
}
#endif

void mouse_check_button_released(double numb, int* returnValue);
#ifdef DEFINE_WRAPPERS
void mouse_check_button_released(double numb, int* returnValue)
{
    addDelayedFunctionCall(FP_mouse_check_button_released, returnValue, 1, numb);
}
#endif

void mouse_wheel_up(int* returnValue);
#ifdef DEFINE_WRAPPERS
void mouse_wheel_up(int* returnValue)
{
    addDelayedFunctionCall(FP_mouse_wheel_up, returnValue, 1);
}
#endif

void mouse_wheel_down(int* returnValue);
#ifdef DEFINE_WRAPPERS
void mouse_wheel_down(int* returnValue)
{
    addDelayedFunctionCall(FP_mouse_wheel_down, returnValue, 1);
}
#endif
