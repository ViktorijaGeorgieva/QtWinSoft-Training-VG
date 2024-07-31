#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

#include "Matrica.h"

Matrica::Matrica(int redovi, int koloni){
    this->redovi = (redovi > 0 ? redovi : 4);
    this->koloni = (koloni > 0 ? koloni : 4);
    ptr = new int[redovi * koloni];
    assert(ptr != 0);
    for(int i = 0; i < redovi; i++){
        for(int j = 0; j < koloni; j++){
            ptr[i * koloni + j] = 0;
        }
    }

}

Matrica::Matrica(const Matrica &matrica) : redovi(matrica.redovi), koloni(matrica.koloni){
    ptr = new int[redovi * koloni];
    assert(ptr != 0);
    for(int i = 0; i < matrica.redovi; i++){
        for(int j = 0; j < matrica.koloni; j++){
            ptr[i * koloni + j] = matrica.ptr[i * koloni + j];
        }
    }
}

Matrica::~Matrica(){
    delete [] ptr;
}

const Matrica &Matrica::operator=(const Matrica &matrica1){
    if(&matrica1 != this){
        if(redovi != matrica1.redovi || koloni != matrica1.koloni){
            delete [] ptr;
            redovi = matrica1.redovi;
            koloni = matrica1.koloni;
            ptr = new int[redovi * koloni];
            assert(ptr != 0);
        }
        for(int i = 0; i < redovi; i++){
            for(int j = 0; j < koloni; j++){
                ptr[i * koloni + j] = matrica1.ptr[i * koloni + j];
            }
        }
    }
    return *this;
}

bool Matrica::operator==(const Matrica &matrica1) const{
    if(redovi != matrica1.redovi || koloni != matrica1.koloni){
        return false;
    }
    for(int i = 0; i < redovi; i++){
        for(int j = 0; j < koloni; j++){
            if(ptr[i * koloni + j] != matrica1.ptr[i * koloni + j])
                return false;
        }
    }
    return true;
}

bool Matrica::operator!=(const Matrica &matrica1) const{
    if(redovi != matrica1.redovi || koloni != matrica1.koloni){
        return true;
    }
    for(int i = 0; i < redovi; i++){
        for(int j = 0; j < koloni; j++){
            if(ptr[i * koloni + j] != matrica1.ptr[i * koloni + j])
                return true;
        }
    }
    return false;
}

int &Matrica::operator[](int indeks){
    assert(0 <= indeks && indeks < redovi * koloni);
    return ptr[indeks];
}

const int &Matrica::operator[](int indeks) const{
    assert(0 <= indeks && indeks < redovi * koloni);
    return ptr[indeks];
}

Matrica Matrica::operator+(const Matrica &matrica) const{
    Matrica tmp(*this);
    if(redovi != matrica.redovi || koloni != matrica.koloni){
        return tmp;
    }else{
        tmp.redovi = redovi;
        tmp.koloni = koloni;
        for(int i = 0; i < redovi; i++){
            for(int j = 0; j < koloni; j++){
                tmp[i * koloni + j] = ptr[i * koloni + j] + matrica.ptr[i * matrica.koloni + j];
            }
        }
    }
    return tmp;
}

Matrica Matrica::operator-(const Matrica &matrica) const{
    Matrica tmp(*this);
    if(redovi != matrica.redovi || koloni != matrica.koloni){
        return tmp;
    }else{
        tmp.redovi = redovi;
        tmp.koloni = koloni;
        for(int i = 0; i < redovi; i++){
            for(int j = 0; j < koloni; j++){
                tmp[i * koloni + j] = ptr[i * koloni + j] - matrica.ptr[i * matrica.koloni + j];
            }
        }
    }
    return tmp;
}

Matrica Matrica::operator*(const Matrica &matrica) const{
    if(koloni != matrica.redovi){
        return *this;
    }else{
        Matrica tmp(redovi, matrica.koloni);
        for(int i = 0; i < redovi; i++){
            for(int j = 0; j < matrica.koloni; j++){
                for(int k = 0; k < koloni; k++){
                    tmp[i * matrica.koloni + j] += ptr[i * koloni + k] * matrica.ptr[k * matrica.koloni + j];
                }
            }
        }
        return tmp;
    }
}

Matrica Matrica::operator*(const int broj) const{
    Matrica tmp(redovi, koloni);
    for(int i = 0; i < redovi; i++){
        for(int j = 0; j < koloni; j++){
            tmp[i * koloni + j] = ptr[i * koloni + j] * broj;
        }
    }
    return tmp;
}

Matrica operator*(int broj, Matrica matrica){
    Matrica tmp(matrica.redovi, matrica.koloni);
    for(int i = 0; i < matrica.redovi; i++){
        for(int j = 0; j < matrica.koloni; j++){
            tmp[i * matrica.koloni + j] = matrica.ptr[i * matrica.koloni + j] * broj;
        }
    }
    return tmp;
}

istream &operator>>(istream &input, Matrica &matrica){
    for(int i = 0; i < matrica.redovi; i++){
        for(int j = 0; j < matrica.koloni; j++){
            input>>matrica.ptr[i * matrica.koloni + j];
        }
    }
    return input;
}

ostream &operator<<(ostream &output, const Matrica &matrica){
    for(int i = 0; i < matrica.redovi; i++){
        for(int j = 0; j < matrica.koloni; j++){
            output<<setw(5)<<matrica.ptr[i * matrica.koloni + j];
        }
        output<<endl;
    }
    return output;
}
