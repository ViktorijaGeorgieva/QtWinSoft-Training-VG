#include "Pravoagolnik.h"

Pravoagolnik::Pravoagolnik(const char *ime):DvoDimenzionalni(ime){
    br++;
}

int Pravoagolnik::getBr(){
    return br;
}
