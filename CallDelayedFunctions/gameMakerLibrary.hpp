#define GMEXPORT extern "C" __declspec(dllexport)

#include "variableWrapper.hpp"

#define pr_pointlist 1
#define pr_linelist 2
#define pr_linestrip 3
#define pr_trianglelist 4
#define pr_trianglestrip 5
#define pr_trianglefan 6

#include "gameMakerFunctions\3DGraphics\d3d_model.hpp"
#include "gameMakerFunctions\3DGraphics\d3d_shape.hpp"
#include "gameMakerFunctions\3DGraphics\d3d_transform.hpp"
#include "gameMakerFunctions\3DGraphics\d3d_primitive.hpp"

#include "gameMakerFunctions\userInteraction\mouse.hpp"
#include "gameMakerFunctions\userInteraction\keyboard.hpp"
#include "gameMakerFunctions\userInteraction\joystick.hpp"

//vk_nokey
//vk_anykey
#define vk_left 37
#define vk_right 39
#define vk_up 38
#define vk_down 40
#define vk_enter 13
#define vk_escape 27
#define vk_space 32
#define vk_shift 16
#define vk_control 17
/*#define vk_alt
#define vk_backspace
#define vk_tab
#define vk_home
#define vk_end
#define vk_delete
#define vk_insert
#define vk_pageup
#define vk_pagedown
#define vk_pause
#define vk_printscreen
#define vk_f1
#define vk_f2
#define vk_f3
#define vk_f4
#define vk_f5
#define vk_f6
#define vk_f7
#define vk_f8
#define vk_f9
#define vk_f10
#define vk_f11
#define vk_f12
#define vk_numpad0
#define vk_numpad1
#define vk_numpad2
#define vk_numpad3
#define vk_numpad4
#define vk_numpad5
#define vk_numpad6
#define vk_numpad7
#define vk_numpad8
#define vk_numpad9
#define vk_multiply
#define vk_divide
#define vk_add
#define vk_subtract
#define vk_decimal*/

#if 0
void joystick_name(int id, int* result);
#endif

#include "gameMakerFunctions\gameGraphics\fontsAndText.hpp"
#include "gameMakerFunctions\gameGraphics\drawingShapes.hpp"

/*draw_set_font(font)
draw_set_halign(halign)

        fa_left
        fa_center
        fa_right

draw_set_valign(valign)

        fa_top
        fa_middle
        fa_bottom*/

//draw_text_ext(int x, int y, char* string, int sep, int w)
//string_width(char* string)
//string_height(char* string)
//string_width_ext(char* string, int sep, int w)
//string_height_ext(char* string, int sep, int w)

/*draw_text_transformed(int x, int y, char* string, int xscale, int yscale, int angle)
draw_text_ext_transformed(x,y,string,sep,w,xscale,yscale,angle)
draw_text_color(x,y,string,c1,c2,c3,c4,alpha)
draw_text_ext_color(x,y,string,sep,w,c1,c2,c3,c4,alpha)
draw_text_transformed_color(x,y,string,xscale,yscale,angle,c1,c2,c3,c4,alpha)
draw_text_ext_transformed_color(x,y,string,sep,w,xscale,yscale,angle,c1,c2,c3,c4, double alpha)*/

#include "gameMakerFunctions\gamePlay\rooms.hpp"

#include "gameMakerFunctions\builtInVariables.hpp"
