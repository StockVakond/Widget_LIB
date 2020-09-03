#include "button.h"
using namespace std;
using namespace genv;

Button::Button(Application *ca,int px, int py,int sx,int sy,string _text, int _state, int _id)
:Widget(ca,px,py,sx,sy, _state)
    {
        id=_id;
        b_text=_text;
        clicked_on=false;
    }
void Button::handle(event ev){
    if(ev.type==ev_mouse&&ev.button==btn_left){
        clicked_on=true;
        current_app->gombfv(id);
        draw();
        gout.refresh();
    }

}
void Button::draw()const{
    gout<<move_to(pos_x,pos_y)<<color(210,210,210)<<box(size_x, size_y);
    if(clicked_on)
    {
    gout<< color(191,191,191);
    }
    else{gout<<color(230,230,230);}
    gout << move_to(pos_x+1, pos_y+1)<< box(size_x-2, size_y-2);
    gout<<move_to(pos_x+size_x/2-gout.twidth(b_text)/2, pos_y+size_y/2+gout.cascent()/2)<<color(0,0,0)<<text(b_text);

}
