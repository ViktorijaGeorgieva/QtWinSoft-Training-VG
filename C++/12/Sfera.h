#ifndef SFERA_H
#define SFERA_H

#include "TroDimenzionalni.h"

class Sfera:public TroDimenzionalni{
public:
    Sfera(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
