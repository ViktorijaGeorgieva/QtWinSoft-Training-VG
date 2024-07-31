#include <iostream>
#include <ctime>

using namespace std;

#include "Kosuli.h"

Kosuli::Kosuli(){}

Kosuli::Kosuli(char *imeNaArtikl, int golemina, int cena, int denDonesen, int mesecDonesen, int godinaDonesen):Artikl(imeNaArtikl, golemina, cena, denDonesen, mesecDonesen, godinaDonesen){}

void Kosuli::prikaziPodatociKosuli() const{
    prikaziPodatociArtikl();
}

bool Kosuli::presmetajNabavka(){}

Kosuli Kosuli::postaviKosuli(){
    char imeNaArtikl[20];
    int goleminaNaArtikl, cenaNaArtikl, denDonesen, mesecDonesen, godinaDonesen;

    cout<<"Vnesi ime na artikl:";
    cin>>imeNaArtikl;
    cout<<"Vnesi golemina:";
    cin>>goleminaNaArtikl;
    cout<<"Vnesi cena:";
    cin>>cenaNaArtikl;
    cout<<"Vnesi datum koga e donesen vo prodavnica:";
    cin>>denDonesen>>mesecDonesen>>godinaDonesen;

    return Kosuli(imeNaArtikl, goleminaNaArtikl, cenaNaArtikl, denDonesen, mesecDonesen, godinaDonesen);
}
