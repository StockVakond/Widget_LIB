#ifndef ROLLER_H_INCLUDED
#define ROLLER_H_INCLUDED
#include "graphics.hpp"

#include <iostream>

using namespace genv;
class Roller{
protected:
    int pos_x;
    int pos_y;
    int size_x;
    int size_y;
    int rpos_y;
    bool grabbed;
    int dy;
    int states;
    double r_y;
public:

    Roller(int px, int py, int sx, int sy,int s_elements, int _states);
    int gety(){return rpos_y;}
     void handle(event ev);
     void draw()const;
     void roll(int a);
     void button_release();
     bool is_grabbed(){return grabbed;};
     void set_state(int st){states=st;r_y=size_y/(st);};
};


#endif // ROLLER_H_INCLUDED
