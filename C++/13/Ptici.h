#ifndef PTICI_H
#define PTICI_H

#include "Zivotno.h"

class Ptici:public Zivotno{
public:
    Ptici();
    Ptici(char *, char, char, int, int, int, int, int, int, int, int, int);
    void prikaziPodatoci() const;
    bool presmetajVakcinacija();
    char getLetac() const;
    Ptici postavi();
private:
    char letac;
};

#endif
