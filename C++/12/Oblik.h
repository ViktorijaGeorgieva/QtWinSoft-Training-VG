#ifndef OBLIK_H
#define OBLIK_H

#include <iostream>
#include <cstring>

class Oblik{
public:
    Oblik(const char* ime);
    ~Oblik();
    static int getBr();
    void pecatenje() const;
protected:
    char ime[10];
private:
    inline static int br = 0;
};

#endif
