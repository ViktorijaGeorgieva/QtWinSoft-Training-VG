/*Креирај листа од 10000 случајни цели броеви co вредности од 0 до 9999. Потоа прикажи ги следните вредности:
-број на парни елементи
-број на елементи помали од 2000
-број на елементи во интервал [2000, 4000)
-број на елементи во интервал [4000, 6000)
-број на елементи во интервал [6000, 8000)
-број на елементи во интервал [8000, 10000)
-средна вредност на елементите*/
#include <iostream>
#include <cstdlib>
#include <list>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int slucaenBroj();
bool parniElementi(int broj);
bool pomaliOd2000(int broj);
bool interval(int broj);

int odBroj = 2000, doBroj = 4000;
#define SIZE 10000

int main()
{
    list<int> lista(SIZE);
    ostream_iterator<int> output(cout, " ");
    srand(time(0));
    generate(lista.begin(), lista.end(), slucaenBroj);
    copy(lista.begin(), lista.end(), output);
    int vrednost = count_if(lista.begin(), lista.end(), parniElementi);
    cout<<"Broj na parni elementi:"<<vrednost<<endl;
    vrednost = count_if(lista.begin(), lista.end(), pomaliOd2000);
    cout<<"Broj na elementi pomali od 2000:"<<vrednost<<endl;
    vrednost = count_if(lista.begin(), lista.end(), interval);
    cout<<"Broj na elementi vo interval [2000, 4000):"<<vrednost<<endl;
    odBroj += 2000;
    doBroj += 2000;
    vrednost = count_if(lista.begin(), lista.end(), interval);
    cout<<"Broj na elementi vo interval [4000, 6000):"<<vrednost<<endl;
    odBroj += 2000;
    doBroj += 2000;
    vrednost = count_if(lista.begin(), lista.end(), interval);
    cout<<"Broj na elementi vo interval [6000, 8000):"<<vrednost<<endl;
    odBroj += 2000;
    doBroj += 2000;
    vrednost = count_if(lista.begin(), lista.end(), interval);
    cout<<"Broj na elementi vo interval [8000, 10000):"<<vrednost<<endl;
    vrednost = accumulate(lista.begin(), lista.end(), 0);
    double srednaVrednost = (double) vrednost / SIZE;
    cout<<"Sredna vrednost na elementite:"<<srednaVrednost<<endl;

    return 0;
}

int slucaenBroj(){
    return rand() % 10000;
}

bool parniElementi(int broj){
    return broj % 2 == 0;
}

bool pomaliOd2000(int broj){
    return broj < 2000;
}

bool interval(int broj){
    return broj >= odBroj && broj < doBroj;
}
