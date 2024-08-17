#ifndef PRAVOAGOLNIK_H
#define PRAVOAGOLNIK_H

#include "Oblik.h"

class Pravoagolnik:public Oblik{
    double sirina, visina;
public:
    Pravoagolnik(double s, double v);

    double plostina() const override;
    bool operator==(const Oblik& o) const override;
};

#endif
