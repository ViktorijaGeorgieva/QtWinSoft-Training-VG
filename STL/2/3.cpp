/*Една фирма води евиденција за лица кои можат да бидат вработени или клиенти. За секое лице се чуваат следните податоци:  imeiprezime, mat_br,
 * vozrast, adresa, kod. За вработените kod има целобројна вредност, а за клиентите е низа од знаци.
Креирај class template Lica во која ќе се сместуваат податоците за лица. Податоците кои се низи од знаци да се внесуваат преку динамичка алокација на
меморија. Креирај две полиња од објекти, Vraboteni и Klienti. За печатење на двете полиња употреби ја pecatiPole од претходната задача.

Напиши тест програма која содржи мени:

1.Внесување на податоци за вработен

2.Внесување на податоци за клиент

3.Печетење на листа на вработени

4.Печатење на листа на клиенти

5.Крај*/
#include <iostream>

using namespace std;

#include "Lica.h"
#include "Lica.cpp"

int meni();

template<class T>
void pecatiPole(T* arr, int n){
    for(int i = 0; i < n; i++){
        arr[i].pecatenje();
        cout<<endl;
    }
}

int main()
{
    int izbor, counterV = 0, counterK = 0;
    Lica<int> vraboteni[50];
    Lica<string> klienti[50];

    while((izbor = meni()) != 5){
        switch (izbor) {
        case 1:{
            Lica<int> novVraboten;
            vraboteni[counterV++] = novVraboten.postavi();
            break;
        }
        case 2:{
            Lica<string> novKlient;
            klienti[counterK++] = novKlient.postavi();
            break;
        }
        case 3:{
            pecatiPole(vraboteni, counterV);
            break;
        }
        case 4:{
            pecatiPole(klienti, counterK);
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
    cout<<"1 - Vnesuvanje na podatoci za vraboten"<<endl
         <<"2 - Vnesuvanje na podatoci za klient"<<endl
         <<"3 - Pecatenje na lista na vraboteni"<<endl
         <<"4 - Pecatenje na lista na klienti"<<endl
         <<"5 - Kraj"<<endl;
    cin>>izbor;

    return izbor;
}
