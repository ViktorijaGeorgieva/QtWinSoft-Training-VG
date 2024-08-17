/*Во една банка пристигаат уплати за штедачи. Напиши програма во која ќе се внесуваат податоци за уплати и ќе се прикажува листа и вкупна уплата за
 * даден штедач. Импламентирај класа Uplata која содржи податоци за штедач и големина на уплата. Користи контејнер multimap. Програмата треба да
 * овозможува едноставно мени за внесување и прикажување на уплати.
1.Додај уплата
2.Прикажи уплати за даден штедач
3.Крај*/
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

class Uplata{
public:
    Uplata(string, int);
    string getIme() const{
        return ime;
    }
    int getUplata() const{
        return uplata;
    }
private:
    string ime;
    int uplata;
};

Uplata::Uplata(string ime, int uplata){
    this->ime = ime;
    this->uplata = uplata;
}

typedef multimap<string, Uplata, less<string>> mmid;

int meni();

int main()
{
    int izbor;
    mmid pairs;

    while((izbor = meni()) != 3){
        switch (izbor) {
        case 1:{
            string ime;
            int uplata;
            cout<<"Vnesi ime na stedac: ";
            cin.ignore();
            getline(cin, ime);
            cout<<"Vnesi uplata: ";
            cin>>uplata;
            pairs.insert(mmid::value_type(ime, Uplata(ime, uplata)));
            break;
        }
        case 2:{
            mmid::const_iterator itr;
            string ime;
            cout<<"Vnesi ime na stedac: ";
            cin.ignore();
            getline(cin, ime);
            if(pairs.count(ime) == 0){
                cout<<"Ne postoi stedacot."<<endl;
                break;
            }
            itr = pairs.find(ime);
            cout<<"Stedacot "<<itr->second.getIme()<<" ima uplata od "<<itr->second.getUplata()<<endl;
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
    cout<<"Vnesi izbor: "<<endl
         <<"1 - Dodaj uplata: "<<endl
         <<"2 - Prikazi uplati za daden stedac."<<endl
         <<"3 - Za kraj"<<endl;
    cin>>izbor;
    return izbor;
}
