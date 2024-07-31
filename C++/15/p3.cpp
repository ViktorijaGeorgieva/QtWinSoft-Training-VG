/*Да се направи хиерархија за класата Oblik, така да оваа класа е апстрактна основна класа која содржи интерфејс за целата хиерархија. Од неа
 * директно наследуваат DvoDimenzionalni и TroDimenzionalni кои исто така треба да се апстрактни. Од секоја од овие две  класи да се изведат
 * најмалку по 3 облици. Да се користи виртуелна print функција за да се испечати типот и димензиите на секоја класа. Да се направат и виртуелни
 * функции ploshtina и volumen кои ќе ги пресметуваат ове вредности за секој од облиците. Да се напише тест програма која ги прикажува манипулациите
 * со оваа хиерархија.*/
#include <iostream>
#include <vector>
#include <memory>
#include "Cilindar.h"
#include "Kocka.h"
#include "Krug.h"
#include "Kvadrat.h"
#include "Sfera.h"
#include "Triagolnik.h"

using namespace std;

int main()
{
    vector<unique_ptr<Oblik>> oblici;

    oblici.emplace_back(make_unique<Cilindar>("Cilindar", 2, 5));
    oblici.emplace_back(make_unique<Kocka>("Kocka", 2));
    oblici.emplace_back(make_unique<Krug>("Krug", 5));
    oblici.emplace_back(make_unique<Kvadrat>("Kvadrat", 4));
    oblici.emplace_back(make_unique<Sfera>("Sfera", 3));
    oblici.emplace_back(make_unique<Triagolnik>("Triagolnik", 3, 6));

    for(const auto& oblik:oblici){
        oblik->pecatenje();
        cout<<"Plostina:"<<oblik->plostina()<<endl;
        cout<<"Volumen:"<<oblik->volumen()<<endl;
    }

    return 0;
}
