#ifndef KVADRAT_H
#define KVADRAT_H

#include "DvoDimenzionalni.h"

class Kvadrat:public DvoDimenzionalni{
public:
    Kvadrat(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
