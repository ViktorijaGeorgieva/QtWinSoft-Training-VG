#ifndef MNOZESTVO_H
#define MNOZESTVO_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
class Mnozestvo{
    vector<T> elementi;
public:
    void dodadiElement(const T& element);
    void prikazuvanjeElementi() const;
    T najgolem() const;
    size_t brojElementi() const;
};

template<typename T>
void Mnozestvo<T>::dodadiElement(const T& element){
    if(find(elementi.begin(), elementi.end(), element) == elementi.end()){
        elementi.push_back(element);
    }else{
        cout<<"Elementot vekje postoi."<<endl;
    }
}

template<typename T>
void Mnozestvo<T>::prikazuvanjeElementi() const{
    for(const auto& element : elementi) {
        cout <<"Plostina: "<<element.plostina()<<endl;
    }
}

template<typename T>
T Mnozestvo<T>::najgolem() const{
    return *max_element(elementi.begin(), elementi.end(), [](const T& a, const T& b){
        return a.plostina() < b.plostina();
    });
}

template<typename T>
size_t Mnozestvo<T>::brojElementi() const{
    return elementi.size();
}

#endif
