#ifndef DROP_LIST_H_INCLUDED
#define DROP_LIST_H_INCLUDED
#include "widget.h"
#include "roller.h"
#include <vector>
#include <string>

using namespace std;

class Droplist : public Widget{
protected:
    vector<string> elements;
    int order_of_active=-1;
    int element_size=genv::gout.cascent()+genv::gout.cdescent()+4;
    int drpos;
    double w;
    int top_order=0;
    Roller *rlr;

public:
    Droplist(Application *, int px, int py, int sx, int sy, vector<string>_elements, int _state);
     void draw()const;
     void handle(genv::event ev);
     string getvalue();
     void button_release();
    int get_id(){return order_of_active;}
    void addelement(string);
    void remelement(int id);
    void reset_id(){order_of_active=min(order_of_active, int(elements.size()));}

};

#endif // DROP_LIST_H_INCLUDED
