#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H
class guiElement
{
    public:
        virtual void step_event() = 0;
        virtual void draw_event() = 0;
};
#endif
