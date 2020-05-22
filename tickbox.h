#ifndef TICKBOX_H_INCLUDED
#define TICKBOX_H_INCLUDED

#include "widget.h"

using namespace std;

class Tickbox : public Widget {
protected:
    bool ticked;
public:
    Tickbox(Application *ca,int px, int py,int s,bool in_tick, int _state);
    void draw()const;
    void handle(genv::event ev);
    bool get_ticked(){return ticked;}
    void switch_tick(bool t){
        ticked=t;
    }

};


#endif // TICKBOX_H_INCLUDED
