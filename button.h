#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "widget.h"
#include <string>
using namespace std;

class Button: public Widget{
protected:
    string b_text;
    bool clicked_on;
    int id;

public:
    Button(Application *ca,int px, int py,int sx,int sy,string _text, int _state, int _id);
    void draw()const;
    void handle(genv::event ev);
    void button_release(){clicked_on=false;};

};
#endif // BUTTON_H_INCLUDED
