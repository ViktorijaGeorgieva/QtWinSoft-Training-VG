#ifndef TRIAGOLNIK_H
#define TRIAGOLNIK_H

#include "DvoDimenzionalni.h"

class Triagolnik:public DvoDimenzionalni{
public:
    Triagolnik(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
