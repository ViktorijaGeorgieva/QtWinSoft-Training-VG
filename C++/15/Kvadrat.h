#ifndef KVADRAT_H
#define KVADRAT_H

#include "DvoDimenzionalni.h"

class Kvadrat:public DvoDimenzionalni{
public:
    Kvadrat(const string& ime, double strana):DvoDimenzionalni(ime), strana(strana){}
    void pecatenje() const override{
        cout<<"Kvadrat:"<<ime<<" so strana:"<<strana<<endl;
    }
    double plostina() const override{
        return strana * strana;
    }
private:
    double strana;
};

#endif
