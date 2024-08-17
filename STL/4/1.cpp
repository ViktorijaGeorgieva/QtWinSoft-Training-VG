/*Напиши класа Imenik којa содржи ime и tel_broj. Креирај телефонски именик користејќи контејнер vector. Прикажи го именикот во абецеден редослед.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Imenik{
public:
    Imenik(string, string);
    string getIme() const{
        return ime;
    }
    string getTelBroj() const{
        return telBroj;
    }
private:
    string ime;
    string telBroj;
};

Imenik::Imenik(string ime, string telBroj){
    this->ime = ime;
    this->telBroj = telBroj;
}

bool sporedba(Imenik imenik1, Imenik imenik2){
    return imenik1.getIme() < imenik2.getIme();
}

int main()
{
    vector<Imenik> imenik;

    imenik.push_back(Imenik("Ana", "078456999"));
    imenik.push_back(Imenik("Petar", "077458444"));
    imenik.push_back(Imenik("Trajce", "075898588"));
    imenik.push_back(Imenik("Jana", "076565987"));
    sort(imenik.begin(), imenik.end(), sporedba);
    for(int i = 0; i < imenik.size(); i++){
        cout<<imenik[i].getIme()<<" "<<imenik[i].getTelBroj()<<endl;
    }
    return 0;
}
