/*Да се направи класа Matrica која работи со дводимензионална низа од цели броеви. Да се преклопат  оператори за влез и екстракција на потоци,
 * индексен оператор, оператор за собирање, одземање и множење (низа со низа, низа со цел број и цел број со низа). Да се преклопат оператори за
 * еднаквост и нееднаквост на низа, копирачки конструктор, конверзиски конструктор. Да се постави кориснички изборник за опции во главната програма.
 * Може да се користат колку сакаме други помошни функции.*/
#include <iostream>

using namespace std;

#include "Matrica.h"

int meni();

int main()
{
    int izbor, counter = 0;
    Matrica matrici[100];
    while((izbor = meni()) != 12){
        switch (izbor) {
        case 1:{
            int redovi, koloni;
            cout<<"Vnesi broj na redovi i koloni:";
            cin>>redovi>>koloni;
            Matrica novaMatrica(redovi, koloni);
            cout<<"Vnesi elementi:";
            cin>>novaMatrica;
            cout<<novaMatrica;
            matrici[counter++] = novaMatrica;
            break;
        }
        case 2:{
            int indeks;
            cout<<"Vnesi indeks na matrica:";
            cin>>indeks;
            if(indeks > counter)
                break;
            else{
                Matrica novaMatrica = matrici[indeks - 1];
                matrici[counter++] = novaMatrica;
            }
            break;
        }
        case 3:{
            if(counter == 0)
                break;
            for(int i = 0; i < counter; i++){
                cout<<matrici[i];
            }
            break;
        }
        case 4:{
            int indeksMatrica1, indeksMatrica2;
            cout<<"Vnesi indeksi na matricite:";
            cin>>indeksMatrica1>>indeksMatrica2;
            if(indeksMatrica1 > counter || indeksMatrica2 > counter)
                break;
            else{
                if(matrici[indeksMatrica1 - 1] == matrici[indeksMatrica2 - 1]){
                    cout<<"Matricite se identicni."<<endl;
                }else{
                    cout<<"Matricite se razlicni."<<endl;
                }
            }
            break;
        }
        case 5:{
            int indeksMatrica, indeksElement;
            cout<<"Vnesi indeks na matrica i indeks na element:";
            cin>>indeksMatrica>>indeksElement;
            if(indeksMatrica > counter)
                break;
            else{
                cout<<matrici[indeksMatrica - 1][indeksElement]<<endl;
            }
            break;
        }
        case 6:{
            int indeksMatrica, indeksElement;
            cout<<"Vnesi indeks na matrica i indeks na element:";
            cin>>indeksMatrica>>indeksElement;
            if(indeksMatrica > counter)
                break;
            else{
                int broj;
                cout<<"Vnesi broj za zamena:";
                cin >> broj;
                matrici[indeksMatrica - 1][indeksElement] = broj;
                cout<<matrici[indeksMatrica - 1];
            }
            break;
        }
        case 7:{
            int indeksMatrica1, indeksMatrica2;
            cout<<"Vnesi indeksi na matricite:";
            cin>>indeksMatrica1>>indeksMatrica2;
            if(indeksMatrica1 > counter || indeksMatrica2 > counter)
                break;
            else
            {
                Matrica tmp = matrici[indeksMatrica1 - 1] + matrici[indeksMatrica2 - 1];
                if(tmp != matrici[indeksMatrica1 - 1])
                {
                    cout<<"Matrica "<<indeksMatrica1<<" + Matrica " << indeksMatrica2<<endl;
                    cout<<tmp;
                }
            }
            break;
        }
        case 8:{
            int indeksMatrica1, indeksMatrica2;
            cout<<"Vnesi indeksi na matricite:";
            cin>>indeksMatrica1>>indeksMatrica2;
            if(indeksMatrica1 > counter || indeksMatrica2 > counter)
                break;
            else
            {
                Matrica tmp = matrici[indeksMatrica1 - 1] - matrici[indeksMatrica2 - 1];
                if(tmp != matrici[indeksMatrica1 - 1])
                {
                    cout<<"Matrica "<<indeksMatrica1<<" - Matrica "<<indeksMatrica2<<endl;
                    cout<<tmp;
                }
            }
            break;
        }
        case 9:{
            int indeksMatrica1, indeksMatrica2;
            cout << "Vnesi indeksi na matricite:";
            cin>>indeksMatrica1>>indeksMatrica2;
            if(indeksMatrica1 > counter || indeksMatrica2 > counter)
                break;
            else
            {
                Matrica tmp = matrici[indeksMatrica1 - 1] * matrici[indeksMatrica2 - 1];
                if(tmp != matrici[indeksMatrica1 - 1])
                {
                    cout<<"Matrica "<<indeksMatrica1 <<" * Matrica "<<indeksMatrica2<<endl;
                    cout<<tmp;
                }
            }
            break;
        }
        case 10:{
            int indeksMatrica, broj;

            cout<<"Vnesi indeks na matrica:";
            cin>>indeksMatrica;
            cout<<"Vnesi broj:";
            cin>>broj;
            if(indeksMatrica > counter)
                break;
            else
            {
                cout<<"Matrica "<<indeksMatrica<<" *  "<<broj<<endl;
                cout<<matrici[indeksMatrica - 1] * broj;
            }
            break;
        }
        case 11:{
            int indeksMatrica, broj;

            cout<<"Vnesi indeks na matrica:";
            cin>>indeksMatrica;
            cout<<"Vnesi broj:";
            cin>>broj;
            if(indeksMatrica > counter)
                break;
            else
            {
                cout<<broj<<" *  "<<"Matrica "<<indeksMatrica<<endl;
                cout<<broj * matrici[indeksMatrica - 1];
            }
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
    cout<<"1 - Kreiraj nova matrica"<<endl
         <<"2 - Kopiraj matrica"<<endl
         <<"3 - Izlistaj matrici"<<endl
         <<"4 - Sporedi matrici"<<endl
         <<"5 - Ispecati element na matrica"<<endl
         <<"6 - Promeni element na matrica"<<endl
         <<"7 - Sobiranje na dve matrici"<<endl
         <<"8 - Odzemanje na dve matrici"<<endl
         <<"9 - Mnozenje na dve matrici"<<endl
         <<"10 - Mnozenje na matrica so broj"<<endl
         <<"11 - Mnozenje na broj so matrica"<<endl
         <<"12 - Kraj"<<endl;
    cin>>izbor;
    return izbor;
}
