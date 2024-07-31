#include <iostream>
#include <ctime>

using namespace std;

#include "Pantaloni.h"

Pantaloni::Pantaloni(){}

Pantaloni::Pantaloni(char *imeNaArtikl, int golemina, int cena, int denDonesen, int mesecDonesen, int godinaDonesen, int denSlednaNabavka, int mesecSlednaNabavka, int godinaSlednaNabavka):Artikl(imeNaArtikl, golemina, cena, denDonesen, mesecDonesen, godinaDonesen), datumNaSlednaNabavka(denSlednaNabavka, mesecSlednaNabavka, godinaSlednaNabavka){}

void Pantaloni::prikaziPodatociPantaloni() const{
    prikaziPodatociArtikl();
    cout<<"Datum na sledna nabavka:";
    getDatumNaSlednaNabavka().pecatenje();
}

bool Pantaloni::presmetajNabavka(){
    static const int denovi[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t t = time(0);
    tm* momentalenDatum = localtime(&t);
    int momentalnaGodina = momentalenDatum->tm_year + 1900;
    int momentalenMesec = momentalenDatum->tm_mon + 1;
    int momentalenDen = momentalenDatum->tm_mday;
    int denSlednaNabavka = datumNaSlednaNabavka.getDen();
    int mesecSlednaNabavka = datumNaSlednaNabavka.getMesec();
    int godinaSlednaNabavka = datumNaSlednaNabavka.getGodina();
    int slednaNabavka = ((godinaSlednaNabavka * 365) + (denovi[mesecSlednaNabavka] + mesecSlednaNabavka) + denSlednaNabavka) - ((momentalnaGodina * 365) + (denovi[momentalenMesec] + momentalenMesec) + momentalenDen);
    if(slednaNabavka <= 7 && slednaNabavka >= 0)
        return true;
    return false;
}

Datum Pantaloni::getDatumNaSlednaNabavka() const{
    return datumNaSlednaNabavka;
}

Pantaloni Pantaloni::postaviPantaloni(){
    char imeNaArtikl[20];
    int goleminaNaArtikl, cenaNaArtikl, denDonesen, mesecDonesen, godinaDonesen, denSlednaNabavka, mesecSlednaNabavka, godinaSlednaNabavka;
    cout<<"Vnesi ime na artikl:";
    cin>>imeNaArtikl;
    cout<<"Vnesi golemina:";
    cin>>goleminaNaArtikl;
    cout<<"Vnesi cena:";
    cin>>cenaNaArtikl;
    cout<<"Vnesi datum koga e donesen vo prodavnica:";
    cin>>denDonesen>>mesecDonesen>>godinaDonesen;
    cout<<"Vnesi datum na sledna nabavka:";
    cin>>denSlednaNabavka>>mesecSlednaNabavka>>godinaSlednaNabavka;

    return Pantaloni(imeNaArtikl, goleminaNaArtikl, cenaNaArtikl, denDonesen, mesecDonesen, godinaDonesen, denSlednaNabavka, mesecSlednaNabavka, godinaSlednaNabavka);
}
