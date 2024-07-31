#ifndef VLEKACI_H
#define VLEKACI_H

#include "Datum.h"
#include "Zivotno.h"

class Vlekaci:public Zivotno{
public:
    Vlekaci();
    Vlekaci(char *, char, int, int, int, int, int, int, int, int, int, int, int, int);
    void prikaziPodatoci() const;
    bool presmetajVakcinacija();
    Datum getDatumNaSlednaVakcinacija() const;
    Vlekaci postavi();
private:
    Datum datumNaSlednaVakcinacija;
};

#endif
