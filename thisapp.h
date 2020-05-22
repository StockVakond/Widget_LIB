#ifndef THISAPP_H_INCLUDED
#define THISAPP_H_INCLUDED
#include "application.h"
#include "brain.h"
#include "widget.h"
#include "tile.h"
#include "tickbox.h"
#include "textview.h"
#include "button.h"
#include "comp.h"
#include <vector>
using namespace std;

class MyApp: public Application{
private:
    ///game
    vector<vector<Tile *>> board;///vector of columns
    Brain *reversi;
    Tickbox *hint;
    Textview *thint;
    Comp *cplayer;
    Tile *white_sc;
    Tile *black_sc;
    Textview *w_sc;
    Textview *b_sc;
    Button *exit2;

    ///menu
    Button *pvp;
    Button *pvc;
    Button *sitback;
    Button *exit;
    ///overlay
    Button *menube;
    Textview *win;

public:
    MyApp(int state_no);
    void startup();
    void events();
    void action(string action_id){}
};



#endif // THISAPP_H_INCLUDED
