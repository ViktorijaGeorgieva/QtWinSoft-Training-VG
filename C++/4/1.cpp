/*Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.

Користи целоборјни променливи за броител и именител кои мора да се приватни. Обезбеди потребен број на контруктори кои нема да дозволат дефинирање
на грешни вредности (со 0 не се дели!). По секоја од наредните операции, дропката треба да се зачува во редуцирана форма, т.е дропката 2/4 треба да
се зачува како 1/2. Обезбеди ги следните јавни функции членки:
    а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
    б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    д) Печатење на објектот во форма a/b.
    ѓ) Печатење на објектот во форма на реален број.
*/
#include <iostream>

using namespace std;

#include "Dropki.h"

int main()
{
    Dropki dropka1, dropka2;
    int broitel, imenitel;

    cout<<"Vnesi broitel i imenitel za prvata dropka: ";
    cin>>broitel>>imenitel;
    dropka1.setVrednostiNaDropka(broitel, imenitel);
    cout<<"Vnesi broitel i imenitel za vtorata dropka: ";
    cin>>broitel>>imenitel;
    dropka2.setVrednostiNaDropka(broitel, imenitel);
    dropka1.sobiranje(dropka2);
    dropka1.odzemanje(dropka2);
    dropka1.mnozenje(dropka2);
    dropka1.delenje(dropka2);
    cout<<"Prva dropka: ";
    dropka1.pecatenje();
    cout<<"Vtora dropka: ";
    dropka2.pecatenje();

    return 0;
}
