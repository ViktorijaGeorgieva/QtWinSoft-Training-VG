#ifndef KARTA_H
#define KARTA_H

#include <string>

using namespace std;

class Karta {
public:
    Karta();
    Karta(int, string);
    int getBroj() const {return broj;}
    string getBoja() const {return boja;}
    friend ostream &operator<<(ostream&, const Karta &);
private:
    int broj;
    string boja;
};

#endif
