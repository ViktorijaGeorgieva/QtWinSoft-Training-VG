#include "Pravoagolnik.h"

Pravoagolnik::Pravoagolnik(double s, double v):sirina(s), visina(v){}

double Pravoagolnik::plostina() const{
    return sirina * visina;
}

bool Pravoagolnik::operator==(const Oblik& o) const{
    const Pravoagolnik* p = dynamic_cast<const Pravoagolnik*>(&o);
    return p && sirina == p->sirina && visina == p->visina;
}
