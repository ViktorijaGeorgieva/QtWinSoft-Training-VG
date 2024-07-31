#include <iostream>
#include <ctime>

using namespace std;

#include "Ptici.h"

Ptici::Ptici(){}

Ptici::Ptici(char *ime, char pol, char letac, int denNaRagjanje, int mesecNaRagjanje, int godinaNaRagjanje, int denNaDonesuvanje, int mesecNaDonesuvanje, int godinaNaDonesuvanje, int denNaPoslednaVakcinacija, int mesecNaPoslednaVakcinacija, int godinaNaPoslednaVakcinacija):Zivotno(ime, pol, denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje, denNaDonesuvanje, mesecNaDonesuvanje, godinaNaDonesuvanje, denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija){
    this->letac = (letac == 'd' || letac == 'n') ? letac : 'n';
}

void Ptici::prikaziPodatoci() const{
    prikaziPodatociZivotno();
    cout<<"Letac:"<<getLetac()<<endl;
}
bool Ptici::presmetajVakcinacija(){
    static const int denovi[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t t = time(0);
    tm* momentalenDatum = localtime(&t);
    int momentalnaGodina = momentalenDatum->tm_year + 1900;
    int momentalenMesec = momentalenDatum->tm_mon + 1;
    int momentalenDen = momentalenDatum->tm_mday;
    int denNaSlednaVakcinacija = getDatumNaPoslednaVakcinacija().getDen();
    int mesecNaSlednaVakcinacija = getDatumNaPoslednaVakcinacija().getMesec();
    int godinaNaSlednaVakcinacija = getDatumNaPoslednaVakcinacija().getGodina();
    if(mesecNaSlednaVakcinacija + 6 <= 12)
        mesecNaSlednaVakcinacija += 6;
    else{
        godinaNaSlednaVakcinacija += 1;
        mesecNaSlednaVakcinacija = (mesecNaSlednaVakcinacija + 6) % 12;
    }
    int denoviDoVakcinacija = ((godinaNaSlednaVakcinacija * 365) + (denovi[mesecNaSlednaVakcinacija] + mesecNaSlednaVakcinacija) + denNaSlednaVakcinacija) - ((momentalnaGodina * 365) + (denovi[momentalenMesec] + momentalenMesec) + momentalenDen);
    if(denoviDoVakcinacija <= 7)
        return true;
    return false;
}

Ptici Ptici::postavi(){
    char ime[20], pol, letac;
    int denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje, denNaDonesuvanje, mesecNaDonesuvanje, godinaNaDonesuvanje, denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija;

    cout<<"Vnesi ime na zivotno:";
    cin.ignore();
    cin.getline(ime, 20);
    cout<<"Vnesi pol:";
    cin>>pol;
    cout<<"Vnesi dali e letac:";
    cin>>letac;
    cout<<"Vnesi datum na ragjanje:";
    cin>>denNaRagjanje>>mesecNaRagjanje>>godinaNaRagjanje;
    cout<<"Vnesi datum na donesuvanje vo zooloska:";
    cin>>denNaDonesuvanje>>mesecNaDonesuvanje>>godinaNaDonesuvanje;
    cout<<"Vnesi datum na posledna vakcinacija:";
    cin>>denNaPoslednaVakcinacija>>mesecNaPoslednaVakcinacija>>godinaNaPoslednaVakcinacija;

    return Ptici(ime, pol, letac, denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje, denNaDonesuvanje, mesecNaDonesuvanje, godinaNaDonesuvanje, denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija);
}

char Ptici::getLetac() const{
    return letac;
}
