#include "roller.h"
#include <iostream>
using namespace std;
using namespace genv;
Roller::Roller(int px, int py, int sx, int sy,int s_elements, int _states):
        pos_x(px),pos_y(py),size_x(sx),size_y(sy), states(_states)
        {
            rpos_y=0;
            grabbed = false;
            dy=0;
            r_y=size_y/(states);
        }

void Roller::roll(int a){
if(rpos_y+a>0){
    if(rpos_y+a<size_y-r_y)
        rpos_y+=a;
    else rpos_y=size_y-r_y;
}
else rpos_y=0;
}
void Roller::handle(event ev){
    if(ev.type==ev_mouse){
        if(ev.button==btn_left){
            if(ev.pos_y>=rpos_y+pos_y&&ev.pos_y<=rpos_y+pos_y+r_y){
                grabbed=true;
                dy=ev.pos_y-(pos_y+rpos_y);
                this->draw();
            }
        }

        else if(ev.button==0&&grabbed){
            if(ev.pos_x>pos_x-50&&ev.pos_x<pos_x+size_x+50){
                if(ev.pos_y>=pos_y+dy){
                    if(ev.pos_y<=pos_y+size_y-r_y+dy)
                        rpos_y=ev.pos_y-pos_y-dy;
                    else rpos_y=size_y-r_y;
                }
                else
                rpos_y=0;
            }
                else
                rpos_y=0;

        }
    }
}
void Roller::draw()const{
    ///line
    gout<<color(180,180,180)<<move_to(pos_x,pos_y)<<box_to(pos_x+size_x, pos_y+size_y);
    gout<<color(170,170,170)<<move_to(pos_x+2,pos_y+2)<<box_to(pos_x+size_x-2, pos_y+size_y-2);
    ///slider
    gout<<color(195,195,195)<<move_to(pos_x+1, pos_y+rpos_y+1)<<box_to(pos_x+size_x-1, pos_y+rpos_y+r_y-1);
    if(!grabbed){
    gout<<color(210,210,210)<<move_to(pos_x+2, pos_y+rpos_y+2)<<box_to(pos_x+size_x-2, pos_y+rpos_y+r_y-2);
    }
    else{
    gout<<color(190,190,190)<<move_to(pos_x+2, pos_y+rpos_y+2)<<box_to(pos_x+size_x-2, pos_y+rpos_y+r_y-2);
    }
    }
void Roller::button_release(){
grabbed=false;
dy=0;
draw();
}
