#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED
#include <cmath>
#include "widget.h"
#include "help.h"

using namespace std;
class Counter : public Widget {
protected:
    int val_int;
    int val_min, val_max;
    int tsize;
    bool pressedup;
    bool presseddown;
public:
    Counter(Application *ca,int px, int py,size_t sx,int vmin,int vmax,  int val, int _state);
    Counter(Application *ca,int px, int py,int vmin,int vmax,  int val, int _state);


    void draw()const;
    void handle(genv::event ev);
    void button_release();

};

#endif // COUNTER_H_INCLUDED
