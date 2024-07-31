#ifndef ASISTENT_H
#define ASISTENT_H

#include "Vraboten.h"

class Asistent: public Vraboten{
public:
    Asistent();
    Asistent(char *, char *, int, char *, char *, int);
    Asistent postaviAsistent();
    void prikaziPodatociAsistent() const;
private:
    char *zvanje;
    char *mentor;
    int brojPredmeti;
};

#endif
