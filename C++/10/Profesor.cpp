#include <iostream>
#include <cstring>

using namespace std;

#include "Profesor.h"

Profesor::Profesor(){}

Profesor::Profesor(char *ime, char *prezime, int godinaNaVrabotuvanje, char *zvanje, char *oblast, int brojPredmeti):Vraboten(ime, prezime, godinaNaVrabotuvanje){
    this->zvanje = new char[strlen(zvanje) + 1];
    strcpy(this->zvanje, zvanje);
    this->oblast = new char[strlen(oblast) + 1];
    strcpy(this->oblast, oblast);
    this->brojPredmeti = brojPredmeti;
}

Profesor Profesor::postaviProfesor(){
    int godinaNaVrabotuvanje, brojPredmeti;
    char ime[20], prezime[20], zvanje[20], oblast[20];

    cout<<"Vnesi ime:";
    cin>>ime;
    cout<<"Vnesi prezime:";
    cin>>prezime;
    cout<<"Vnesi godina na vrabotuvanje:";
    cin>>godinaNaVrabotuvanje;
    cout<<"Vnesi zvanje:";
    cin>>zvanje;
    cout<<"Vnesi oblast:";
    cin>>oblast;
    cout<<"Vnesi broj na predmeti:";
    cin>>brojPredmeti;

    return Profesor(ime, prezime, godinaNaVrabotuvanje, zvanje, oblast, brojPredmeti);
}

void Profesor::prikaziPodatociProfesor() const{
    prikaziPodatociVraboten();
    cout<<"Zvanje:"<<zvanje<<endl
         <<"Oblast:"<<oblast<<endl
         <<"Broj na predmeti"<<brojPredmeti<<endl;
}
