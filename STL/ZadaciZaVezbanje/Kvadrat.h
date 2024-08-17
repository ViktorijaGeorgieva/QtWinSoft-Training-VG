#ifndef KVADRAT_H
#define KVADRAT_H
#include <iostream>

using namespace std;

class Kvadrat{
public:
    Kvadrat();
    Kvadrat(double);
    double getStrana() const {return strana;}
    bool operator <(const Kvadrat &);
    friend ostream &operator<<(ostream&, const Kvadrat &);
private:
    double strana;
};

#endif
