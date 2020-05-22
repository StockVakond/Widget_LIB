#include "thisapp.h"
#include <vector>
using namespace std;
using namespace genv;
MyApp::MyApp(int state_no):Application(state_no)
{
    genv::gout.open(800,800);
    states=state_no;
    startup();

}
void MyApp::startup(){
    reversi=new Brain(0);
    hint=new Tickbox(this,100,350,gout.cascent()+gout.cdescent()+6, true,0);
    thint=new Textview(this, 50,350,gout.twidth("Hints")+6,gout.cascent()+gout.cdescent()+6,"Hints",0,false);
    reversi->initiate(board,this,hint);
    vector<vector<double>> _Vmap={{99,-16,8,6,6,8,-16,99},{-16,-24,-4,-3,-3,-4,-24,-16},{8,-4,7,4,4,7,-4,8},{6,-3,4,0,0,4,-3,6},{6,-3,4,0,0,4,-3,6},{8,-4,7,4,4,7,-4,8},{-16,-24,-4,-3,-3,-4,-24,-16},{99,-16,8,6,6,8,-16,99}};
    vector<vector<Tile *>> *ptb = &board;
    cplayer=new Comp(_Vmap,ptb,reversi);
    pvp=new Button(this,300,250,200,50,"2 Player Mode",1);
    pvc=new Button(this,300,200,200,50,"1 Player Mode",1);
    sitback=new Button(this,300,300,200,50,"Just Watch",1);
    exit=new Button(this,300,350,200,50,"Exit Game",1);
    exit2=new Button(this,700,50,50,50,"X",0);
    white_sc= new Tile(this,reversi,hint,600,350,50,50,{0,0},0,false);
    white_sc->change_state(1);
    w_sc=new Textview(this, 640,370,gout.twidth("x2")+6,gout.cascent()+gout.cdescent()+6,"x2",0,false);
    black_sc= new Tile(this,reversi,hint,600,400,50,50,{0,0},0,false);
    black_sc->change_state(-1);
    b_sc=new Textview(this, 640,420,gout.twidth("x2")+6,gout.cascent()+gout.cdescent()+6,"x2",0,false);
    states=1;
    menube=new Button(this,300,650,200,50,"Exit to Menu",2);
    win= new Textview(this, 300,600,200,50,"The Winner Is ",2,false);
}
void MyApp::events(){
    event ev;
    vector<Widget*>::iterator itr;
    Widget* focus=nullptr;
    bool pp=false;
    bool pc=false;
    bool noint=false;
    bool ex=false;
    int ct=0;
    int fin=0;
    while(gin >> ev &&(char)(ev.keycode)!=('q')&&!ex) {
        if(pvp->get_val()){
            pp=true;
        }
        else if(pvc->get_val()){
            pc=true;
        }
        else if(sitback->get_val()){
            noint=true;
            states=0;
            hint->switch_tick(false);
            sitback->button_release();
        }
        else if(exit->get_val())
            ex=true;
        if(exit2->get_val()or menube->get_val()){
            states=1;
            pp=false;
            pc=false;
            noint=false;
            reversi->reset();
            reversi->look_for_moves();
            reversi->tile_sync(board);
            hint->switch_tick(true);
        }
        if(pp||pc){
            states=0;
        }
        gout<<color(200,200,200)<<move_to(0,0)<<box_to(800-1,800-1);
        for (Widget * wg : widgets[states]){
            wg->draw();
        }
        gin.timer(40);
        fin=reversi->get_no_moves();
        if(fin>1){
            states=2;
            pp=false;
            pc=false;
            noint=false;
        }
        if(states==2){
                if(reversi->get_score(1)>reversi->get_score(-1)){
                        win->set_text("The White Player Won");}
                else if(reversi->get_score(1)==reversi->get_score(-1)){
                        win->set_text("Wow It's a TIE");
                }
                else win->set_text("The Black Player Won");
                for (Widget * wg : widgets[0]) {
                    wg->draw();
                }
                if(exit2->active(ev.pos_x,ev.pos_y))
                    exit2->handle(ev);
        }
        if(pc){
            if(ev.type==ev_timer&&reversi->get_player()==-1){
                ct++;
                if(ct==3){
                    cplayer->c_think();
                    cplayer->c_move();
                    reversi->look_for_moves();
                    reversi->tile_sync(board);
                    ct=0;
                }
            }
        }
        if(noint){
            if(ev.type==ev_timer){
                ct++;
                if(ct==3){
                    cplayer->c_think();
                    cplayer->c_move();
                    reversi->look_for_moves();
                    reversi->tile_sync(board);
                    ct=0;
                }
            }
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            if(pp or ((ev.pos_x<200 or ev.pos_x>600)&&(ev.pos_y<200 or ev.pos_y>600)) or (reversi->get_player()==1&&!noint) or states==1 or states==2){
                for (itr=widgets[states].begin();itr<widgets[states].end();itr++) {
                    if ((*itr)->active(ev.pos_x, ev.pos_y)) {
                        focus = *itr;
                    }
                }
            }

        }
        if(ev.type==ev_mouse&&ev.button==btn_right&&states==0&&!noint){
            if(ev.pos_x>=200&&ev.pos_x<=600&&ev.pos_y>=200&&ev.pos_y<600){
                for(auto q:board){
                    for(auto e:q){
                        if(e->active(ev.pos_x,ev.pos_y)){
                            reversi->show_move(e,board);
                        }
                    }
                }
            }
        }
        if(ev.type==ev_mouse&&ev.button==-btn_right&&states==0){
            reversi->dont_show(board);
        }
        if(ev.keycode==key_escape)
            focus=nullptr;
        if (focus) {
            focus->handle(ev);
            focus=nullptr;
        }
        if(ev.type==ev_mouse&&ev.button==-btn_left){
            pvp->button_release();
            pvc->button_release();
            exit->button_release();
            exit2->button_release();
            menube->button_release();
            sitback->button_release();
        }
        if(ev.type==ev_mouse&&ev.button==btn_left)
            reversi->tile_sync(board);

        w_sc->set_textnow(reversi->get_score(1));
        b_sc->set_textnow(reversi->get_score(-1));

    gout << refresh;

}
}
