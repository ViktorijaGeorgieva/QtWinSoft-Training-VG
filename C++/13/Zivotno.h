#ifndef ZIVOTNO_H
#define ZIVOTNO_H

#include "Datum.h"

class Zivotno{
public:
    Zivotno();
    Zivotno(char *, char, int, int, int, int, int, int, int, int, int);
    void prikaziPodatociZivotno() const;
    virtual bool presmetajVakcinacija() = 0;
    char* getIme() const;
    char getPol() const;
    Datum getDatumNaRagjanje() const;
    Datum getDatumNaDonesuvanjeVoZooloska() const;
    Datum getDatumNaPoslednaVakcinacija() const;
private:
    char *ime;
    char pol;
    Datum datumNaRagjanje;
    Datum datumNaDonesuvanjeVoZooloska;
    Datum datumNaPoslednaVakcinacija;

};

#endif
