#ifndef VRABOTEN_H
#define VRABOTEN_H

class Vraboten{
public:
    Vraboten();
    Vraboten(char *, char *, int);
    Vraboten postaviVraboten();
    void prikaziPodatociVraboten() const;
private:
    char *ime;
    char *prezime;
    int godinaNaVrabotuvanje;
};

#endif
