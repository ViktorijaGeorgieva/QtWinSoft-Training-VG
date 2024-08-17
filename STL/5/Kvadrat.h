#ifndef KVADRAT_H
#define KVADRAT_H

#include "Oblik.h"

class Kvadrat:public Oblik{
    double strana;
public:
    Kvadrat(double s);

    double plostina() const override;
    bool operator==(const Oblik& o) const override;
};

#endif
