#include "application.h"
#include "widget.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;
Application::Application(int state_no){
for(int i=0;i<state_no;i++){
    vector<Widget*> iwid;
    widgets.push_back(iwid);
    }
}

void Application::load_widget(Widget * current_widget,int st){
    widgets[st].push_back(current_widget);
    }
