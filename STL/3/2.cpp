/*Креирај class template Mnozestvo<T> во со функции членки за додавање, прикажување на елементи на множеството и определување на најголем елемент во
 * множеството. Како податочна структура за сместување на елементите на множеството може да се користи поле. Секој елемент може да се појави само
 * еднаш. Секое множество содржи static компонента во која е сместен бројот на елементи на множеството. Креирај три множества: А од int, B од double
 * и C од char*. Користи соодветна специјализација за коректно определување на најголем елемент во множеството од стрингови. Програмата треба да
 * имплементира мени со следните опции:
1.Додај елемент во А
2.Додај елемент во B
3.Додај елемент во C
4.Прикажи го А
5.Прикажи го B
6.Прикажи го C
7.Прикажи најголеми елементи
8.Прикажи број на елементи во множествата
9.Крај*/
#include <iostream>
#include <string>

using namespace std;

#include "Mnozestvo.h"
#include "Mnozestvo.cpp"

int meni();

template<>
string Mnozestvo<string>::najgolemElement(){
    if(n == 0)
        return "Mnozestvoto e prazno";
    string najgolem = arr[0];
    for(int i = 1; i < n; i++){
        if(najgolem.length() < arr[i].length())
            najgolem = arr[i];
    }
    return najgolem;
}

int main()
{
    int izbor;
    Mnozestvo<int> A;
    Mnozestvo<double> B;
    Mnozestvo<string> C;

    while((izbor = meni()) != 9){
        switch (izbor) {
        case 1:{
            int vrednost;
            cout<<"Vnesi element vo A:";
            cin>>vrednost;
            A.dodadiElement(vrednost);
            break;
        }
        case 2:{
            double vrednost;
            cout<<"Vnesi element vo B:";
            cin>>vrednost;
            B.dodadiElement(vrednost);
            break;
        }
        case 3:{
            string vrednost;
            cout<<"Vnesi element vo C:";
            cin.ignore();
            getline(cin, vrednost);
            C.dodadiElement(vrednost);
            break;
        }
        case 4:{
            cout<<"Elementi na A:";
            A.pecatenje();
            break;
        }
        case 5:{
            cout<<"Elementi na B:";
            B.pecatenje();
            break;
        }
        case 6:{
            cout<<"Elementi na C:";
            C.pecatenje();
            break;
        }
        case 7:{
            cout<<"Najgolem element na A e "<<A.najgolemElement()<<endl;
            cout<<"Najgolem element na B e "<<B.najgolemElement()<<endl;
            cout<<"Najgolem element na C e "<<C.najgolemElement()<<endl;
            break;
        }
        case 8:{
            cout<<"A ima "<<A.getN()<<" elementi."<<endl;
            cout<<"B ima "<<B.getN()<<" elementi."<<endl;
            cout<<"C ima "<<C.getN()<<" elementi."<<endl;
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
    cout<<"1 - Dodaj element vo A"<<endl
         <<"2 - Dodaj element vo B"<<endl
         <<"3 - Dodaj element vo C"<<endl
         <<"4 - Prikazi go A"<<endl
         <<"5 - Prikazi go B"<<endl
         <<"6 - Prikazi go C"<<endl
         <<"7 - Prikazi najgolemi elementi"<<endl
         <<"8 -Prikazi broj na elementi vo mnozestvata"<<endl
         <<"9 - Kraj"<<endl;
    cin>>izbor;
    return izbor;
}
