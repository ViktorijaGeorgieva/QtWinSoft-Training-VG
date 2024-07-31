#ifndef DVODIMENZIONALNI_H
#define DVODIMENZIONALNI_H

#include "Oblik.h"

class DvoDimenzionalni:public Oblik{
public:
    DvoDimenzionalni(const string& ime):Oblik(ime){}
    virtual ~DvoDimenzionalni() = 0;
    double volumen() const override {
        return 0.0;
    }
};

inline DvoDimenzionalni::~DvoDimenzionalni(){}

#endif
