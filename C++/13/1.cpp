/*Во една зоолошка градина се води евиденција за животните кои се чуваат во неа: птици, влекачи и цицачи. Користејќи ги концептите на ООП да се
 * моделираат соодветни класи според спецификациите дадени на слика 1. Цицачите се вакцинираат секоја година, птиците на секои 6 месеци, а за
 * влекачите овој податок варира. Во main() функцијата да се конструира низа од долунаведените класи (влекачи, птици и цицачи) и да се имплементира
 * кориснички посредник преку мени со следните опции:
1.	Додавање на животно во листата
2.	Прикажување на бројна состојба
3.	Прикажување на животни од дадена група
4.	Прикажување на целата листа
5.	Прикажување на сите животни кои треба да се вакцинираат во рок од 1 недела
6.	Излез од менито
*/
#include <iostream>

using namespace std;

#include "Vlekaci.h"
#include "Ptici.h"
#include "Cicaci.h"

int meni();

int main()
{
    int izbor, counterV = 0, counterP = 0, counterC = 0;
    Vlekaci vlekaci[50];
    Ptici ptici[50];
    Cicaci cicaci[50];

    while((izbor = meni()) != 6){
        switch (izbor) {
        case 1:{
            int tipNaZivotno;
            cout<<"1 - Vlekaci"<<endl
                 <<"2 - Ptici"<<endl
                 <<"3 - Cicaci"<<endl;
            cin>>tipNaZivotno;
            if(tipNaZivotno == 1){
                Vlekaci novVlekac = novVlekac.postavi();
                vlekaci[counterV++] = novVlekac;
                break;
            }else if(tipNaZivotno == 2){
                Ptici novaPtica = novaPtica.postavi();
                ptici[counterP++] = novaPtica;
                break;
            }else if(tipNaZivotno == 3){
                Cicaci novCicac = novCicac.postavi();
                cicaci[counterC++] = novCicac;
                break;
            }else
                break;
        }
        case 2:{
            int vkupnoZivotni = counterV + counterP + counterC;
            cout<<"Vkupno zivotni:"<<vkupnoZivotni<<endl;
            break;
        }
        case 3:{
            int tipNaZivotno;
            cout<<"1 - Vlekaci"<<endl
                 <<"2 - Ptici"<<endl
                 <<"3 - Cicaci"<<endl;
            cin>>tipNaZivotno;
            if(tipNaZivotno == 1){
                if(counterV == 0)
                    break;
                for(int i = 0; i < counterV; i++){
                    cout<<"Vlekac "<<i + 1<<":"<<endl;
                    vlekaci[i].prikaziPodatoci();
                }
                break;
            }else if(tipNaZivotno == 2){
                if(counterP == 0)
                    break;
                for(int i = 0; i < counterP; i++){
                    cout<<"Ptica "<<i + 1<<":"<<endl;
                    ptici[i].prikaziPodatoci();
                }
                break;
            }else if(tipNaZivotno == 3){
                if(counterC == 0)
                    break;
                for(int i = 0; i < counterC; i++){
                    cout<<"Cicac "<<i + 1<<":"<<endl;
                    cicaci[i].prikaziPodatoci();
                }
                break;
            }else
                break;
        }
        case 4:{
            if(counterV == 0 && counterP == 0 && counterC == 0)
                break;
            for(int i = 0; i < counterV; i++){
                cout<<"Vlekac "<<i + 1<<":"<<endl;
                vlekaci[i].prikaziPodatoci();
            }
            for(int i = 0; i < counterP; i++){
                cout<<"Ptica "<<i + 1<<":"<<endl;
                ptici[i].prikaziPodatoci();
            }
            for(int i = 0; i < counterC; i++){
                cout<<"Cicac "<<i + 1<<":"<<endl;
                cicaci[i].prikaziPodatoci();
            }
            break;
        }
        case 5:{
            int counter = 0;
            if(counterV == 0 && counterP == 0 && counterC == 0)
                break;
            for(int i = 0; i < counterV; i++){
                if(vlekaci[i].presmetajVakcinacija()){
                    cout<<"Vlekac "<<i + 1<<":"<<endl;
                    vlekaci[i].prikaziPodatoci();
                    counter = 1;
                }
            }
            for(int i = 0; i < counterP; i++){
                if(ptici[i].presmetajVakcinacija()){
                    cout<<"Ptica "<<i + 1<<":"<<endl;
                    ptici[i].prikaziPodatoci();
                    counter = 1;
                }
            }
            for(int i = 0; i < counterC; i++){
                if(cicaci[i].presmetajVakcinacija()){
                    cout<<"Cicac "<<i + 1<<":"<<endl;
                    cicaci[i].prikaziPodatoci();
                    counter = 1;
                }
            }
            if(counter == 0)
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
    cout<<"1 - Dodavanje na zivotno vo listata"<<endl
         <<"2 - Prikazuvanje na brojna sostojba"<<endl
         <<"3 - Prikazuvanje na zivotni od dadena grupa"<<endl
         <<"4 - Prikazuvanje na celata lista"<<endl
         <<"5 - Prikazuvanje na site zivotni sto treba da se vakciniraat vo rok od 1 nedela"<<endl
         <<"6 - Izlez od menito"<<endl;
    cin>>izbor;
    return izbor;
}
