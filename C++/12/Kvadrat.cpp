#include "Kvadrat.h"

Kvadrat::Kvadrat(const char *ime):DvoDimenzionalni(ime){
    br++;
}

int Kvadrat::getBr(){
    return br;
}
