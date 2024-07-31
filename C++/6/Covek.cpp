#include <iostream>
#include <cstring>

using namespace std;

#include "Covek.h"

Covek::Covek(){}

Covek::Covek(string ime, string prezime, string adresa, string telefon){
    this->ime = ime;
    this->prezime = prezime;
    this->adresa = adresa;
    this->telefon = telefon;
}

void Covek::pecatenje() const{
    cout<<ime<<" "<<prezime<<" "<<adresa<<" "<<telefon<<endl;
}
