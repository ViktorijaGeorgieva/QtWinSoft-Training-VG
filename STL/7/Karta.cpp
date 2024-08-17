#include <iostream>

using namespace std;

#include "Karta.h"

Karta::Karta(){}

Karta::Karta(int broj, string boja)
{
    this->broj = broj;
    this->boja = boja;
}

ostream &operator<<(ostream &output, const Karta &karta)
{
    output<<karta.getBroj()<<" "<<karta.getBoja();

    return output;
}
