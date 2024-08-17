#ifndef PRAVOAGOLNIK_H
#define PRAVOAGOLNIK_H

class Pravoagolnik{
public:
    Pravoagolnik(int = 1, int = 1);
    Pravoagolnik postavi();
    int getPlostina() const;
private:
    int sirina;
    int dolzina;
    int plostina;
};

#endif
