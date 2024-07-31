/*Да се формира класа Квадар (скриени елементи: должина, ширина и висина; јавни функции: плоштина, волумен). Од неа да се имплементира поле од
 * објекти. Да се најде оној кој има најмала плоштина, а не е коцка. Да се креира мени:
a)	Креирај нов објект
b)	Постави ги димензиите
c)	Печати ги димензиите на сите објекти
d)	Печати ги димензиите за поедин објект
e)	Печати ги оние кои го задоволуваат условот
*/
#include <iostream>

using namespace std;

class Kvadar{
private:
    int dolzina;
    int sirina;
    int visina;
public:
    Kvadar(){}
    Kvadar(int dolzina, int sirina, int visina){
        this->dolzina = dolzina;
        this->sirina = sirina;
        this->visina = visina;
    }
    int getDolzina(){
        return dolzina;
    }
    int getSirina(){
        return sirina;
    }
    int getVisina(){
        return visina;
    }
    void postaviDimenzii();
    void pecatiDimenzii();
    int plostina();
    int volumen();
};

void Kvadar::postaviDimenzii(){
    cout<<"Vnesi dolzina na kvadar: ";
    cin>>dolzina;
    cout<<"Vnesi sirina na kvadar: ";
    cin>>sirina;
    cout<<"Vnesi visina na kvadar: ";
    cin>>visina;
}

void Kvadar::pecatiDimenzii(){
    cout<<"Dolzinata na kvadarot e "<<dolzina<<", sirinata na kvadarot e "<<sirina<<", visinata na kvadarot e "<<visina<<endl;
}

int Kvadar::plostina(){
    if(dolzina == sirina && sirina==visina)
        return 6 * (dolzina * dolzina);
    else
        return 2 * (dolzina * sirina + sirina * visina + dolzina * visina);
}

int Kvadar::volumen(){
    return dolzina * sirina * visina;
}
int meni(){
    int izbor;
    cout<<"1 - Kreiraj nov objekt."<<endl
         <<"2 - Postavi gi dimenziite."<<endl
         <<"3 - Pecati gi dimenziite na site objekti."<<endl
         <<"4 - Pecati gi dimenziite za poedinecen objekt."<<endl
         <<"5 - Pecati gi onie koi go zadovoluvaat uslovot."<<endl
         <<"6 - Kraj"<<endl;
    cin>>izbor;
    return izbor;
}

int main()
{
    int izbor, counter = 0;
    Kvadar kvadari[100];

    while ((izbor = meni()) != 6) {
        switch (izbor) {
        case 1:{
            Kvadar novKvadar;
            kvadari[counter++] = novKvadar;
            break;
        }
        case 2: {
            int brNaKvadar;
            cout<<"Vnesi broj na kvadar: ";
            cin>>brNaKvadar;
            if(brNaKvadar > counter || brNaKvadar <= 0){
                cout<<"Ne postoi kvadar so broj "<<brNaKvadar<<endl;
                break;
            }
            kvadari[brNaKvadar - 1].postaviDimenzii();
            break;
        }
        case 3: {
            int i;
            for(i = 0; i < counter; i++){
                cout<<"Kvadar "<<i + 1<<endl;
                kvadari[i].pecatiDimenzii();
            }
            break;
        }
        case 4: {
            int brNaKvadar;
            cout<<"Vnesi broj na kvadar: ";
            cin>>brNaKvadar;
            if(brNaKvadar > counter || brNaKvadar <= 0){
                cout<<"Ne postoi kvadar so broj "<<brNaKvadar<<endl;
                break;
            }
            cout<<"Kvadar "<<brNaKvadar<<endl;
            kvadari[brNaKvadar - 1].pecatiDimenzii();
            break;
        }
        case 5: {
            int i, tmp;
            int minPlostina = INT_MAX;
            int indeks = -1;
            for(i = 0; i < counter; i++){
                if(kvadari[i].getDolzina() == kvadari[i].getSirina() && kvadari[i].getSirina() == kvadari[i].getVisina())
                    continue;
                else{
                    tmp = kvadari[i].plostina();
                    if(minPlostina > tmp){
                        indeks = i;
                        minPlostina = tmp;
                    }
                }
            }
            if(indeks != -1){
                cout<<"Kvadar "<<indeks + 1<<" ima najmala plostina: "<<minPlostina<<endl;
            }else{
                cout<<"Nieden kvadar ne go zadovoluva uslovot."<<endl;
            }
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
