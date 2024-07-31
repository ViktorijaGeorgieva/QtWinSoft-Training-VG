#ifndef OBLIK_H
#define OBLIK_H

#include <iostream>
#include <cstring>

using namespace std;

class Oblik{
public:
    Oblik(const string& ime):ime(ime){}
    virtual ~Oblik() = 0;
    virtual void pecatenje() const = 0;
    virtual double plostina() const = 0;
    virtual double volumen() const = 0;
protected:
    string ime;
};

inline Oblik::~Oblik(){}

#endif
