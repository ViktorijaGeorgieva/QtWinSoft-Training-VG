#ifndef KRUG_H
#define KRUG_H

#include "DvoDimenzionalni.h"

class Krug:public DvoDimenzionalni{
public:
    Krug(const string& ime, double radius):DvoDimenzionalni(ime), radius(radius){}
    void pecatenje() const override{
        cout<<"Krug:"<<ime<<" so radius:"<<radius<<endl;
    }
    double plostina() const override{
        return radius * radius * 3.14;
    }
private:
    double radius;
};

#endif
