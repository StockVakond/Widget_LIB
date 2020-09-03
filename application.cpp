#include "application.h"
#include "widget.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;
Application::Application(int state_no, int _w_width, int _w_height){
for(int i=0;i<state_no;i++){
    vector<Widget*> iwid;
    widgets.push_back(iwid);
    }
w_width=_w_width;
w_height=_w_height;
}

void Application::load_widget(Widget * current_widget,int st){
    widgets[st].push_back(current_widget);
    }
