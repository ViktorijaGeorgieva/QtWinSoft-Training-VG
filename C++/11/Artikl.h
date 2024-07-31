#ifndef ARTIKL_H
#define ARTIKL_H

#include "Datum.h"

class Artikl{
public:
    Artikl();
    Artikl(char *, int, int, int, int, int);
    void prikaziPodatociArtikl() const;
    char* getImeNaArtikl() const;
    int getGolemina() const;
    int getCena() const;
    Datum getDatumDonesenVoProdavnica() const;
    void setImeNaArtikl(char *);
    void setGolemina(int);
    void setCena(int);
private:
    char *imeNaArtikl;
    int golemina;
    int cena;
    Datum datumDonesenVoProdavnica;
};


#endif
