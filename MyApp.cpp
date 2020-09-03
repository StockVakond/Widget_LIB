#include "myapp.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace genv;
MyApp::MyApp(int state_no, int width, int height):Application(state_no, width, height )
{
    genv::gout.open(w_width,w_height);
    current_state=0; ///current_state = [0, state_no)
    d1=new Droplist(this,25,25,200,100,{"1","2","3","4","5","6"},current_state);
    d2=new Droplist(this,250,25,200,100,{"a1","b2","c3","d4","e5","f6"},current_state);
    b1=new Button(this,25,150,50,40,"ADD",current_state, 1);
    t1=new Textedit(this, 100,200,200,100,"az alma nem esik messze a fajatol",current_state, true);
    startup();

}
void MyApp::startup(){

}
void MyApp::gombfv(int id){
    if(id==1){

    d2->addelement(d1->getvalue(d1->get_id()));
    cout<<d1->get_id();
    }
}
void MyApp::events(){
    event ev;
    vector<Widget*>::iterator itr;
    Widget* focus=nullptr;
    while(gin >> ev && ev.keycode!=key_escape) {

        gout<<color(200,200,200)<<move_to(0,0)<<box_to(800-1,600-1);
        for (Widget * wg : widgets[current_state]){
            wg->draw();
        }

        if (ev.type == ev_mouse && ev.button==btn_left) {
            focus=nullptr;
            for (itr=widgets[current_state].begin();itr<widgets[current_state].end();itr++) {
                if ((*itr)->active(ev.pos_x, ev.pos_y)) {
                    focus = *itr;
                }
            }
        }
        if(ev.keycode==(char)('#'))
            focus=nullptr;
        if (focus) {
            focus->handle(ev);
        }
        if(ev.type==ev_mouse&&ev.button==-btn_left){///button_release
        }
        gout << refresh;

}
}
