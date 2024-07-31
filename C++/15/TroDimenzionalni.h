#ifndef TRODIMENZIONALNI_H
#define TRODIMENZIONALNI_H

#include "Oblik.h"

class TroDimenzionalni:public Oblik{
public:
    TroDimenzionalni(const string& ime):Oblik(ime){}
    virtual ~TroDimenzionalni() = 0;
    double plostina() const override = 0;
};

inline TroDimenzionalni::~TroDimenzionalni(){}

#endif
