#include <iostream>
#include <cstring>

using namespace std;
#include "Artikl.h"

Artikl::Artikl(){}

Artikl::Artikl(char *imeNaArtikl, int golemina, int cena, int den, int mesec, int godina):datumDonesenVoProdavnica(den, mesec, godina){
    this->imeNaArtikl = new char[strlen(imeNaArtikl) + 1];
    strcpy(this->imeNaArtikl, imeNaArtikl);
    this->golemina = golemina;
    this->cena = cena;
}

void Artikl::prikaziPodatociArtikl() const{
    cout<<"Ime na artikl:"<<getImeNaArtikl()<<endl
         <<"Golemina:"<<getGolemina()<<endl
         <<"Cena:"<<getCena()<<endl
         <<"Donesen vo prodavnica:";
    getDatumDonesenVoProdavnica().pecatenje();
}

char* Artikl::getImeNaArtikl() const{
    return imeNaArtikl;
}

int Artikl::getGolemina() const{
    return golemina;
}

int Artikl::getCena() const{
    return cena;
}

Datum Artikl::getDatumDonesenVoProdavnica() const{
    return datumDonesenVoProdavnica;
}

void Artikl::setImeNaArtikl(char *imeNaArtikl){
    this->imeNaArtikl = new char[strlen(imeNaArtikl) + 1];
    strcpy(this->imeNaArtikl, imeNaArtikl);
}

void Artikl::setGolemina(int golemina){
    this->golemina = golemina;
}

void Artikl::setCena(int cena){
    this->cena = cena;
}
