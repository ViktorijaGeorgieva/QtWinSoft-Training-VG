#ifndef KOCKA_H
#define KOCKA_H

#include "TroDimenzionalni.h"

class Kocka:public TroDimenzionalni{
public:
    Kocka(const string& ime, double strana):TroDimenzionalni(ime), strana(strana){}
    void pecatenje() const override{
        cout<<"Kocka:"<<ime<<" so strana:"<<strana<<endl;
    }
    double plostina() const override{
        return 6 * strana * strana;
    }
    double volumen() const override{
        return strana * strana * strana;
    }
private:
    double strana;
};

#endif
