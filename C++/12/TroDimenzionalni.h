#ifndef TRODIMENZIONALNI_H
#define TRODIMENZIONALNI_H

#include "Oblik.h"

class TroDimenzionalni:public Oblik{
public:
    TroDimenzionalni(const char* ime);
    ~TroDimenzionalni();
    static int getBr();
private:
    inline static int br = 0;
};

#endif
