#include "help.h"
#include "graphics.hpp"

int help_width(int a){
    std::stringstream ss;
    std::string as;
    ss<<a;
    ss>>as;
    return (genv::gout.twidth(as));
}
int help_width(int a, int b){
    std::stringstream ss;
    std::stringstream ss2;
    std::string as;
    std::string bs;
    ss<<a;
    ss>>as;
    ss2<<b;
    ss2>>bs;
    return ((genv::gout.twidth(as)+genv::gout.twidth(bs))/2+(abs((genv::gout.twidth(as))-(genv::gout.twidth(bs))))/2);
}
