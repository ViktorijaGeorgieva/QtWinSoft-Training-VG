#include "Kvadrat.h"

Kvadrat::Kvadrat(double s):strana(s){}

double Kvadrat::plostina() const{
    return strana * strana;
}

bool Kvadrat::operator==(const Oblik& o) const{
    const Kvadrat* k = dynamic_cast<const Kvadrat*>(&o);
    return k && strana == k->strana;
}
