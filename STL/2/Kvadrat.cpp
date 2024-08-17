#include <iostream>

using namespace std;

#include "Kvadrat.h"

Kvadrat::Kvadrat(int strana){
    this->strana = strana;
    plostina = strana * strana;
}
Kvadrat Kvadrat::postavi(){
    int strana;
    cout<<"Vnesi strana na kvadrat:";
    cin>>strana;

    return Kvadrat(strana);
}

int Kvadrat::getPlostina() const{
    return plostina;
}
