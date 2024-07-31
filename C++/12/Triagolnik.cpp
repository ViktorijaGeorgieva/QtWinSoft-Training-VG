#include "Triagolnik.h"

Triagolnik::Triagolnik(const char *ime):DvoDimenzionalni(ime){
    br++;
}

int Triagolnik::getBr(){
    return br;
}
