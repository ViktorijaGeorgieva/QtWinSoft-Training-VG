#ifndef PRAVOAGOLNIK_H
#define PRAVOAGOLNIK_H

#include "DvoDimenzionalni.h"

class Pravoagolnik:public DvoDimenzionalni{
public:
    Pravoagolnik(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
