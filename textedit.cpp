#include "textedit.h"
#include <iostream>
using namespace std;
using namespace genv;


using namespace std;
using namespace genv;
Textedit::Textedit(Application *ca,int px, int py,int sx,int sy,string _text, int _state,bool bg):
    Widget(ca,px,py,sx,sy, _state)
    {
        background=bg;
        allt=_text;
        string oneword="";
        string onerow="";
        for(int i=0; i<_text.length(); i++){
            char nextchar=_text[i];
            oneword+=nextchar;
            if(nextchar==' ' || i==_text.length()-1){
                if(gout.twidth(onerow+oneword)<size_x-6){
                    onerow+=oneword;
                    oneword="";
                }
                else{dtext.push_back(onerow);
                     onerow=oneword;
                     oneword="";
                     }
            }
        }
        dtext.push_back(onerow);
    }
void Textedit::draw()const{
    int rowsize=gout.cascent()+gout.cdescent()+4;
    if(background){
    gout<<move_to(pos_x,pos_y)<<color(210,210,210)<<box(size_x, size_y);
    gout << move_to(pos_x+1, pos_y+1) << color(230,230,230) << box(size_x-2, size_y-2);
    }

    for(int i=0; i<dtext.size();i++){
        if(i==dtext.size()-1&&active)
        gout<<move_to(pos_x+3, pos_y+gout.cascent()+3+i*rowsize)<<color(0,0,0)<<text(dtext[i]+"|");
        else
        gout<<move_to(pos_x+3, pos_y+gout.cascent()+3+i*rowsize)<<color(0,0,0)<<text(dtext[i]);
        }
}
void Textedit::sync(){
        vector<string>_dtext;
            string oneword="";
            string onerow="";
            for(int i=0; i<allt.length(); i++){
                char nextchar=allt[i];
                oneword+=nextchar;
                if(nextchar==' ' || i==allt.length()-1){
                    if(gout.twidth(onerow+oneword)<size_x-6){
                        onerow+=oneword;
                        oneword="";
                    }
                    else{
                        _dtext.push_back(onerow);
                        onerow=oneword;
                        oneword="";
                    }
                }
                else if(gout.twidth(onerow+oneword)>size_x-6){
                    if(gout.twidth(oneword)<=size_x-6){
                        _dtext.push_back(onerow);
                        onerow=oneword;
                        oneword="";
                    }
                    else{
                        _dtext.push_back(onerow);
                        onerow=oneword.substr(0, oneword.size());
                        oneword=oneword.substr(oneword.size()-1,oneword.size());
                    }
                }
            }
            _dtext.push_back(onerow);
            dtext=_dtext;
}
void Textedit::handle(genv::event ev){
        active=true;
    if(ev.type==ev_key){
        if(ev.keycode==key_backspace){
                if(allt.length()>0)
                    allt.erase(allt.begin()+allt.length()-1);

        }
        else if(ev.keycode>0&&ev.keycode%256!=10&&ev.keycode!=key_enter){
            write((char)(ev.keycode));
        }
        sync();
        if((dtext.size())*rowsize> size_y&&allt.length()>0)
            allt.erase(allt.begin()+allt.length()-1);
        sync();
    }
    draw();
    active=false;
}

void Textedit::write(char q){
    if((dtext.size())*rowsize<= size_y)
        allt+=q;

}

