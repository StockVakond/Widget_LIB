#ifndef TEXTEDIT_H_INCLUDED
#define TEXTEDIT_H_INCLUDED
#include "widget.h"
#include <vector>
using namespace std;

class Textedit : public Widget{
protected:
    vector<string> dtext;
    string allt;
    bool background;
    bool active=false;
    int rowsize=genv::gout.cascent()+genv::gout.cdescent()+4;
public:
    Textedit(Application *ca,int px, int py,int sx,int sy,string _text, int _state,bool bg);
    void draw()const;
    void handle(genv::event ev);
    void set_text(string t);
    void write(char q);
    void sync();
};




#endif // TEXTEDIT_H_INCLUDED
