#ifndef STEDAC_H
#define STEDAC_H

#include "Covek.h"

class Stedac{
public:
    Stedac();
    Stedac(string, string, string, string, int, int);
    ~Stedac();
    static int getKamata();
    static int getBrojStedaci();
    void pecatenje() const;
private:
    Covek lice;
    int bilans;
    int kredit;
    static int kamata;
    static int brojStedaci;
};

#endif
