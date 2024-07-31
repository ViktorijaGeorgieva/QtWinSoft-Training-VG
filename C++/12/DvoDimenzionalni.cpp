#include "DvoDimenzionalni.h"

DvoDimenzionalni::DvoDimenzionalni(const char* ime):Oblik(ime){
    br++;
}

DvoDimenzionalni::~DvoDimenzionalni(){}

int DvoDimenzionalni::getBr(){
    return br;
}
