#include <iostream>

using namespace std;

#include "Pravoagolnik.h"

Pravoagolnik::Pravoagolnik(int sirina, int dolzina){
    this->sirina = sirina;
    this->dolzina = dolzina;
    plostina = sirina * dolzina;
}

Pravoagolnik Pravoagolnik::postavi(){
    int sirina, dolzina;
    cout<<"Vnesi sirina i dolzina na pravoagolnikot:";
    cin>>sirina>>dolzina;

    return Pravoagolnik(sirina, dolzina);
}

int Pravoagolnik::getPlostina() const{
    return plostina;
}
