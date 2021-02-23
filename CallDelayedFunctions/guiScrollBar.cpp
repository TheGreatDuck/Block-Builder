#include "gameMakerLibrary.hpp"
#include "guiScrollBar.hpp"

guiScrollBar::guiScrollBar(int x, int y, unsigned int width, unsigned int height, int min_range, int max_range, unsigned int scrollHeight, unsigned int* varirable, bool isHorizontal)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->min_range = min_range;
    this->max_range = max_range;
    this->scrollHeight = scrollHeight;
    this->varirable = varirable;
    this->isHorizontal = isHorizontal;
    this->held = false;
}

void guiScrollBar::step_event()
{
    if (mouse_check_button_pressed(1) == 1)
    {
        int mx = *mouse_x;
        int my = *mouse_y;

        if (isHorizontal)
        {
            if (((my - y) <= height) && my >= y && (mx-x) <= 32 && mx >= x && *varirable >= min_range+1)
                *varirable = *varirable - 1;

            if (((my - y) <= height) && my >= y && (mx-x) <= width && mx >= width-32 && *varirable + 1 <= max_range)
                *varirable = *varirable + 1;

            if (((my - y) <= height) && my >= y && (mx - x) >= ((*varirable - min_range)*(width-64))/(max_range + scrollHeight - min_range) + 32 && (mx - x) <= ((*varirable + scrollHeight - min_range)*(width-64))/(max_range + scrollHeight - min_range) + 32)
                held = true;
        } else
        {
            if (((mx - x) <= width) && mx >= x && (my-y) <= 32 && my >= y && *varirable >= min_range+1)
                *varirable = *varirable - 1;

            if (((mx - x) <= width) && mx >= x && (my-y) <= height && my >= height-32 && *varirable + 1 <= max_range)
                *varirable = *varirable + 1;

            if (((mx - x) <= width) && mx >= x && (my - y) >= ((*varirable - min_range)*(height-64))/(max_range + scrollHeight - min_range) + 32 && (my - y) <= ((*varirable + scrollHeight - min_range)*(height-64))/(max_range + scrollHeight - min_range) + 32)
                held = true;
        }
    }

    if (held)
    {
        int mx = *mouse_x;
        int my = *mouse_y;

        if (!mouse_check_button(1))
            held = false;
        else if (isHorizontal)
        {
            if (mx - x >= 32)
                *varirable = ((max_range + scrollHeight - min_range)*(mx - x - 32))/(width-64) + min_range;
            else
                *varirable = min_range;
        } else
        {
            if (my - y >= 32)
                *varirable = ((max_range + scrollHeight - min_range)*(my - y - 32))/(height-64) + min_range;
            else
                *varirable = min_range;
        }

        if (*varirable > max_range)
            *varirable = max_range;
    }
}

void guiScrollBar::draw_event()
{
    double gray = make_color_rgb(192,192,192);
    double black = make_color_rgb(0,0,0);
    double white = make_color_rgb(255,255,255);

    draw_set_color(gray);
    draw_rectangle(x,y,x+width,y+height,0);
    draw_set_color(black);
    draw_rectangle(x,y,x+width,y+height,1);
    draw_rectangle(x+1,y+1,x+width-1,y+height-1,1);

    if (isHorizontal)
    {
        draw_rectangle(x,y,x+32,y+height,0);
        draw_rectangle(x+width-32,y,x+width,y+height,0);

        if (!held)
            draw_set_color(white);
        draw_rectangle(x+((*varirable - min_range)*(width-64))/(max_range + scrollHeight - min_range) + 32,y,x+((*varirable + scrollHeight - min_range)*(width-64))/(max_range + scrollHeight - min_range) + 32,y+height,0);
    } else
    {
        draw_rectangle(x,y,x+width,y+32,0);
        draw_rectangle(x,y+height-32,x+width,y+height,0);

        if (!held)
            draw_set_color(white);
        draw_rectangle(x,y+((*varirable - min_range)*(height-64))/(max_range + scrollHeight - min_range) + 32,x+width,y+((*varirable + scrollHeight - min_range)*(height-64))/(max_range + scrollHeight - min_range) + 32,0);
    }

    draw_set_color(white);
}
