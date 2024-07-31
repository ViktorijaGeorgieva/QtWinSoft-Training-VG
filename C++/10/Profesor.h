#ifndef PROFESOR_H
#define PROFESOR_H

#include "Vraboten.h"

class Profesor: public Vraboten{
public:
    Profesor();
    Profesor(char *, char *, int, char *, char *, int);
    Profesor postaviProfesor();
    void prikaziPodatociProfesor() const;
private:
    char *zvanje;
    char *oblast;
    int brojPredmeti;
};

#endif
