#include <iostream>
#include <cstring>

using namespace std;

#include "Asistent.h"

Asistent::Asistent(){}

Asistent::Asistent(char *ime, char *prezime, int godinaNaVrabotuvanje, char *zvanje, char *mentor, int brojPredmeti):Vraboten(ime, prezime, godinaNaVrabotuvanje){
    this->zvanje = new char[strlen(zvanje) + 1];
    strcpy(this->zvanje, zvanje);
    this->mentor = new char[strlen(mentor) + 1];
    strcpy(this->mentor, mentor);
    this->brojPredmeti = brojPredmeti;
}

Asistent Asistent::postaviAsistent(){
    int godinaNaVrabotuvanje, brojPredmeti;
    char ime[20], prezime[20], zvanje[20], mentor[20];

    cout<<"Vnesi ime:";
    cin>>ime;
    cout<<"Vnesi prezime:";
    cin>>prezime;
    cout<<"Vnesi godina na vrabotuvanje:";
    cin>>godinaNaVrabotuvanje;
    cout<<"Vnesi zvanje:";
    cin>>zvanje;
    cout<<"Vnesi mentor:";
    cin>>mentor;
    cout<<"Vnesi broj na predmeti:";
    cin>>brojPredmeti;

    return Asistent(ime, prezime, godinaNaVrabotuvanje, zvanje, mentor, brojPredmeti);
}

void Asistent::prikaziPodatociAsistent() const{
    prikaziPodatociVraboten();
    cout<<"Zvanje:"<<zvanje<<endl
         <<"Mentor:"<<mentor<<endl
         <<"Broj na predmeti:"<<brojPredmeti<<endl;
}
