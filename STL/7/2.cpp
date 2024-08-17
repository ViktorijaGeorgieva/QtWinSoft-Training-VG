/*Напиши програма за играње на едноставна игра со карти која ги има следните правила: шпилот од 52 карти се меша и се делат картите на сите играчи
 * подеднакво. Добива оној играч што има најголем збир.
а)Вредностите на картите се од 1 до 14 соодветно, без разлика на бојата, А има вредност 1.
б)Вредностите на картите се од 1 до 14 соодветно, А има вредност 1. Картите срце се бројат двојно.
На почетокот на играта да се внесе бројот на играчи. Во излезот да се прикажат картите и збирот што ги добил секој играч.*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

#include "Karta.h"
#include "Igrac.h"

#define SIZE 52

void delenjeKarti(int brojIgraci, vector<Igrac> &igraci, vector<Karta> karti);

int main()
{
    vector<Karta> spilKarti;
    int brojKarta = 1, counter = 1, max = 0, pobednik = 0, brojIgraci, tipIgra;
    string bojaKarta = "Srce";
    cout<<"Vnesi broj na igraci:";
    cin>>brojIgraci;
    vector<Igrac> igraci(brojIgraci);
    cout<<"Vnesi tip na igra:"<<endl
         <<"1 -Vrednostite na kartite se od 1 do 14 soodvetno, bez razlika  na bojata, A ima vrednost 1."<<endl
         <<"2 - Vrednostite na kartite se od 1 do 14 soodvetno, A ima vrednost 1. Kartite srce se brojat dvojno."<<endl;
    cin>>tipIgra;
    tipIgra = (tipIgra == 1 || tipIgra == 2) ? tipIgra : 1;
    for(int i = 0; i < SIZE; i++){
        spilKarti.push_back(Karta(brojKarta, bojaKarta));
        brojKarta++;
        if(brojKarta == 11)
            brojKarta++;
        if(brojKarta == 15){
            if(counter == 1)
                bojaKarta = "Detelina";
            else if(counter == 2)
                bojaKarta == "Baklava";
            else
                bojaKarta = "List";
            brojKarta = 1;
            counter++;
        }
    }
    ostream_iterator<Karta> output(cout, "\n");
    copy(spilKarti.begin(), spilKarti.end(), output);
    random_shuffle(spilKarti.begin(), spilKarti.end());
    copy(spilKarti.begin(), spilKarti.end(), output);
    delenjeKarti(brojIgraci, igraci, spilKarti);
    for(int i = 0; i < brojIgraci; i++){
        int sum = igraci[i].suma(tipIgra);
        if(sum > max){
            max = sum;
            pobednik = i + 1;
        }
        cout<<"Igrac "<<i + 1<<":"<<endl;
        igraci[i].pecatenje();
        cout<<"Suma:"<<sum<<endl;
    }
    cout<<"Pobednik e Igrac "<<pobednik<<" so suma "<<max<<endl;

    return 0;
}

void delenjeKarti(int brojIgraci, vector<Igrac> &igraci, vector<Karta> karti){
    int brojPodeleniKarti = (SIZE / brojIgraci) * brojIgraci;
    for(int i = 0; i < brojPodeleniKarti; i++){
        igraci[i % brojIgraci].vnesiKarta(karti[i]);
    }
}
