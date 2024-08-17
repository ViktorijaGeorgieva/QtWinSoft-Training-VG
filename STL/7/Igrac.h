#ifndef IGRAC_H
#define IGRAC_H

#include <string>
#include "Karta.h"

using namespace std;

class Igrac {
public:
    Igrac();
    void vnesiKarta(Karta karta);
    int suma(int);
    void pecatenje() const;
private:
    int counter;
    Karta karti[30];
};

#endif
