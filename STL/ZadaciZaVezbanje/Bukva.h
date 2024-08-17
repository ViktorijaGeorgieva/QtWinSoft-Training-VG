#ifndef BUKVA_H
#define BUKVA_H
#include <iostream>

using namespace std;

class Bukva{
public:
    Bukva();
    Bukva(char);
    char getBukva() const {
        return bukva;
    }
    char getPogodenaBukva() const {
        return pogodenaBukva;
    }
    void setPogodenaBukva();
    friend ostream &operator <<(ostream&, const Bukva &);
private:
    char bukva;
    bool pogodenaBukva;
};

#endif
