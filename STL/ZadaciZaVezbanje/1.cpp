/*Креирај класа Pravoagolnik која содржи double sirina и double dolzina, и класа Kvadrat која содржи double strana. Во две текстуални датотеки се
 * сместени линии со чија содржина може да биде:
-број 1 по кој следат два double броја
-број 2 по кој следи еден double број.
Овие вредности треба да се вчитаат во програма и од нив да се создадат објекти. Ако првата вредност е 1 тогаш се создава Pravoagolnik чии димензии се
двата броја што следуваат. Ако првата вредност е 2 тогаш се создава Kvadrat чија страна е бројот што следува.
На пример,
1 2.5 3.5
2 10.0
1 5 5
ќе значи дека ќе се создадат два правоаголника и еден квадрат.
Ако линија содржи вредности различни од пропишаните, програмата да генерира исклучок.
Определи ја унијата и пресекот на сите правоаголници и унијата и пресекот на сите квадрати што се дефинирани со датотеките.
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <exception>
#include <fstream>
#include <vector>

using namespace std;

#include "Pravoagolnik.h"
#include "Kvadrat.h"

int main()
{
    int tip;
    double sirinaPravoagolnik, dolzinaPravoagolnik, stranaKvadrat;
    vector<Pravoagolnik> pravoagolnici1;
    vector<Pravoagolnik> pravoagolnici2;
    vector<Kvadrat> kvadrati1;
    vector<Kvadrat> kvadrati2;
    vector<Pravoagolnik> pravoagolniciUnija;
    vector<Pravoagolnik> pravoagolniciPresek;
    vector<Kvadrat> kvadratiUnija;
    vector<Kvadrat> kvadratiPresek;

    ostream_iterator<Pravoagolnik> outputP(cout, "\n");
    ostream_iterator<Kvadrat> outputK(cout, "\n");
    ifstream readDatoteka1("datoteka1.txt", ios::in);
    if(!readDatoteka1)
        throw logic_error("Ne e pronajdena datotekata.");
    try{
        while (readDatoteka1 >> tip) {
            if(tip == 1){
                readDatoteka1>>sirinaPravoagolnik>>dolzinaPravoagolnik;
                pravoagolnici1.push_back(Pravoagolnik(sirinaPravoagolnik, dolzinaPravoagolnik));
            }else if(tip == 2){
                readDatoteka1>>stranaKvadrat;
                kvadrati1.push_back(Kvadrat(stranaKvadrat));
            }else
                throw 0;
        }
    }catch(int){
        readDatoteka1.close();
    }
    cout<<"Pravoagolnici od datoteka1:"<<endl
         <<"Sirina"<<setw(10)<<"Dolzina"<<endl;
    copy(pravoagolnici1.begin(), pravoagolnici1.end(), outputP);
    cout<<"Kvadrati od datoteka1:"<<endl;
    copy(kvadrati1.begin(), kvadrati1.end(), outputK);
    readDatoteka1.close();
    ifstream readDatoteka2("datoteka2.txt", ios::in);
    if(!readDatoteka2)
        throw logic_error("Ne e pronajdena datotekata.");
    try{
        while(readDatoteka2 >> tip){
            if(tip == 1){
                readDatoteka2>>sirinaPravoagolnik>>dolzinaPravoagolnik;
                pravoagolnici2.push_back(Pravoagolnik(sirinaPravoagolnik, dolzinaPravoagolnik));
            }else if(tip == 2){
                readDatoteka2>>stranaKvadrat;
                kvadrati2.push_back(Kvadrat(stranaKvadrat));
            }else
                throw 0;
        }
    }catch(int){
        readDatoteka2.close();
    }
    cout<<"Pravoagolnici od datoteka2:"<<endl;
    cout<<"Sirina"<<setw(10)<<"Dolzina"<<endl;
    copy(pravoagolnici2.begin(), pravoagolnici2.end(), outputP);
    cout<<"Kvadrati od datoteka2:"<<endl;
    copy(kvadrati2.begin(), kvadrati2.end(), outputK);
    readDatoteka2.close();
    sort(pravoagolnici1.begin(), pravoagolnici1.end());
    sort(kvadrati1.begin(), kvadrati1.end());
    sort(pravoagolnici2.begin(), pravoagolnici2.end());
    sort(kvadrati2.begin(), kvadrati2.end());
    set_union(pravoagolnici1.begin(), pravoagolnici1.end(), pravoagolnici2.begin(), pravoagolnici2.end(), back_inserter(pravoagolniciUnija));
    cout<<"Unija na pravoagolnicite:"<<endl;
    cout<<"Sirina"<<setw(10)<<"Dolzina"<<endl;
    copy(pravoagolniciUnija.begin(), pravoagolniciUnija.end(), outputP);
    set_intersection(pravoagolnici1.begin(), pravoagolnici1.end(), pravoagolnici2.begin(), pravoagolnici2.end(), back_inserter(pravoagolniciPresek));
    cout<<"Presek na pravoagolnicite:"<<endl;
    cout<<"Sirina"<<setw(10)<<"Dolzina"<<endl;
    copy(pravoagolniciPresek.begin(), pravoagolniciPresek.end(), outputP);
    set_union(kvadrati1.begin(), kvadrati1.end(), kvadrati2.begin(), kvadrati2.end(), back_inserter(kvadratiUnija));
    cout<<"Unija na kvadratite:"<<endl;
    copy(kvadratiUnija.begin(), kvadratiUnija.end(), outputK);
    set_intersection(kvadrati1.begin(), kvadrati1.end(), kvadrati2.begin(), kvadrati2.end(), back_inserter(kvadratiPresek));
    cout<<"Presek na kvadratite:"<<endl;
    copy(kvadratiPresek.begin(), kvadratiPresek.end(), outputK);

    return 0;
}
