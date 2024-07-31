#ifndef KRUG_H
#define KRUG_H

#include "DvoDimenzionalni.h"

class Krug:public DvoDimenzionalni{
public:
    Krug(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
