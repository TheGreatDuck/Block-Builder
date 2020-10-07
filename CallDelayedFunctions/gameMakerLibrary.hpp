#define GMEXPORT extern "C" __declspec(dllexport)
//define GMEXPORT extern "C"

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

#include "gameMakerFunctions\gameGraphics\fontsAndText.hpp"

#include "gameMakerFunctions\gamePlay\rooms.hpp"

void sprite_get_texture(int* spr, double subimg, int* returnValue);
void sprite_add(const char* fname, double imgnumb, double removeback, double smooth, double xorig, double yorig, int* ind);
void draw_sprite(int* spr, double subimg, double x, double y);
