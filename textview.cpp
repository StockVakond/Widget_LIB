#include "textview.h"
#include <sstream>
using namespace std;
using namespace genv;
Textview::Textview(Application *ca,int px, int py,int sx,int sy,string _text, int _state,bool bg):Widget(ca,px,py,sx,sy, _state)
    {
        dtext=_text;
        background=bg;
    }
void Textview::draw()const{
    if(background){
    gout<<move_to(pos_x,pos_y)<<color(210,210,210)<<box(size_x, size_y);
    gout << move_to(pos_x+1, pos_y+1) << color(230,230,230) << box(size_x-2, size_y-2);
    }
    gout<<move_to(pos_x+size_x/2-gout.twidth(dtext)/2, pos_y+size_y/2+gout.cascent()/2)<<color(0,0,0)<<text(dtext);

}
void Textview::handle(genv::event ev){
}
void Textview::set_textnow(int t){
    stringstream ss;
    string temp_;
    ss<<t;
    ss>>temp_;
    dtext="x"+temp_;
}
