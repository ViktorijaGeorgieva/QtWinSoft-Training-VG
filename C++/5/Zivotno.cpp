#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "Datum.h"
#include "Zivotno.h"

Zivotno::Zivotno() : datumNaRagjanje(1, 1, 2000), datumNaDonesuvanjeVoZoo(1, 1, 2000), datumNaPoslednaVakcinacija(1, 1, 2000) {}

Zivotno::Zivotno(char *ime, char tip, char pol, int denNaRagjanje, int mesecNaRagjanje, int godinaNaRagjanje, int denNaDonesuvanjeVoZoo, int mesecNaDonesuvanjeVoZoo, int godinaNaDonesuvanjeVoZoo, int denNaPoslednaVakcinacija, int mesecNaPoslednaVakcinacija, int godinaNaPoslednaVakcinacija) : datumNaRagjanje(denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje), datumNaDonesuvanjeVoZoo(denNaDonesuvanjeVoZoo, mesecNaDonesuvanjeVoZoo, godinaNaDonesuvanjeVoZoo), datumNaPoslednaVakcinacija(denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija){
    int len = strlen(ime);
    len = len < 20 ? len : 19;
    strncpy(this->ime, ime, len);
    this->ime[len] = '\0';
    this->tip = (tip == 'c' || tip == 'v' || tip == 'p') ? tip : 'c';
    this->pol = (pol == 'm' || pol == 'z') ? pol : 'm';
}

void Zivotno::prikaziPodatoci() const{
    cout<<ime<<endl;
    cout<<pol<<endl;
    if(tip == 'c')
        cout<<"Cicach"<<endl;
    else if(tip == 'v')
        cout<<"Vlekach"<<endl;
    else
        cout<<"Ptica"<<endl;
    cout<<"Datum na ragjanje: ";
    datumNaRagjanje.pecatenje();
    cout<<"Datum na donesuvanje vo zooloska: ";
    datumNaDonesuvanjeVoZoo.pecatenje();
    cout<<"Datum na posledna vakcinacija: ";
    datumNaPoslednaVakcinacija.pecatenje();
}

int Zivotno::presmetajVakcinacija(){
    static const int denovi[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t t = time(0);
    tm* momentalenDatum = localtime(&t);
    int momentalnaGodina = momentalenDatum->tm_year + 1900;
    int momentalenMesec = momentalenDatum->tm_mon + 1;
    int momentalenDen = momentalenDatum->tm_mday;
    int denNaVakcinacija = datumNaPoslednaVakcinacija.getDen();
    int mesecNaVakcinacija = datumNaPoslednaVakcinacija.getMesec();
    int godinaNaVakcinacija = datumNaPoslednaVakcinacija.getGodina();

    if(tip == 'c'){
        godinaNaVakcinacija += 1;
        int denoviDoVakcinacija = ((godinaNaVakcinacija * 365) + (denovi[mesecNaVakcinacija] + mesecNaVakcinacija) + denNaVakcinacija) - ((momentalnaGodina * 365) + (denovi[momentalenMesec] + momentalenMesec) + momentalenDen);
        if(denoviDoVakcinacija <= 7 && denoviDoVakcinacija >= 0)
            return 1;
    }else if(tip == 'v'){
        if(mesecNaVakcinacija + 8 <= 12)
            mesecNaVakcinacija += 8;
        else{
            godinaNaVakcinacija += 1;
            mesecNaVakcinacija = (mesecNaVakcinacija + 8) % 12;
        }
        int denoviDoVakcinacija = ((godinaNaVakcinacija * 365) + (denovi[mesecNaVakcinacija] + mesecNaVakcinacija) + denNaVakcinacija) - ((momentalnaGodina * 365) + (denovi[momentalenMesec] + momentalenMesec) + momentalenDen);
        if(denoviDoVakcinacija <= 7 && denoviDoVakcinacija >= 0)
            return 1;
    }else if(tip == 'p'){
        if(mesecNaVakcinacija + 6 <= 12)
            mesecNaVakcinacija += 6;
        else{
            godinaNaVakcinacija += 1;
            mesecNaVakcinacija = (mesecNaVakcinacija + 6) % 12;
        }
        int denoviDoVakcinacija = ((godinaNaVakcinacija * 365) + (denovi[mesecNaVakcinacija] + mesecNaVakcinacija) + denNaVakcinacija) - ((momentalnaGodina * 365) + (denovi[momentalenMesec] + momentalenMesec) + momentalenDen);
        if(denoviDoVakcinacija <= 7 && denoviDoVakcinacija >= 0)
            return 1;
    }
    return 0;
}
