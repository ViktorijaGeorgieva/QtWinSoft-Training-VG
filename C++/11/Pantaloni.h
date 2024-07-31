#ifndef PANTALONI_H
#define PANTALONI_H

#include "Artikl.h"

class Pantaloni:public Artikl{
public:
    Pantaloni();
    Pantaloni(char *, int, int, int, int, int, int, int , int);
    void prikaziPodatociPantaloni() const;
    bool presmetajNabavka();
    Datum getDatumNaSlednaNabavka() const;
    Pantaloni postaviPantaloni();
private:
    Datum datumNaSlednaNabavka;
};

#endif
