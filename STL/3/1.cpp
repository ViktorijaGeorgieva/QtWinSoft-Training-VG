/*Напиши class template Zapis<T> кој содржи три приватни членки: x, y и z од тип Т. Креирај function template kontrolor кој ќе проверува дали збирот
 * на елементите x, y и z во Zapis надминува 10000. Напиши соодветна програма за демонстрација со инстанцирање на објекти од тип Zapis<int> и
 * Zapis<double>.*/
#include <iostream>

using namespace std;

template<class T>
class Zapis{
public:
    Zapis(T, T, T);
    T getX() const{
        return x;
    }
    T getY() const{
        return y;
    }
    T getZ() const{
        return z;
    }
private:
    T x;
    T y;
    T z;
};

template<class T>
Zapis<T>::Zapis(T x, T y, T z){
    this->x = x;
    this->y = y;
    this->z = z;
}

template<class T>
bool kontrolor(Zapis<T> zapis){
    if(zapis.getX() + zapis.getY() + zapis.getZ() > 10000)
        return true;
    else
        return false;
}

int main()
{
    Zapis<int> zapisInt(1400, 5700, 3000);
    Zapis<double> zapisDouble(100.61, 600.54, 32.16);
    if(kontrolor(zapisInt))
        cout<<"Zbirot na elementite od zapisInt e pogolem od 10000"<<endl;
    else
        cout<<"Zbirot na elementite od zapisInt ne e pogolem od 10000"<<endl;
    if(kontrolor(zapisDouble))
        cout<<"Zbirot na elementite od zapisDouble e pogolem od 10000"<<endl;
    else
        cout<<"Zbirot na elementite od zapisDouble ne e pogolem od 10000"<<endl;
    return 0;
}
