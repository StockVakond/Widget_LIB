#ifndef TEXTVIEW_H_INCLUDED
#define TEXTVIEW_H_INCLUDED

#include "widget.h"

using namespace std;

class Textview : public Widget{
protected:
    string dtext;
    bool background;
public:
    Textview(Application *ca,int px, int py,int sx,int sy,string _text, int _state,bool bg);
    void draw()const;
    void handle(genv::event ev);
    void set_text(string t){dtext=t;};
};


#endif // TEXTVIEW_H_INCLUDED
