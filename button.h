#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "widget.h"
#include <string>
using namespace std;

class Button: public Widget{
protected:
    string b_text;
    bool pressed;
    bool clicked_on;
public:
    Button(Application *ca,int px, int py,int sx,int sy,string _text, int _state);
    void draw()const;
    void handle(genv::event ev);
    void button_release(){clicked_on=false;pressed=false;};
    bool get_val(){return pressed;}

};
#endif // BUTTON_H_INCLUDED
