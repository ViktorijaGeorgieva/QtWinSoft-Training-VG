/*Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на слика 1, а потоа во функцијата main() да се
 * констуира низа со објекти од долунаведените класи (професор, асистент, демонстратор) и имплементира кориснички посредник преку мени со следните
 * опции:

1.Додавање на нов вработен во листата
2.Прикажување на листата
3.Крај
*/
#include <iostream>

using namespace std;

#include "Profesor.h"
#include "Asistent.h"
#include "Demonstrator.h"

int meni();

int main()
{
    int izbor, counterP = 0, counterA = 0, counterD = 0;
    Profesor profesori[100];
    Asistent asistenti[100];
    Demonstrator demonstratori[100];

    while ((izbor = meni()) != 3) {
        switch (izbor) {
        case 1:{
            int tipNaVraboten;
            cout<<"1 - Profesor"<<endl
                 <<"2 - Asistent"<<endl
                 <<"3 - Demonstrator"<<endl;
            cin>>tipNaVraboten;
            if(tipNaVraboten == 1){
                Profesor novProfesor = novProfesor.postaviProfesor();
                profesori[counterP++] = novProfesor;
                break;
            }else if(tipNaVraboten == 2){
                Asistent novAsistent = novAsistent.postaviAsistent();
                asistenti[counterA++] = novAsistent;
                break;
            }else if(tipNaVraboten == 3){
                Demonstrator novDemonstrator = novDemonstrator.postaviDemonstrator();
                demonstratori[counterD++] = novDemonstrator;
                break;
            }else{
                break;
            }
        }
        case 2:{
            int tipNaVraboten;
            cout<<"1 - Profesor"<<endl
                 <<"2 - Asistent"<<endl
                 <<"3 - Demonstrator"<<endl;
            cin>>tipNaVraboten;
            if(tipNaVraboten == 1){
                if(counterP == 0)
                    break;
                for(int i = 0; i < counterP; i++){
                    cout<<"Profesor "<<i + 1<<endl;
                    profesori[i].prikaziPodatociProfesor();
                }
                break;
            }else if(tipNaVraboten == 2){
                if(counterA == 0)
                    break;
                for(int i = 0; i < counterA; i++){
                    cout<<"Asistent "<<i + 1<<endl;
                    asistenti[i].prikaziPodatociAsistent();
                }
                break;
            }else if(tipNaVraboten == 3){
                if(counterD == 0)
                    break;
                for(int i = 0; i < counterD; i++){
                    cout<<"Demonstrator "<<i + 1<<endl;
                    demonstratori[i].prikaziPodatociDemonstrator();
                }
                break;
            }else{
                break;
            }
        }
        default:
            break;
        }
    }

    return 0;
}

int meni(){
    int izbor;
    cout<<"1 - Dodavanje na nov vraboten vo listata"<<endl
         <<"2 - Prikazuvanje na listata"<<endl
         <<"3 - Kraj"<<endl;
    cin>>izbor;

    return izbor;
}
