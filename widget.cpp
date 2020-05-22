#include "widget.h"
using namespace genv;
using namespace std;
Widget::Widget(Application * ca,int px, int py, size_t sx, size_t sy, int _state):
        current_app(ca),pos_x(px),pos_y(py),size_x(sx),size_y(sy)
        {ca->load_widget(this, _state);}


bool Widget::active(int ev_x, int ev_y){
    return(ev_x>pos_x&&ev_x<(pos_x+size_x)&&ev_y>pos_y&&ev_y<(pos_y+size_y));
}
