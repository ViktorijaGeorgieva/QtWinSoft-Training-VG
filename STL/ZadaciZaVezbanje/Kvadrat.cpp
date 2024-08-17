#include <iostream>

using namespace std;

#include "Kvadrat.h"

Kvadrat::Kvadrat() {}

Kvadrat::Kvadrat(double strana)
{
    this->strana = strana;
}

bool Kvadrat::operator <(const Kvadrat &k)
{
    return strana < k.getStrana();
}

ostream &operator<<(ostream &output, const Kvadrat &k)
{
    output << k.getStrana();

    return output;
}
