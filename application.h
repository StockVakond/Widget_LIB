#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <string>
#include <vector>
class Widget;
using namespace std;
class Application{
protected:
    vector<vector<Widget*>> widgets;
    int states;
public:
    Application(int state_no);
    virtual ~Application(){};
    virtual void events()=0;
    virtual void action(string)=0;
    void load_widget(Widget * current_widget,int st);
    int get_state(){return states;}
    void set_state(int stateset){states=stateset;}
};


#endif // APPLICATION_H_INCLUDED
