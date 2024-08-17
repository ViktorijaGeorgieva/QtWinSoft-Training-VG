/*Напиши програма која содржи class template Array со која може да се инстанцира поле од било кој тип. Класата треба да содржи функции членки за
 * сместување и преземање на вредност на елемент од полето. Да се демонстрира создавање на објекти за int и double тип.*/
#include <iostream>

using namespace std;

template<class T>
class Array{
public:
    Array(int = 3);
    void postaviVrednosti();
    void pecatenje() const;
    T getElement(int) const;
    void setElement(int, T);
private:
    int n;
    T* ptr;
};

template<class T>
Array<T>::Array(int n){
    this->n = (n > 0) ? n : 3;
    ptr = new T[3];
}

template<class T>
void Array<T>::postaviVrednosti(){
    for(int i = 0; i < n; i++){
        cout<<"Vnesi element:";
        cin>>ptr[i];
    }
}

template<class T>
void Array<T>::pecatenje() const{
    for(int i = 0; i < n; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
T Array<T>::getElement(int index) const{
    if(index > n || index < 1)
        return 0;
    return ptr[index - 1];
}

template<class T>
void Array<T>::setElement(int index, T val){
    if(index > n || index < 1)
        return;
    cout<<ptr[index - 1]<<" e zamenet so "<<val<<endl;
    ptr[index - 1] = val;
}

int main()
{
    int intN, doubleN;
    cout<<"Vnesi dolzini na nizite:";
    cin>>intN>>doubleN;
    Array<int> arrayInt(intN);
    Array<double> arrayDouble(doubleN);
    arrayInt.postaviVrednosti();
    arrayDouble.postaviVrednosti();
    arrayInt.setElement(1, 6);
    arrayDouble.setElement(3, 4.6);
    arrayInt.pecatenje();
    arrayDouble.pecatenje();

    return 0;
}
