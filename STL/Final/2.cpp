/*Во еден магацин се води евиденција за артикли. Во текстуална датотека inventar.txt се чуваат следните податоци за секој артикл: инвентарен број
 * (int), количество (int) и цена (double) за секој артикл.  Креирај класа Inventar која содржи id, kolicestvo и cena.  Напиши програма во која се
 * создава vector од артикли, а потоа прикажува вкупна вредност на артиклите во магацинот и листа на сите артикли за кои количеството е помало од 10.
 * Пресметувањето на вкупната вредност и прикажувањето на артиклите изврши го со STL алгоритми. Ако не постои влезна датотека, програмата да фрли
 * исклучок. */
#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>


using namespace std;

class Inventar{
public:
    Inventar();
    Inventar(int, int, double);
    int getId() const{
        return id;
    }
    int getKolicestvo() const{
        return kolicestvo;
    }
    double getCena() const{
        return cena;
    }
    friend ostream &operator<<(ostream&, const Inventar &);
private:
    int id;
    int kolicestvo;
    double cena;
};

Inventar::Inventar(){}

Inventar::Inventar(int id, int kolicestvo, double cena){
    this->id = id;
    this->kolicestvo = kolicestvo;
    this->cena = cena;
}

ostream &operator<<(ostream &output, const Inventar &inventar){
    output<<inventar.getId()<<setw(20)<<inventar.getKolicestvo()<<setw(20)<<inventar.getCena();

    return output;
}

int main()
{
    vector<Inventar> inventar;
    ostream_iterator<Inventar> output(cout, "\n");
    int id, kolicestvo;
    double cena, vkupno;
    ifstream readInventar("inventar.txt", ios::in);
    if(!readInventar){
        throw std::logic_error("Ne e pronajdena datotekata.");
    }
    while(readInventar>>id>>kolicestvo>>cena){
        inventar.push_back(Inventar(id, kolicestvo, cena));
    }
    vkupno = accumulate(inventar.begin(), inventar.end(), 0.0, [](double i, Inventar &inventar){
        return inventar.getCena() * inventar.getKolicestvo() + i;
    });
    cout<<"Vkupna cena:"<<endl
         <<vkupno<<endl;
    cout<<"Lista na artikli so kolicestvo pomalo od 10:"<<endl;
    cout<<"Id"<<setw(20)<<"Kolicestvo"<<setw(20)<<"Cena"<<endl;
    copy_if(inventar.begin(), inventar.end(), output, [](Inventar inventar){
        return inventar.getKolicestvo() < 10;
    });
    readInventar.close();

    return 0;
}
