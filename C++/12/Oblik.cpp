#include <iostream>
#include <cstring>

using namespace std;

#include "Oblik.h"

Oblik::Oblik(const char* ime){
    strcpy(this->ime, ime);
    br++;
}

Oblik::~Oblik(){}

int Oblik::getBr(){
    return br;
}

void Oblik::pecatenje() const{
    cout<<ime<<endl;
}
