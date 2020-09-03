#ifndef MYAPP_H_INCLUDED
#define MYAPP_H_INCLUDED
#include "application.h"
#include "brain.h"
#include "widget.h"
#include "tickbox.h"
#include "textview.h"
#include "button.h"
#include "drop_list.h"
#include "textedit.h"
#include <vector>
using namespace std;

class MyApp: public Application{
private:
    Droplist* d1;
    Droplist* d2;
    Button* b1;
    Textedit* t1;
public:
    void gombfv(int id);
    MyApp(int state_no, int width, int height);
    void startup();
    void events();
    void action(string action_id){}
};





#endif // MYAPP_H_INCLUDED
