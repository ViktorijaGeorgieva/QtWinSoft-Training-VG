#ifndef DATUM_H
#define DATUM_H

class Datum{
public:
    Datum(int = 1, int = 1, int = 2000);
    int getDen() const{
        return den;
    }
    int getMesec() const{
        return mesec;
    }
    int getGodina() const{
        return godina;
    }
    void pecatenje() const;
private:
    int den;
    int mesec;
    int godina;
    int proverka(int);
};

#endif
