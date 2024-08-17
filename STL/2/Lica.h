#ifndef LICA_H
#define LICA_H

#include <string>

using namespace std;

template<class T>
class Lica{
public:
    Lica();
    Lica(string, long long, int, string, T);
    Lica<T> postavi();
    void pecatenje() const;
    string getImeIPrezime() const{
        return imeIPrezime;
    }
    long long getMaticenBroj() const{
        return maticenBroj;
    }
    int getVozrast() const{
        return vozrast;
    }
    string getAdresa() const{
        return adresa;
    }
    T getKod() const{
        return kod;
    }
private:
    string imeIPrezime;
    long long maticenBroj;
    int vozrast;
    string adresa;
    T kod;
};

#endif
