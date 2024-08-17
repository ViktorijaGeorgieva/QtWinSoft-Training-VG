#include <iostream>
#include <string>

using namespace std;

#include "Lica.h"

template<class T>
Lica<T>::Lica(){}

template<class T>
Lica<T>::Lica(string imeIPrezime, long long maticenBroj, int vozrast, string adresa, T kod){
    this->imeIPrezime = imeIPrezime;
    this->maticenBroj = maticenBroj;
    this->vozrast = vozrast;
    this->adresa = adresa;
    this->kod = kod;
}

template<class T>
Lica<T> Lica<T>::postavi(){
    string imeIPrezime, adresa;
    long long maticenBroj;
    int vozrast;
    T kod;
    cout<<"Vnesi ime i prezime:";
    cin.ignore();
    getline(cin, imeIPrezime);
    cout<<"Vnesi maticen broj:";
    cin>>maticenBroj;
    cout<<"Vnesi vozrast:";
    cin>>vozrast;
    cout<<"Vnesi adresa:";
    cin.ignore();
    getline(cin, adresa);
    cout<<"Vnesi kod:";
    cin>>kod;

    return Lica(imeIPrezime, maticenBroj, vozrast, adresa, kod);
}

template<class T>
void Lica<T>::pecatenje() const{
    cout<<"Ime i prezime:"<<getImeIPrezime()<<endl
         <<"Maticen broj:"<<getMaticenBroj()<<endl
         <<"Vozrast:"<<getVozrast()<<endl
         <<"Adresa:"<<getAdresa()<<endl
         <<"Kod:"<<getKod()<<endl;
}
