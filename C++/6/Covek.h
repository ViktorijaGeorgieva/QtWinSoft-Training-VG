#ifndef COVEK_H
#define COVEK_H

using namespace std;

#include <string>

class Covek{
public:
    Covek();
    Covek(string, string, string, string);
    string getIme() const{
        return ime;
    }
    string getPrezime() const{
        return prezime;
    }
    void pecatenje() const;
private:
    string ime;
    string prezime;
    string adresa;
    string telefon;
};

#endif
