#ifndef KOCKA_H
#define KOCKA_H

#include "TroDimenzionalni.h"

class Kocka:public TroDimenzionalni{
public:
    Kocka(const char* ime);
    static int getBr();
private:
    inline static int br = 0;
};

#endif
