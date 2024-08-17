#ifndef MNOZESTVO_H
#define MNOZESTVO_H

template<class T>
class Mnozestvo{
public:
    Mnozestvo();
    void dodadiElement(T);
    void pecatenje() const;
    int getN() const;
    T najgolemElement();
private:
    T arr[50];
    static int n;
};

#endif
