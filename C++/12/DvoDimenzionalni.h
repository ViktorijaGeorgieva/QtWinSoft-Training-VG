#ifndef DVODIMENZIONALNI_H
#define DVODIMENZIONALNI_H

#include "Oblik.h"

class DvoDimenzionalni:public Oblik{
public:
    DvoDimenzionalni(const char* ime);
    ~DvoDimenzionalni();
    static int getBr();
private:
    inline static int br = 0;
};

#endif
