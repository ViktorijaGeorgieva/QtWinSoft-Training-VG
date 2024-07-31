#include <iostream>
#include <ctime>

using namespace std;

#include "Vlekaci.h"

Vlekaci::Vlekaci():datumNaSlednaVakcinacija(1, 1, 2000){}

Vlekaci::Vlekaci(char * ime, char pol, int denNaRagjanje, int mesecNaRagjanje, int godinaNaRagjanje, int denNaDonesuvanje, int mesecNaDonesuvanje, int godinaNaDonesuvanje, int denNaPoslednaVakcinacija, int mesecNaPoslednaVakcinacija, int godinaNaPoslednaVakcinacija, int denNaSlednaVakcinacija, int mesecNaSlednaVakcinacija, int godinaNaSlednaVakcinacija):Zivotno(ime, pol, denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje, denNaDonesuvanje, mesecNaDonesuvanje, godinaNaDonesuvanje, denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija), datumNaSlednaVakcinacija(denNaSlednaVakcinacija, mesecNaSlednaVakcinacija, godinaNaSlednaVakcinacija){}

void Vlekaci::prikaziPodatoci() const{
    prikaziPodatociZivotno();
    cout<<"Datum na sledna vakcinacija:";
    getDatumNaSlednaVakcinacija().pecatenje();
}

bool Vlekaci::presmetajVakcinacija(){
    static const int denovi[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t t = time(0);
    tm* momentalenDatum = localtime(&t);
    int momentalnaGodina = momentalenDatum->tm_year + 1900;
    int momentalenMesec = momentalenDatum->tm_mon + 1;
    int momentalenDen = momentalenDatum->tm_mday;
    int denNaSlednaVakcinacija = getDatumNaSlednaVakcinacija().getDen();
    int mesecNaSlednaVakcinacija = getDatumNaSlednaVakcinacija().getMesec();
    int godinaNaSlednaVakcinacija = getDatumNaSlednaVakcinacija().getGodina();
    int denoviDoVakcinacija = ((godinaNaSlednaVakcinacija * 365) + (denovi[mesecNaSlednaVakcinacija] + mesecNaSlednaVakcinacija) + denNaSlednaVakcinacija) - ((momentalnaGodina * 365) + (denovi[momentalenMesec] + momentalenMesec) + momentalenDen);
    if(denoviDoVakcinacija <= 7 && denoviDoVakcinacija >= 0)
        return true;
    return false;
}

Datum Vlekaci::getDatumNaSlednaVakcinacija() const{
    return datumNaSlednaVakcinacija;
}

Vlekaci Vlekaci::postavi(){
    char ime[20], pol;
    int denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje, denNaDonesuvanje, mesecNaDonesuvanje, godinaNaDonesuvanje, denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija, denNaSlednaVakcinacija, mesecNaSlednaVakcinacija, godinaNaSlednaVakcinacija;
    cout<<"Vnesi ime na zivotno:";
    cin.ignore();
    cin.getline(ime, 20);
    cout<<"Vnesi pol:";
    cin>>pol;
    cout<<"Vnesi datum na ragjanje:";
    cin>>denNaRagjanje>>mesecNaRagjanje>>godinaNaRagjanje;
    cout<<"Vnesi datum na donesuvanje vo zooloska:";
    cin>>denNaDonesuvanje>>mesecNaDonesuvanje>>godinaNaDonesuvanje;
    cout<<"Vnesi datum na posledna vakcinacija:";
    cin>>denNaPoslednaVakcinacija>>mesecNaPoslednaVakcinacija>>godinaNaPoslednaVakcinacija;
    cout<<"Vnesi datum na sledna vakcinacija:";
    cin>>denNaSlednaVakcinacija>>mesecNaSlednaVakcinacija>>godinaNaSlednaVakcinacija;

    return Vlekaci(ime, pol, denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje, denNaDonesuvanje, mesecNaDonesuvanje, godinaNaDonesuvanje, denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija, denNaSlednaVakcinacija, mesecNaSlednaVakcinacija, godinaNaSlednaVakcinacija);
}
