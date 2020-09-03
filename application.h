#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <string>
#include <vector>
class Widget;
using namespace std;
class Application{
protected:
    vector<vector<Widget*>> widgets;
    int current_state;
    int w_width;
    int w_height;
public:
    Application(int state_no, int _w_width, int _w_height);
    virtual ~Application(){};
    virtual void events()=0;
    virtual void action(string)=0;
    virtual void gombfv(int id)=0;
    void load_widget(Widget * current_widget,int st);
    int get_state(){return current_state;}
    void set_state(int stateset){current_state=stateset;}
};


#endif // APPLICATION_H_INCLUDED
