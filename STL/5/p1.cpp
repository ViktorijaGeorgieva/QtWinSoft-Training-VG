/*Во едно множество се сместуваат објекти кои се геометриски фигури. Креирај класи Pravoagolnik, Kvadrat и Krug. Креирај class template Mnozestvo<T>
 * во со функции членки за додавање, прикажување на елементи на множеството и определување на најголем елемент во множеството (елемент со најголема
 * површина). Како податочна структура за сместување на елементите на множеството може да се користи поле. Секој елемент може да се појави само
 * еднаш. Креирај три множества: pravoagolnici, kvadrati и krugovi од Pravoagolnik, Kvadrat и Krug, соодветно. Креирај function template за печатење
 * на множество. Програмата треба да имплементира мени со следните опции:
1.Додај правоаголник
2.Додај квадрат
3.Додај круги
4.Прикажи го множеството правоаголници
5.Прикажи го множеството квадрати
6.Прикажи го множеството кругови
7.Прикажи најголеми елементи
8.Прикажи број на елементи во множествата
9.Крај*/
#include <iostream>

#include "Pravoagolnik.h"
#include "Kvadrat.h"
#include "Krug.h"
#include "Mnozestvo.h"

using namespace std;

template<typename T>
void pecatenje(const Mnozestvo<T>& set){
    set.prikazuvanjeElementi();
}

int main() {
    Mnozestvo<Pravoagolnik> pravoagolnici;
    Mnozestvo<Kvadrat> kvadrati;
    Mnozestvo<Krug> krugovi;

    int izbor;
    while(true){
        cout<<"Meni:"<<endl
             <<"1.Dodaj pravoagolnik"<<endl
             <<"2.Dodaj kvadrat"<<endl
             <<"3.Dodaj krug"<<endl
             <<"4.Prikazi go mnozestvoto pravoagolnici"<<endl
             <<"5.Prikazi go mnozestvoto kvadrati"<<endl
             <<"6.Prikazi go mnozestvoto krugovi"<<endl
             <<"7.Prikazi najgolemi elementi"<<endl
             <<"8.Prikazi  broj na elementi vo mnozestvata"<<endl
             <<"9.Kraj"<<endl;
        cout<<"Vnesi izbor: ";
        cin>>izbor;

        switch(izbor){
        case 1: {
            double s, v;
            cout<<"Vnesi sirina i dolzina na pravoagolnik: ";
            cin>>s>>v;
            pravoagolnici.dodadiElement(Pravoagolnik(s, v));
            break;
        }
        case 2: {
            double s;
            cout<<"Vnesi strana na kvadrat: ";
            cin>>s;
            kvadrati.dodadiElement(Kvadrat(s));
            break;
        }
        case 3: {
            double r;
            cout<<"Vnesi radius na krug: ";
            cin>>r;
            krugovi.dodadiElement(Krug(r));
            break;
        }
        case 4: {
            pecatenje(pravoagolnici);
            break;
        }
        case 5: {
            pecatenje(kvadrati);
            break;
        }
        case 6: {
            pecatenje(krugovi);
            break;
        }
        case 7: {
            Pravoagolnik najgolemPravoagolnik = pravoagolnici.najgolem();
            cout<<"Najgolem pravoagolnik: "<<najgolemPravoagolnik.plostina()<<endl;
            Kvadrat najgolemKvadrat = kvadrati.najgolem();
            cout<<"Najgolem kvadrat: "<<najgolemKvadrat.plostina()<<endl;
            Krug najgolemKrug = krugovi.najgolem();
            cout<<"Najgolem krug: "<<najgolemKrug.plostina()<<endl;
            break;
        }
        case 8: {
            cout<<"Broj na pravoagolnici: "<<pravoagolnici.brojElementi()<<endl;
            cout<<"Broj na kvadrati: "<<kvadrati.brojElementi()<<endl;
            cout<<"Broj na krugovi: "<<krugovi.brojElementi()<<endl;
            break;
        }
        case 9:{
            return 0;
        }
        default:
            break;
        }
    }
    return 0;
}
