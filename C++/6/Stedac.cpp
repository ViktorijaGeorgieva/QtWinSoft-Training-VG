#include <iostream>

using namespace std;

#include "Covek.h"
#include "Stedac.h"

Stedac::Stedac(){}

int Stedac::kamata = 1;
int Stedac::brojStedaci = 0;

int Stedac::getKamata(){
    return kamata;
}

int Stedac::getBrojStedaci(){
    return brojStedaci;
}

Stedac::Stedac(string ime, string prezime, string adresa, string telefon, int bilans, int kredit):lice(ime, prezime, adresa, telefon){
    this->bilans = bilans;
    this->kredit = kredit;
    brojStedaci++;
}

Stedac::~Stedac(){
    brojStedaci--;
}

void Stedac::pecatenje() const{
    lice.pecatenje();
    cout<<"Bilans: "<<bilans<<" Kredit: "<<kredit<<endl;
}
