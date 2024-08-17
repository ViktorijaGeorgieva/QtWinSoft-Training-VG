#include "Krug.h"
#include <cmath>

Krug::Krug(double r):radius(r){}

double Krug::plostina() const{
    return M_PI * radius * radius;
}

bool Krug::operator==(const Oblik& o) const{
    const Krug* k = dynamic_cast<const Krug*>(&o);
    return k && radius == k->radius;
}
