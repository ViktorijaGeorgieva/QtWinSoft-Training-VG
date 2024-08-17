#ifndef KVADRAT_H
#define KVADRAT_H

class Kvadrat{
public:
    Kvadrat(int = 1);
    Kvadrat postavi();
    int getPlostina() const;
private:
    int strana;
    int plostina;
};

#endif
