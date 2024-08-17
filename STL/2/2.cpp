/*Креирај класа Kvadrat со податоци strana и класа Pravoagolnik со податоци sirina и dolzina.  Напиши function template sortirajPole со кој се врши
 * сортирање на поле и function template pecatiPole со кој се врши печатење на поле. Во main креирај две полиња од квадрати и праваголници, прикажи
 * ги со pecatiPole, сортирај ги според плоштина со sortirajPole и повторно отпечати ги. */
#include <iostream>

using namespace std;

#include "Kvadrat.h"
#include "Pravoagolnik.h"

template<class T>
void sortirajPole(T* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i].getPlostina() > arr[j].getPlostina()){
                T tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

template<class T>
void pecatiPole(T* arr, int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i].getPlostina()<<" ";
    }
    cout<<endl;
}

int main()
{
    int brNaKvadrati, brNaPravoagolnici;
    cout<<"Vnesi broj na kvadrati i pravoagolnici:";
    cin>>brNaKvadrati>>brNaPravoagolnici;
    Kvadrat kvadrati[brNaKvadrati];
    Pravoagolnik pravoagolnici[brNaPravoagolnici];
    for(int i = 0; i < brNaKvadrati; i++){
        Kvadrat novKvadrat;
        kvadrati[i] = novKvadrat.postavi();
    }
    for(int i = 0; i < brNaPravoagolnici; i++){
        Pravoagolnik novPravoagolnik;
        pravoagolnici[i] = novPravoagolnik.postavi();
    }
    cout<<"Kvadrati:"<<endl;
    pecatiPole(kvadrati, brNaKvadrati);
    sortirajPole(kvadrati, brNaKvadrati);
    cout<<"Sortirani spored plostina:"<<endl;
    pecatiPole(kvadrati, brNaKvadrati);
    cout<<"Pravoagolnici:"<<endl;
    pecatiPole(pravoagolnici, brNaPravoagolnici);
    sortirajPole(pravoagolnici, brNaPravoagolnici);
    cout<<"Sortirani spored plostina:"<<endl;
    pecatiPole(pravoagolnici, brNaPravoagolnici);

    return 0;
}
