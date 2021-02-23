#include "gameMakerLibrary.hpp"
#include "guiButton.hpp"

guiButton::guiButton(int x, int y, unsigned int width, unsigned int height, void (*behavior)(), char* label)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->behavior = behavior;
    this->label = label;
}

void guiButton::step_event()
{
    if (mouse_check_button_pressed(1) == 1)
    {
        int mx = *mouse_x;
        int my = *mouse_y;
        if (((mx - x) <= width) && ((my - y) <= height) && mx >= x && my >= y)
            behavior();
    }
}

void guiButton::draw_event()
{
    double gray = make_color_rgb(192,192,192);
    double black = make_color_rgb(0,0,0);
    double white = make_color_rgb(255,255,255);
    draw_set_color(gray);
    draw_rectangle(x,y,x+width,y+height,0);
    draw_set_color(black);
    draw_rectangle(x,y,x+width,y+height,1);
    draw_set_color(black);
    draw_rectangle(x+1,y+1,x+width-1,y+height-1,1);
    draw_set_halign(*fa_center);
    draw_set_valign(*fa_middle);
    draw_text(x + (width/2.0), y + (height/2.0), label);
    draw_set_color(white);
}
