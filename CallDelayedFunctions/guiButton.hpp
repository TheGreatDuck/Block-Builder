#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include "guiElement.hpp"
class guiButton : guiElement
{
    public:
        guiButton(int x, int y, unsigned int width, unsigned int height, void (*behavior)(), char* label);
        void step_event() override;
        void draw_event() override;

    private:
        int x;
        int y;
        unsigned int width;
        unsigned int height;
        void (*behavior)();
        char* label;
};
#endif
