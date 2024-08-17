#ifndef KRUG_H
#define KRUG_H

#include "Oblik.h"

class Krug:public Oblik{
    double radius;
public:
    Krug(double r);

    double plostina() const override;
    bool operator==(const Oblik& o) const override;
};

#endif
