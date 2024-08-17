#ifndef PRAVOAGOLNIK_H
#define PRAVOAGOLNIK_H
#include <iostream>

using namespace std;

class Pravoagolnik{
public:
    Pravoagolnik();
    Pravoagolnik(double, double);
    double getSirina() const {
        return sirina;
    }
    double getDolzina() const {
        return dolzina;
    }
    bool operator <(const Pravoagolnik &);
    friend ostream &operator<<(ostream&, const Pravoagolnik &);
private:
    double sirina;
    double dolzina;
};

#endif
