/*Да се направи проект кој ќе покрива што е можно повеќе облици, дводимензионални и тродимензионални. Хиерархијата треба да има основна класа Oblik
 * од која се изведуваат класите DvoDomenzionalni и TroDimenzionalni. Секоја од овие две класи треба да се подели на што е можно повеќе облици. Да се
 * даде можност за внесување на објект, како и негово директно креирање од главната програма. Да се прикажат испечатувања на различни објекти. Да има
 * во секоја класа вградено бројач за објектите инстанцирани од класата.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cilindar.h"
#include "Kocka.h"
#include "Krug.h"
#include "Kvadrat.h"
#include "Pravoagolnik.h"
#include "Prsten.h"
#include "Sfera.h"
#include "Triagolnik.h"

using namespace std;

int main()
{
    int counter = 0;
    Oblik** oblici = new Oblik*[50];

    srand(time(nullptr));
    for(int i = 0; i < 50; i++){
        int random = rand() % 10;
        switch (random) {
        case 1:
            oblici[counter++] = new Cilindar("Cilindar");
            break;
        case 2:
            oblici[counter++] = new Kocka("Kocka");
            break;
        case 3:
            oblici[counter++] = new Krug("Krug");
            break;
        case 4:
            oblici[counter++] = new Kvadrat("Kvadrat");
            break;
        case 5:
            oblici[counter++] = new Pravoagolnik("Pravoagolnik");
            break;
        case 6:
            oblici[counter++] = new Prsten("Prsten");
            break;
        case 7:
            oblici[counter++] = new Sfera("Sfera");
            break;
        case 8:
            oblici[counter++] = new Triagolnik("Triagolnik");
            break;
        default:
            break;
        }
    }
    for(int i = 0; i < counter; i++)
        oblici[i]->pecatenje();
    cout<<"Broj na oblici:"<<Oblik::getBr()<<endl;
    cout<<"Broj na dvodimenzionalni oblici:"<<DvoDimenzionalni::getBr()<<endl;
    cout<<"Broj na trodimenzionalni oblici:"<<TroDimenzionalni::getBr()<<endl;
    cout<<"Broj na cilindri:"<<Cilindar::getBr()<<endl;
    cout<<"Broj na kocki:"<<Kocka::getBr()<<endl;
    cout<<"Broj na krugovi:"<<Krug::getBr()<<endl;
    cout<<"Broj na kvadrati:"<<Kvadrat::getBr()<<endl;
    cout<<"Broj na pravoagolnici:"<<Pravoagolnik::getBr()<<endl;
    cout<<"Broj na prsteni:"<<Prsten::getBr()<<endl;
    cout<<"Broj na sferi:"<<Sfera::getBr()<<endl;
    cout<<"Broj na triagolnici:"<<Triagolnik::getBr()<<endl;
    for(int i = 0; i < counter; i++)
        delete oblici[i];
    delete[] oblici;

    return 0;
}
