#ifndef KOSULI_H
#define KOSULI_H

#include "Artikl.h"

class Kosuli:public Artikl{
public:
    Kosuli();
    Kosuli(char *, int, int, int, int, int);
    void prikaziPodatociKosuli() const;
    bool presmetajNabavka();
    Kosuli postaviKosuli();
};

#endif
