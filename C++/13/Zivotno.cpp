#include <iostream>
#include <cstring>

using namespace std;

#include "Zivotno.h"

Zivotno::Zivotno():datumNaRagjanje(1, 1, 2000), datumNaDonesuvanjeVoZooloska(1, 1, 2000), datumNaPoslednaVakcinacija(1, 1, 2000){}

Zivotno::Zivotno(char * ime, char pol, int denNaRagjanje, int mesecNaRagjanje, int godinaNaRagjanje, int denNaDonesuvanje, int mesecNaDonesuvanje, int godinaNaDonesuvanje, int denNaPoslednaVakcinacija, int mesecNaPoslednaVakcinacija, int godinaNaPoslednaVakcinacija):datumNaRagjanje(denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje), datumNaDonesuvanjeVoZooloska(denNaDonesuvanje, mesecNaDonesuvanje, godinaNaDonesuvanje), datumNaPoslednaVakcinacija(denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija){
    this->ime = new char[strlen(ime) + 1];
    strcpy(this->ime, ime);
    this->pol = (pol == 'm' || pol == 'z') ? pol : 'm';
}

void Zivotno::prikaziPodatociZivotno() const{
    cout<<"Ime na zivotno:"<<getIme()<<endl
         <<"Pol:"<<getPol()<<endl
         <<"Datum na ragjanje:";
    getDatumNaRagjanje().pecatenje();
    cout<<"Datum na donesuvanje vo zooloska:";
    getDatumNaDonesuvanjeVoZooloska().pecatenje();
    cout<<"Datum na posledna vakcinacija:";
    getDatumNaPoslednaVakcinacija().pecatenje();
}

char* Zivotno::getIme() const{
    return ime;
}

char Zivotno::getPol() const{
    return pol;
}

Datum Zivotno::getDatumNaRagjanje() const{
    return datumNaRagjanje;
}

Datum Zivotno::getDatumNaDonesuvanjeVoZooloska() const{
    return datumNaDonesuvanjeVoZooloska;
}

Datum Zivotno::getDatumNaPoslednaVakcinacija() const{
    return datumNaPoslednaVakcinacija;
}
