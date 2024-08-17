#include <iostream>
#include <cstring>

using namespace std;

#include "Mnozestvo.h"

template<class T>
int Mnozestvo<T>::n = 0;

template<class T>
Mnozestvo<T>::Mnozestvo(){}

template<class T>
void Mnozestvo<T>::dodadiElement(T vrednost){
    for(int i = 0; i < n; i++){
        if(vrednost == arr[i])
            return;
    }
    arr[n++] = vrednost;
}

template<class T>
void Mnozestvo<T>::pecatenje() const{
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" "<<endl;
    }
    cout<<endl;
}

template<class T>
T Mnozestvo<T>::najgolemElement(){
    if(n == 0)
        return 0;
    T najgolem = arr[0];
    for(int i = 1; i < n; i++){
        if(najgolem < arr[i])
            najgolem = arr[i];
    }
    return najgolem;
}

template<class T>
int Mnozestvo<T>::getN() const{
    return n;
}
