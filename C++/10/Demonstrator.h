#ifndef DEMONSTRATOR_H
#define DEMONSTRATOR_H

#include "Vraboten.h"

class Demonstrator: public Vraboten{
public:
    Demonstrator();
    Demonstrator(char *, char *, int, char *, char *);
    Demonstrator postaviDemonstrator();
    void prikaziPodatociDemonstrator() const;
private:
    char *rabotnoVremeOd;
    char *rabotnoVremeDo;
};

#endif
