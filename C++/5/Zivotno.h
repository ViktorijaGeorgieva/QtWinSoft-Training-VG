#ifndef ZIVOTNO_H
#define ZIVOTNO_H

#include "Datum.h"

class Zivotno{
public:
    Zivotno();
    Zivotno(char *, char, char, int, int, int, int, int, int, int, int, int);
    char getTip() const{
        return tip;
    }
    void prikaziPodatoci() const;
    int presmetajVakcinacija();
private:
    Datum datumNaRagjanje;
    Datum datumNaDonesuvanjeVoZoo;
    char tip;
    char pol;
    char ime[20];
    Datum datumNaPoslednaVakcinacija;
};

#endif
