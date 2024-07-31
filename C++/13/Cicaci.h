#ifndef CICACI_H
#define CICACI_H

#include "Zivotno.h"

class Cicaci:public Zivotno{
public:
    Cicaci();
    Cicaci(char *, char, char, int, int, int, int, int, int, int, int, int);
    void prikaziPodatoci() const;
    bool presmetajVakcinacija();
    Cicaci postavi();
    char getPrezivar() const;
private:
    char prezivar;
};

#endif
