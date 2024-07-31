#include "Prsten.h"

Prsten::Prsten(const char *ime):DvoDimenzionalni(ime){
    br++;
}

int Prsten::getBr(){
    return br;
}
