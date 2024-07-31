#ifndef CILINDAR_H
#define CILINDAR_H

#include "TroDimenzionalni.h"

class Cilindar:public TroDimenzionalni{
public:
    Cilindar(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
