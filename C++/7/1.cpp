/*Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.

Користи целоборјни променливи за броител и именител кои мора да се приватни. Обезбеди потребен број на контруктори кои нема да дозволат дефинирање на
грешни вредности (со 0 не се дели). По секоја од наредните операции, дропката треба да се зачува во редуцирана форма, т.е дропката 2/4 треба да се
зачува како 1/2. Обезбеди ги следните операторски функции членки:
    а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
    б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
    д) Собирање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
    ѓ) Одземање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
    е) Множење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
    ж) Делење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.

Да се обезбедат и следните функции членки на класата:
    з) Печатење на објектот во форма a/b.
    ѕ) Печатење на објектот во форма на реален број.
*/
#include <iostream>

using namespace std;

#include "Dropki.h"

int main()
{
    Dropki dropka1, dropka2, dropka3;
    int broitel, imenitel, broj;

    cout<<"Vnesi broitel i imenitel za Dropka 1:";
    cin>>broitel>>imenitel;
    dropka1.setVrednostiNaDropka(broitel, imenitel);
    cout<<"Vnesi broitel i imenitel za Dropka 2:";
    cin>>broitel>>imenitel;
    dropka2.setVrednostiNaDropka(broitel, imenitel);
    cout<<"Dropka 1:";
    dropka1.pecatenje();
    cout<<"Dropka 2:";
    dropka2.pecatenje();
    cout<<"Sobiranje na dva objekti od klasa Dropki:";
    dropka3 = dropka1 + dropka2;
    dropka3.pecatenje();
    cout<<"Odzemanje na dva objekti od klasa Dropki:";
    dropka3 = dropka1 - dropka2;
    dropka3.pecatenje();
    cout<<"Mnozenje na dva objekti od klasa Dropki:";
    dropka3 = dropka1 * dropka2;
    dropka3.pecatenje();
    cout<<"Delenje na dva objekti od klasa Dropki:";
    dropka3 = dropka1 / dropka2;
    dropka3.pecatenje();
    cout<<"Vnesi broj:";
    cin>>broj;
    cout<<"Sobiranje na objekt od klasa Dropki so cel broj:";
    dropka3 = dropka1 + broj;
    dropka3.pecatenje();
    cout<<"Odzemanje na objekt od klasa Dropki so cel broj:";
    dropka3 = dropka1 - broj;
    dropka3.pecatenje();
    cout<<"Mnozenje na objekt od klasa Dropki so cel broj:";
    dropka3 = dropka1 * broj;
    dropka3.pecatenje();
    cout<<"Delenje na objekt od klasa Dropki so cel broj:";
    dropka3 = dropka1 / broj;
    dropka3.pecatenje();

    return 0;
}
