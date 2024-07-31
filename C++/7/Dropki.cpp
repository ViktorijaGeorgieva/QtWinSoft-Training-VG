#include <iostream>

using namespace std;

#include "Dropki.h"

void Dropki::setVrednostiNaDropka(int broitel, int imenitel){
    this->broitel = broitel;
    this->imenitel = imenitel==0 ? 1 : imenitel;
}

Dropki::Dropki(int broitel, int imenitel){
    setVrednostiNaDropka(broitel, imenitel);
}

int NZD(int br1, int br2){
    if(br2 == 0)
        return br1;
    return NZD(br2, br1 % br2);
}

void reduciranaForma(int &br1, int &br2){
    int nzd;
    nzd = NZD(br1, br2);
    br1 /= nzd;
    br2 /= nzd;
}

Dropki Dropki::operator+(Dropki dropka){
    Dropki tmp;
    int broitelRez, imenitelRez;
    int broitel1 = broitel;
    int broitel2 = dropka.getBroitel();
    int imenitel1 = imenitel;
    int imenitel2 = dropka.getImenitel();

    if((imenitel1 % imenitel2 == 0) || (imenitel2 % imenitel1 == 0)){
        if(imenitel1 >= imenitel2)
            imenitelRez = imenitel1;
        else
            imenitelRez = imenitel2;
    }else{
        imenitelRez = imenitel1 * imenitel2;
    }
    broitel1 = (imenitelRez / imenitel1) * broitel1;
    broitel2 = (imenitelRez / imenitel2) * broitel2;
    broitelRez = broitel1 + broitel2;
    reduciranaForma(broitelRez, imenitelRez);
    tmp.broitel = broitelRez;
    tmp.imenitel = imenitelRez;

    return tmp;
}

Dropki Dropki::operator+(int broj){
    Dropki tmp;
    int broitelRez;
    int broitel1 = broitel;
    int imenitel1 = imenitel;
    int broitel2 = broj * imenitel1;
    broitelRez = broitel1 + broitel2;
    reduciranaForma(broitelRez, imenitel1);
    tmp.broitel = broitelRez;
    tmp.imenitel = imenitel1;

    return tmp;
}

Dropki Dropki::operator-(Dropki dropka){
    Dropki tmp;
    int broitelRez, imenitelRez;
    int broitel1 = broitel;
    int broitel2 = dropka.getBroitel();
    int imenitel1 = imenitel;
    int imenitel2 = dropka.getImenitel();

    if((imenitel1 % imenitel2 == 0) || (imenitel2 % imenitel1 == 0)){
        if(imenitel1 >= imenitel2)
            imenitelRez = imenitel1;
        else
            imenitelRez = imenitel2;
    }else{
        imenitelRez = imenitel1 * imenitel2;
    }
    broitel1 = (imenitelRez / imenitel1) * broitel1;
    broitel2 = (imenitelRez / imenitel2) * broitel2;
    broitelRez = broitel1 - broitel2;
    reduciranaForma(broitelRez, imenitelRez);
    tmp.broitel = broitelRez;
    tmp.imenitel = imenitelRez;

    return tmp;
}

Dropki Dropki::operator-(int broj){
    Dropki tmp;
    int broitelRez;
    int broitel1 = broitel;
    int imenitel1 = imenitel;
    int broitel2 = broj * imenitel1;

    broitelRez = broitel1 - broitel2;
    reduciranaForma(broitelRez, imenitel1);
    tmp.broitel = broitelRez;
    tmp.imenitel = imenitel1;

    return tmp;
}

Dropki Dropki::operator*(Dropki dropka){
    Dropki tmp;
    int broitelRez, imenitelRez;
    int broitel1 = broitel;
    int broitel2 = dropka.getBroitel();
    int imenitel1 = imenitel;
    int imenitel2 = dropka.getImenitel();

    broitelRez = broitel1 * broitel2;
    imenitelRez = imenitel1 * imenitel2;
    reduciranaForma(broitelRez, imenitelRez);
    tmp.broitel = broitelRez;
    tmp.imenitel = imenitelRez;

    return tmp;
}

Dropki Dropki::operator*(int broj){
    Dropki tmp;
    int broitelRez;
    int broitel1 = broitel;
    int imenitel1 = imenitel;

    broitelRez = broitel1 * broj;
    reduciranaForma(broitelRez, imenitel1);
    tmp.broitel = broitelRez;
    tmp.imenitel = imenitel1;

    return tmp;
}

Dropki Dropki::operator/(Dropki dropka){
    Dropki tmp;
    int broitelRez, imenitelRez;
    int broitel1 = broitel;
    int broitel2 = dropka.getBroitel();
    int imenitel1 = imenitel;
    int imenitel2 = dropka.getImenitel();

    broitelRez = broitel1 * imenitel2;
    imenitelRez = broitel2 * imenitel1;
    reduciranaForma(broitelRez, imenitelRez);
    tmp.broitel = broitelRez;
    tmp.imenitel = imenitelRez;

    return tmp;
}

Dropki Dropki::operator/(int broj){
    Dropki tmp;
    int imenitelRez;
    int broitel1 = broitel;
    int imenitel1 = imenitel;

    imenitelRez = imenitel1 * broj;
    reduciranaForma(broitel1, imenitelRez);
    tmp.broitel = broitel1;
    tmp.imenitel = imenitelRez;

    return tmp;
}

void Dropki::pecatenje(){
    cout<<broitel<<"/"<<imenitel<<"="<<pecatenjeVoFormaNaRealenBroj()<<endl;
}

float Dropki::pecatenjeVoFormaNaRealenBroj(){
    return (float) broitel / imenitel;
}
