#include "TroDimenzionalni.h"

TroDimenzionalni::TroDimenzionalni(const char *ime):Oblik(ime){
    br++;
}

TroDimenzionalni::~TroDimenzionalni(){}

int TroDimenzionalni::getBr(){
    return br;
}
