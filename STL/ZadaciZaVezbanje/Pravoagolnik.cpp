#include <iostream>
#include <iomanip>

using namespace std;

#include "Pravoagolnik.h"

Pravoagolnik::Pravoagolnik() {}

Pravoagolnik::Pravoagolnik(double sirina, double dolzina)
{
    this->sirina = sirina;
    this->dolzina = dolzina;
}

bool Pravoagolnik::operator <(const Pravoagolnik &p)
{
    return sirina * dolzina < p.getSirina() * p.getDolzina();
}

ostream &operator<<(ostream &output, const Pravoagolnik &p)
{
    output<<p.getSirina()<<setw(10)<<p.getDolzina();

    return output;
}
