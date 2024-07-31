#include <iostream>

using namespace std;

#include "Datum.h"

Datum::Datum(int den, int mesec, int godina){
    if(den > 0 && mesec <= 12)
        this->mesec = mesec;
    else
        this->mesec = 1;
    if(godina > 2000 && godina < 2030)
        this->godina = godina;
    else
        this->godina = 2000;
    this->den = proverka(den);
}

int Datum::proverka(int den){
    static const int denovi[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(den > 0 && den <= denovi[this->mesec])
        return den;
    if(mesec == 2 && den == 29 && (godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0)))
        return den;
    return 1;
}

void Datum::pecatenje() const{
    cout<<den<<"/"<<mesec<<"/"<<godina<<endl;
}
