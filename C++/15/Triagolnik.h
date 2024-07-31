#ifndef TRIAGOLNIK_H
#define TRIAGOLNIK_H

#include "DvoDimenzionalni.h"

class Triagolnik:public DvoDimenzionalni{
public:
    Triagolnik(const string& ime, double strana, double visina):DvoDimenzionalni(ime), strana(strana), visina(visina){}
    void pecatenje() const override{
        cout<<"Triagolnik:"<<ime<<" so strana:"<<strana<<" i visina:"<<visina<<endl;
    }
    double plostina() const override{
        return strana * visina * 0.5;
    }
private:
    double strana;
    double visina;
};

#endif
