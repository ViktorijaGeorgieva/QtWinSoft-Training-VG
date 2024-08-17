/*Во една фирма платата на вработените се пресметува како производ од број на бодови и вредност на бод. Вредноста на бодот е иста за сите вработени.
 * Имплементирај класа Vraboten која содржи податочни членови ime и bodovi. Напиши програма со која ќе се пресмета вкупната сума за да се исплати
 * месечна плата за целата фирма. Програмата треба да ја прикаже вкупната сума и список на вработените сортиран според бројот на бодови.
 * За пресметување на сумата да се употреби accumulate. За сортирање на листата да се употреби sort.  */
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

class Vraboten{
public:
    Vraboten();
    Vraboten(string, int);
    string getIme() const{
        return ime;
    }
    int getBodovi() const{
        return bodovi;
    }
    friend ostream &operator<<(ostream&, const Vraboten &);
private:
    string ime;
    int bodovi;
};

Vraboten::Vraboten(){}

Vraboten::Vraboten(string ime, int bodovi){
    this->ime = ime;
    this->bodovi = bodovi;
}

ostream &operator<<(ostream &output, const Vraboten &vraboten){
    output<<vraboten.getIme()<<":"<<vraboten.getBodovi();

    return output;
}

bool sporedba(Vraboten v1, Vraboten v2){
    return v1.getBodovi() < v2.getBodovi();
}

int main()
{
    vector<Vraboten> vraboteni;
    ostream_iterator<Vraboten> output(cout, "\n");
    int vrednostBod, brojVraboteni, bodoviVraboten;
    string ime;

    cout<<"Vnesi broj na vraboteni:"<<endl;
    cin>>brojVraboteni;
    for(int i = 0; i < brojVraboteni; i++){
        cout<<"Vnesi ime na vraboten:"<<endl;
        cin.ignore();
        getline(cin, ime);
        cout<<"Vnesi bodovi:"<<endl;
        cin>>bodoviVraboten;
        vraboteni.push_back(Vraboten(ime, bodoviVraboten));
    }
    cout<<"Vnesi vrednost na bod:"<<endl;
    cin>>vrednostBod;
    sort(vraboteni.begin(), vraboteni.end(), sporedba);
    copy(vraboteni.begin(), vraboteni.end(), output);
    int suma = accumulate(vraboteni.begin(), vraboteni.end(), 0, [](int i, Vraboten &v){
        return v.getBodovi() + i;
    });
    cout<<"Vkupna suma:"<<suma * vrednostBod<<endl;

    return 0;
}
