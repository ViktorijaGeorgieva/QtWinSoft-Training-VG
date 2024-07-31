#ifndef CILINDAR_H
#define CILINDAR_H

#include "TroDimenzionalni.h"

class Cilindar:public TroDimenzionalni{
public:
    Cilindar(const string& ime, double radius, double visina):TroDimenzionalni(ime), radius(radius), visina(visina){}
    void pecatenje() const override{
        cout<<"Cilindar:"<<ime<<" so radius:"<<radius<<" i visina:"<<visina<<endl;
    }
    double plostina() const override{
        return 2 * 3.14 * radius * (radius + visina);
    }
    double volumen() const override{
        return 3.14 * radius * radius * visina;
    }
private:
    double radius;
    double visina;
};

#endif
