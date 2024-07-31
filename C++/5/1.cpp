/*Во една зоолошка градина се води евиденција за различни типови животни кои се чуваат во неа: птици, влекачи, цицачи.... Користејќи ги концептите
 * на ООП да се моделира класа според спецификациите дадени на слика 5.1. Цицачите се вакцинираат секоја година, птиците на секои 6 месеци, а
 * влекачите на секои 8 месеци. Датумите да се дефинираат во посебна класа Datum со приватни податочни членки den, mesec и godina. Да се имплементира
 * кориснички посредник преку мени со следните опции:
1.	Додавање на животно во зоолошка градина
2.	Прикажување на бројна состојба
3.	Прикажување на животни од дадена група (тип: c- цицачи, v-влекачи, p-птици)
4.	Прикажување на целата листа
5.	Прикажување на сите животни кои треба да се вакцинираат во рок од 1 недела
6.	Излез од менито
*/
#include <iostream>

using namespace std;

#include "Zivotno.h"

int meni();
Zivotno vnesiZivotno();

int main()
{
    int izbor;
    Zivotno zivotni[50];
    int i, counter = 0;

    while((izbor = meni()) != 6){
        switch (izbor) {
        case 1:{
            Zivotno novoZivotno;
            novoZivotno = vnesiZivotno();
            zivotni[counter++] = novoZivotno;
            break;
        }
        case 2:{
            cout<<"Vo zooloskata gradina ima "<<counter<<" zivotni."<<endl;
            break;
        }
        case 3:{
            char tip;
            int flag = 0;
            cout<<"Vnesi tip: "<<endl;
            cin>> tip;
            for(i = 0; i < counter; i++){
                if(zivotni[i].getTip() == tip){
                    flag = 1;
                    zivotni[i].prikaziPodatoci();
                }
            }
            if(flag == 0)
                cout<<"Nema zivotni od ovaa grupa"<<endl;
            break;
        }
        case 4:{
            if(counter == 0)
                cout<<"Nema zivotni vo zooloskata gradina."<<endl;
            else{
                for(i = 0; i < counter; i++){
                    zivotni[i].prikaziPodatoci();
                }
            }
            break;
        }
        case 5:{
            int flag = 0;
            for(i = 0; i < counter; i++){
                if(zivotni[i].presmetajVakcinacija()){
                    flag = 1;
                    zivotni[i].prikaziPodatoci();
                }
            }
            if(flag == 0)
                cout<<"Nema zivotni koi treba da se vakciniraat vo rok od edna nedela."<<endl;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}

int meni(){
    int izbor;
    cout<<"1 - Dodavanje na zivotno vo zooloska gradina"<<endl
         <<"2 - Prikazuvanje na brojna sostojba"<<endl
         <<"3 - Prikazuvanje na zivotni od dadena grupa (tip: c-cicachi, v-vlekachi, p-ptici)"<<endl
         <<"4 - Prikazuvanje na celata lista"<<endl
         <<"5 - Prikazuvanje na site zivotni koi treba da se vakciniraat vo rok od edna nedela"<<endl
         <<"6 - Izlez od menito"<<endl;
    cin>>izbor;
    return izbor;
}

Zivotno vnesiZivotno(){
    char ime[20];
    char tip;
    char pol;
    int denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje;
    int denNaDonesuvanjeVoZoo, mesecNaDonesuvanjeVoZoo, godinaNaDonesuvanjeVoZoo;
    int denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija;

    cout<<"Vnesi ime: ";
    cin.ignore();
    cin.getline(ime, 20);
    cout<<"Vnesi tip: ";
    cin>>tip;
    cout<<"Vnesi pol: ";
    cin>>pol;
    cout<<"Vnesi datum na ragjanje: ";
    cin>>denNaRagjanje>>mesecNaRagjanje>>godinaNaRagjanje;
    cout<<"Vnesi datum na donesuvanje vo zooloska gradina: ";
    cin>>denNaDonesuvanjeVoZoo>>mesecNaDonesuvanjeVoZoo>>godinaNaDonesuvanjeVoZoo;
    cout<<"Vnesi datum na posledna vakcinacija: ";
    cin>>denNaPoslednaVakcinacija>>mesecNaPoslednaVakcinacija>>godinaNaPoslednaVakcinacija;
    Zivotno novoZivotno(ime, tip, pol, denNaRagjanje, mesecNaRagjanje, godinaNaRagjanje, denNaDonesuvanjeVoZoo, mesecNaDonesuvanjeVoZoo, godinaNaDonesuvanjeVoZoo, denNaPoslednaVakcinacija, mesecNaPoslednaVakcinacija, godinaNaPoslednaVakcinacija);
    return novoZivotno;
}
