#include <iostream>
#include <cstring>

using namespace std;

#include "Demonstrator.h"

Demonstrator::Demonstrator(){}

Demonstrator::Demonstrator(char *ime, char *prezime, int godinaNaVrabotuvanje, char *rabotnoVremeOd, char *rabotnoVremeDo):Vraboten(ime, prezime, godinaNaVrabotuvanje){
    this->rabotnoVremeOd = new char[strlen(rabotnoVremeOd) + 1];
    strcpy(this->rabotnoVremeOd, rabotnoVremeOd);
    this->rabotnoVremeDo = new char[strlen(rabotnoVremeDo) + 1];
    strcpy(this->rabotnoVremeDo, rabotnoVremeDo);
}

Demonstrator Demonstrator::postaviDemonstrator(){
    int godinaNaVrabotuvanje;
    char ime[20], prezime[20], rabotnoVremeOd[20], rabotnoVremeDo[20];

    cout<<"Vnesi ime:";
    cin>>ime;
    cout<<"Vnesi prezime:";
    cin>>prezime;
    cout<<"Vnesi godina na vrabotuvanje:";
    cin>>godinaNaVrabotuvanje;
    cout<<"Vnesi rabotno vreme od:";
    cin>>rabotnoVremeOd;
    cout<<"Vnesi rabotno vreme do:";
    cin>>rabotnoVremeDo;

    return Demonstrator(ime, prezime, godinaNaVrabotuvanje, rabotnoVremeOd, rabotnoVremeDo);
}

void Demonstrator::prikaziPodatociDemonstrator() const{
    prikaziPodatociVraboten();
    cout<<"Rabotno vreme:"<<rabotnoVremeOd<<"-"<<rabotnoVremeDo<<endl;
}
