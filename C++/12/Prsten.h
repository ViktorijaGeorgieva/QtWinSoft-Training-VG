#ifndef PRSTEN_H
#define PRSTEN_H

#include "DvoDimenzionalni.h"

class Prsten:public DvoDimenzionalni{
public:
    Prsten(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
