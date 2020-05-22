#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED
#include "widget.h"
#include "brain.h"
#include "tickbox.h"
#include <vector>
using namespace std;

class Tile : public Widget{
protected:
    int state; ///0,1,-1; 1 for white -1 for black
    pair<int, int> rel_pos;
    Brain *pa_brain;
    Tickbox *ticker;
    vector<int> bgc;
    bool background;
    bool highlight=0;
public:
    Tile(Application *ca,Brain *rev,Tickbox* _ticker,int px,int py,int sx,int sy, std::pair<int,int>rp,int _state,bool bg);
     void change_state(int target_state);
     void handle(genv::event ev);
     void button_release();
     void draw()const;
     int get_val(){return state;}
     pair<int,int> get_rp(){return rel_pos;}
     void high_light(bool what){highlight=what;};
};



#endif // TILE_H_INCLUDED
