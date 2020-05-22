#include "counter.h"
#include <string>
#include <sstream>


using namespace genv;
using namespace std;
Counter::Counter(Application *ca,int px, int py,size_t sx,int vmin,int vmax,  int val, int _state)///fix meret van megadva
    :Widget(ca,px,py,((sx+30.0)/2+abs((sx-30.0)/2)),genv::gout.cascent()+genv::gout.cdescent()+9, _state)
    {
        ///foolproof:
        ///a max és min nem kell hogy jo sorrendben legyen,
        ///ha valamelyik nem ferne mar ki a fix mereten, ott az erteket addig valtoztatjuk mig ki nem fer
        ///ha a kezdoertek nincs benne a tartomanyban, akkor a kezdoertek a minimum ertek lesz
        ///a szelesseg legalabb 1 karaktert abrazolni tud
        tsize=size_x-20;
        if(vmin<vmax){
            val_min=vmin;
            val_max=vmax;
        }
        else{
            val_max=vmin;
            val_min=vmax;
        }
        if(val>val_max || val < val_min){
            val_int=val_min;}
        else {val_int=val;}

        while(help_width(val_min)>tsize){
            val_min++;
        }
        while(help_width(val_max)>tsize){
            val_max--;
        }
        pressedup=false;
        presseddown=false;
    }

Counter::Counter(Application *ca,int px, int py,int vmin,int vmax,  int val, int _state)///size_x a max/min számokhoz mérten
    :Widget(ca,px,py,help_width(vmin,vmax)+20,genv::gout.cascent()+genv::gout.cdescent()+9, _state)
    {
        ///foolproof
        ///a max és min nem kell hogy jo sorrendben legyen,
        ///ha a kezdoertek nincs benne a tartomanyban akkor a kezdoertek a minimum ertek lesz
        ///a szelesseg mindig a legszelesebb megjelenitheto szamhoz igazodik min/max alapjan
        tsize=help_width(vmin,vmax);
        if(vmin<vmax){
            val_min=vmin;
            val_max=vmax;
        }
        else{
            val_max=vmin;
            val_min=vmax;
        }
        if(val>val_max || val < val_min){
            val_int=val_min;}
        else {val_int=val;}
        pressedup=false;
        presseddown=false;

    }
/*string Counter::getvalue(){
    stringstream ss;
    ss<<val_int;
    string t;
    ss>>t;
    return t+"\n";
}*/
void Counter::button_release(){
    pressedup=false;
    presseddown=false;
    //draw();
}
void Counter::draw()const{
    stringstream ss;
    ss<<val_int;
    string t;
    ss>>t;
    gout<<move_to(pos_x-1, pos_y-1)<<color(150,150,150)<<box(size_x+3, size_y+2);
    gout << move_to(pos_x, pos_y) << color(130,130,130) << box(size_x-10, size_y);
    gout << move_to(pos_x+2, pos_y+2) << color(240,240,240) << box(size_x-14, size_y-4);
    gout << move_to(pos_x+4, pos_y+4+gout.cascent()) <<color(0,0,0)<<text(t);

    gout << color(170,170,170)<<move_to(pos_x+size_x-10, pos_y)<<box(11, size_y/2);
    if(!pressedup)
    gout << color(210,210,210)<< move_to(pos_x+size_x-9, pos_y+1)<<box(9, size_y/2-2);
    else gout << color(190,190,190)<< move_to(pos_x+size_x-9, pos_y+1)<<box(9, size_y/2-2);

    gout << color(170,170,170)<<move_to(pos_x+size_x-10, pos_y+size_y/2)<<box(11, size_y/2);
    if(!presseddown)
    gout <<color(210,210,210)<< move_to(pos_x+size_x-9, pos_y+size_y/2+1)<<box(9, size_y/2-2);
    else gout <<color(190,190,190)<< move_to(pos_x+size_x-9, pos_y+size_y/2+1)<<box(9, size_y/2-2);
    gout<<color(130,130,130)<<move_to(pos_x+size_x-8, pos_y+size_y/2-4)<<line_to(pos_x+size_x-5, pos_y+3);
    gout<<line_to(pos_x+size_x-2, pos_y+size_y/2-4);
    gout<<color(130,130,130)<<move_to(pos_x+size_x-8, pos_y+size_y/2+3)<<line_to(pos_x+size_x-5, pos_y+size_y-4);
    gout<<line_to(pos_x+size_x-2, pos_y+size_y/2+3);
}

void Counter::handle(event ev){
    ///ha a pggdwn/pgup-pal kifutnank a hatarokbol, akkor a hatart kapja meg erteknek
    int mb =0;
    if(ev.type==ev_mouse){
        if(ev.button==btn_left){
            if(ev.pos_x>=pos_x+size_x-10&&ev.pos_x<=pos_x+size_x){
                if(ev.pos_y>=pos_y&&ev.pos_y<=pos_y+size_y/2){
                    mb=1;
                    pressedup=true;
                    draw();
                }
                else if(ev.pos_y>=pos_y+size_y/2&&ev.pos_y<=pos_y+size_y){
                    mb=(-1);
                    presseddown=true;
                    //draw();
                }
            }
        }

    }
    if(val_int+1<=val_max){
        if((ev.keycode==key_up || mb==1)){
            val_int++;
        }
        else if(ev.keycode==key_pgup){
            if(val_int+10<=val_max)
                val_int+=10;
            else val_int=val_max;
            }
        }

    if(val_int-1>=val_min){
        if(ev.keycode==key_down || mb==-1){
            val_int--;
        }
        else if(ev.keycode==key_pgdn)
            if(val_int-10>=val_min)
                val_int-=10;
            else val_int=val_min;
        }
}

