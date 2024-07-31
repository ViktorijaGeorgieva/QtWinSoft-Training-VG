#ifndef SFERA_H
#define SFERA_H

#include "TroDimenzionalni.h"

class Sfera:public TroDimenzionalni{
public:
    Sfera(const string& ime, double radius):TroDimenzionalni(ime), radius(radius){}
    void pecatenje() const override{
        cout<<"Sfera:"<<ime<<" so radius:"<<radius<<endl;
    }
    double plostina() const override{
        return 4 * radius * radius * 3.14;
    }
    double volumen() const override{
        return (4.0/3) * radius * radius * radius * 3.14;
    }
private:
    double radius;
};

#endif
