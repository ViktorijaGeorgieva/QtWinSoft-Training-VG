#include <iostream>
#include <cstring>

using namespace std;

#include "Vraboten.h"

Vraboten::Vraboten(){}

Vraboten::Vraboten(char *ime, char *prezime, int godinaNaVrabotuvanje){
    this->ime = new char[strlen(ime) + 1];
    strcpy(this->ime, ime);
    this->prezime = new char[strlen(prezime) + 1];
    strcpy(this->prezime, prezime);
    this->godinaNaVrabotuvanje = godinaNaVrabotuvanje;
}

Vraboten Vraboten::postaviVraboten(){
    int godinaNaVrabotuvanje;
    char ime[20], prezime[20];

    cout<<"Vnesi ime:";
    cin>>ime;
    cout<<"Vnesi prezime:";
    cin>>prezime;
    cout<<"Vnesi godina na vrabotuvanje:";
    cin>>godinaNaVrabotuvanje;

    return Vraboten(ime, prezime, godinaNaVrabotuvanje);
}

void Vraboten::prikaziPodatociVraboten() const{
    cout<<"Ime:"<<ime<<endl
         <<"Prezime:"<<prezime<<endl
         <<"Godina na vrabotuvanje:"<<godinaNaVrabotuvanje<<endl;
}
