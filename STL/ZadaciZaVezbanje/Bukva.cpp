#include <iostream>

using namespace std;

#include "Bukva.h"

Bukva::Bukva() {}

Bukva::Bukva(char bukva)
{
    this->bukva = bukva;
    pogodenaBukva = false;
}

void Bukva::setPogodenaBukva()
{
    pogodenaBukva = true;
}

ostream &operator<<(ostream &output, const Bukva &b)
{
    if(b.getPogodenaBukva())
        output<<b.getBukva();
    else
        output<<"-";

    return output;
}
