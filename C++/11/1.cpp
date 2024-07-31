/*Во една продавница се води евиденција за артиклите кои се продаваат во неа: пантолони и кошули. Користејќи ги концептите на ООП да се моделираат
 * соодветни класи според спецификациите дадени на сликата. Пратката на пантолони доаѓа секој месец, а нарачки на кошули се прават по потреба.
 * Во main() функцијата да се конструира низа од долунаведените класи (пантолони, кошули) и да се имплементира кориснички посредник преку мени со
 * следните опции:
1.Додавање на артикл во листата
2.Прикажување на артикли од дадена група
3.Прикажување на целата листа (со вкупна цена)
4.Прикажување на сите артикли кои треба да се набават во рок од 1 недела и пари кои треба да се потрошат за да се набават потребните артикли
5.Излез од менито

Приватната членка Donesen_vo_prodavnica е од тип Datum кој треба да се дефинира во посебна класа.
*/
#include <iostream>

using namespace std;

#include "Pantaloni.h"
#include "Kosuli.h"

int meni();

int main()
{
    int izbor, counterP = 0, counterK = 0;
    Pantaloni pantaloni[100];
    Kosuli kosuli[100];

    while ((izbor = meni()) != 5) {
        switch (izbor) {
        case 1:{
            int tipNaArtikl;
            cout<<"1 - Pantaloni"<<endl
                 <<"2 - Kosuli"<<endl;
            cin>>tipNaArtikl;
            if(tipNaArtikl == 1){
                Pantaloni noviPantaloni = noviPantaloni.postaviPantaloni();
                pantaloni[counterP++] = noviPantaloni;
                break;
            }else if(tipNaArtikl == 2){
                Kosuli novaKosula = novaKosula.postaviKosuli();
                kosuli[counterK++] = novaKosula;
                break;
            }else
                break;
        }
        case 2:{
            int tipNaArtikl;
            cout<<"1 - Pantaloni"<<endl
                 <<"2 - Kosuli"<<endl;
            cin>>tipNaArtikl;
            if(tipNaArtikl == 1){
                if(counterP == 0)
                    break;
                for(int i = 0; i < counterP; i++){
                    cout<<"Pantaloni "<<i + 1<<endl;
                    pantaloni[i].prikaziPodatociPantaloni();
                }
                break;
            }else if(tipNaArtikl == 2){
                if(counterK == 0)
                    break;
                for(int i = 0; i < counterK; i++){
                    cout<<"Kosuli "<<i + 1<<endl;
                    kosuli[i].prikaziPodatociKosuli();
                }
                break;
            }else
                break;
        }
        case 3:{
            int vkupnaCena = 0;
            if(counterK == 0 && counterP == 0)
                break;
            for(int i = 0; i < counterP; i++){
                cout<<"Pantaloni "<<i + 1<<endl;
                pantaloni[i].prikaziPodatociPantaloni();
                vkupnaCena += pantaloni[i].getCena();
            }
            for(int i = 0; i < counterK; i++){
                cout<<"Kosula "<<i + 1<<endl;
                kosuli[i].prikaziPodatociKosuli();
                vkupnaCena += kosuli[i].getCena();
            }
            cout<<"Vkupna cena na site artikli:"<<vkupnaCena<<" denari."<<endl;
            break;
        }
        case 4:{
            int vkupnaCena = 0;
            if(counterP == 0)
                break;
            for(int i = 0; i < counterP; i++){
                if(pantaloni[i].presmetajNabavka()){
                    cout<<"Pantaloni "<<i + 1<<endl;
                    pantaloni[i].prikaziPodatociPantaloni();
                    vkupnaCena += pantaloni[i].getCena();
                }
            }
            cout<<"Vkupna cena na site artikli koi treba da se nabavat:"<<vkupnaCena<<" denari."<<endl;
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
    cout<<"1 - Dodavanje na artikl vo listata"<<endl
         <<"2 - Prikazuvanje na artikli od dadena grupa"<<endl
         <<"3 - Prikazuvanje na celata lista (so vkupna cena)"<<endl
         <<"4 - Prikazuvanje na site artikli koi treba da se nabavat vo rok od 1 nedela i pari koi treba da se potrosat za da se nabavat potrebnite artikli"<<endl
         <<"5 - Izlez od menito"<<endl;
    cin>>izbor;

    return izbor;
}
