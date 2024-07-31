/*Да се направи програма која ќе ја користи класата Штедач и ќе овозможи:
a)	Внесување на нов штедач во системот
b)	Приказ на податоците
c)	Уплата на средства
d)	Исплата на средства (со контрола дали е можна таква исплата)
e)	Приказ на салдото за даден штедач
class Stedac
{
 public:
        void vnesi_podatoci();
        void prikazi_podatoci();
        void uplata(unsigned long i);
        void isplata(unsigned long i);
        long sostojba();

  private:
        int broj;
        char imeprezime[30], adresa[50];
        long saldo;
};
*/
#include <iostream>

using namespace std;

class Stedac{
private:
    int broj;
    char imeprezime[30], adresa[50];
    long saldo;
public:
    void vnesi_podatoci();
    void prikazi_podatoci();
    void uplata(unsigned long i);
    void isplata(unsigned long i);
    long sostojba();
};

void Stedac::vnesi_podatoci(){
    cout<<"Vnesi broj: ";
    cin>>broj;
    cin.ignore();
    cout<<"Vnesi ime i prezime: ";
    cin.getline(imeprezime, 30);
    cout<<"Vnesi adresa: ";
    cin.getline(adresa, 50);
    cout<<"Vnesi saldo: ";
    cin>>saldo;
}

void Stedac::prikazi_podatoci(){
    cout<<"Broj: "<<broj<<endl;
    cout<<"Ime i prezime: "<<imeprezime<<endl;
    cout<<"Adresa: "<<adresa<<endl;
    cout<<"Saldo: "<<saldo<<endl;
}

void Stedac::uplata(unsigned long i){
    saldo += i;
    cout<<"Uplata od "<<i<<" denari. Novata sostojba e "<<saldo<<" denari."<<endl;
}

void Stedac::isplata(unsigned long i){
    if(saldo >= i){
        saldo -= i;
        cout<<"Isplata od "<<i<<" denari. Novata sostojba e "<<saldo<<" denari."<<endl;
    }else{
        cout<<"Nemate dovolno sredstva."<<endl;
    }
}

long Stedac::sostojba(){
    return saldo;
}

int meni(){
    int izbor;
    cout<<"1 - Vnesuvanje na nov stedac vo sistemot."<<endl
         <<"2 - Prikaz na podatocite."<<endl
         <<"3 - Uplata na sredstva."<<endl
         <<"4 - Isplata na sredstva (so kontrola dali e mozna takva isplata)."<<endl
         <<"5 - Prikaz na saldoto za daden stedac."<<endl
         <<"6 - Kraj."<<endl;
    cin>>izbor;
    return izbor;
}

int main()
{
    int izbor, counter = 0;
    Stedac stedaci[100];

    while((izbor = meni()) != 6){
        switch (izbor) {
        case 1:{
            Stedac novStedac;
            novStedac.vnesi_podatoci();
            stedaci[counter++] = novStedac;
            break;
        }
        case 2:{
            int brNaStedac;
            cout<<"Vnesi broj na stedac: ";
            cin>>brNaStedac;
            if(brNaStedac > counter || brNaStedac <= 0){
                cout<<"Ne postoi stedac so toj broj."<<endl;
            }else{
                stedaci[brNaStedac - 1].prikazi_podatoci();
            }
            break;
        }
        case 3:{
            int brNaStedac;
            unsigned long iznos;
            cout<<"Vnesi broj na stedac: ";
            cin>>brNaStedac;
            if(brNaStedac > counter || brNaStedac <= 0){
                cout<<"Ne postoi stedac so toj broj."<<endl;
            }else{
                cout<<"Vnesi iznos za uplata: ";
                cin>>iznos;
                stedaci[brNaStedac - 1].uplata(iznos);
            }
            break;
        }
        case 4:{
            int brNaStedac;
            unsigned long iznos;
            cout<<"Vnesi broj na stedac: ";
            cin>>brNaStedac;
            if(brNaStedac > counter || brNaStedac <= 0){
                cout<<"Ne postoi stedac so toj broj."<<endl;
            }else{
                cout<<"Vnesi iznos za isplata: ";
                cin>>iznos;
                stedaci[brNaStedac - 1].isplata(iznos);
            }
            break;
        }
        case 5:{
            int brNaStedac;
            cout<<"Vnesi broj na stedac: ";
            cin>>brNaStedac;
            if(brNaStedac > counter || brNaStedac <= 0){
                cout<<"Ne postoi stedac so toj broj."<<endl;
            }else{
                cout<<"Saldoto na stedac "<<brNaStedac<<" e "<<stedaci[brNaStedac - 1].sostojba()<<" denari."<<endl;
            }
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
