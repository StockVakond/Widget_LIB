#include "drop_list.h"
#include "roller.h"
#include <iostream>
#include <cmath>
using namespace std;
using namespace genv;

Droplist::Droplist(Application *ca, int px, int py, int sx, int sy, vector<string>_elements, int _state)
    :Widget(ca,px,py,sx,sy, _state)
    {
        elements=_elements;
        double w=size_y/(elements.size());
        hanyferel=floor(size_y/(genv::gout.cascent()+genv::gout.cdescent()+6));
        states=max((int)(elements.size()-hanyferel+1), 1);
        rlr=new Roller(px+sx-14, py, 14, sy,elements.size(),states);
        drpos=rlr->gety();

    }


void Droplist::draw()const{

    gout<<color(150,150,150)<<move_to(pos_x-1, pos_y-2)<<box_to(pos_x+size_x+1, pos_y+size_y+1);



    string disptext;
    ///(dynamic)canvas for menu
    canvas c;
    if(elements.size()>0){
    c.open(size_x-12,elements.size()*(element_size)+1);
    //c.transparent(true);
    for(size_t i=0; i<elements.size();i++){
        bool longer=false;
        c<<color(130,130,130)<<move_to(0, i*element_size)<<box_to(size_x-14,(i+1)*element_size);
        disptext=elements[i];
        while(gout.twidth(disptext)>size_x-14-gout.twidth("...")){
                disptext=disptext.substr(0, disptext.size()-1);
                longer=true;
        }
        if(longer)
            disptext+="...";
        if(i==order_of_active){
            c<<color(160,160,160)<<move_to(1,1+i*element_size)<<box_to(size_x-16,(i+1)*element_size-2);
            c<<move_to(2,i*element_size+4+gout.cascent())<<color(0,0,0)<<text(disptext);
        }
            else{
            c<<color(220,220,220)<<move_to(1,1+i*element_size)<<box_to(size_x-16,(i+1)*element_size-2);
            c<<move_to(2,i*element_size+4+gout.cascent())<<color(0,0,0)<<text(disptext);
            }
    }
    ///drawcanv
    gout<<stamp(c,0,drpos-drpos/states+4 ,size_x-14,size_y,pos_x,pos_y);}

    rlr->draw();


}
void Droplist::handle(event ev){
    drpos=rlr->gety();
    if(elements.size()>0){
    w=(size_y)/(elements.size());
    }
    else w=0;

    if(ev.type==ev_mouse){

            if(ev.button==btn_left&&ev.pos_x<pos_x+size_x-14){
                    //if(ev.pos_y>=pos_y+i*element_size&&ev.pos_y<pos_y+(i+1)*element_size){
                order_of_active=min((ev.pos_y+drpos-drpos/states+4-pos_y)/element_size,(int)(elements.size()-1 ));
                draw();
                    //}
            }

        else{
            rlr->handle(ev);
        }
        if(ev.button==btn_wheelup){
            rlr->roll(-w);
        }
        else if(ev.button==btn_wheeldown){
            rlr->roll(w);
        }
        else if(ev.button==-btn_left){
            rlr->button_release();
        }
    }
    if(ev.keycode==key_backspace){
        remelement();
    }
    if(ev.keycode==key_delete){
        addelement("alma");
    }
    draw();

}
void Droplist::button_release(){
    rlr->button_release();
}
string Droplist::getvalue(int _id){
    if(_id!=-1)
        return elements[order_of_active]+"\n";
    else
        return "N/A";
}
void Droplist::addelement(string a){
    elements.push_back(a);
            states=max((int)(elements.size()-hanyferel+1), 1);
        rlr->set_state(states);
}
void Droplist::remelement(){
    if(order_of_active>-1&&elements.size()!=0){
    elements.erase(elements.begin()+order_of_active);
    states=max((int)(elements.size()-hanyferel+1), 1);
    rlr->set_state(states);
    rlr->roll(-w);
    }
    reset_id();
}
