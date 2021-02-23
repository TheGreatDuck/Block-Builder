#ifndef GUI_SCROLL_BAR_H
#define GUI_SCROLL_BAR_H

#include "guiElement.hpp"
class guiScrollBar : guiElement
{
    public:
        guiScrollBar(int x, int y, unsigned int width, unsigned int height, int min_range, int max_range, unsigned int scrollHeight, unsigned int* varirable, bool isHorizontal);
        void step_event() override;
        void draw_event() override;

    private:
        int x;
        int y;
        unsigned int width;
        unsigned int height;
        int min_range;
        int max_range;
        unsigned int scrollHeight;
        unsigned int* varirable;
        bool isHorizontal;
        bool held;
};
#endif
