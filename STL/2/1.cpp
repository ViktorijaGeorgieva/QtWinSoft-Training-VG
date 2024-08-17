/*Напиши function template кој има еден параметризиран тип (T) и прифаќа четири аргументи: поле од тип T, почетен индекс, краен индекс и опциона,
 * почетна вредност. Функцијата трба да ја врати сумата на елементите во полето зададени со почетниот и крајниот индекс. За почетната вредност да се
 * употреби конструкторот на T.*/
#include <iostream>

using namespace std;

template<class T>
T suma(T* arr, int pocetenIndeks, int kraenIndeks, int n, T vrednost = T()){
    if(pocetenIndeks < 0 || kraenIndeks > n || pocetenIndeks > kraenIndeks)
        return 0;
    for(int i = pocetenIndeks; i <= kraenIndeks; i++){
        vrednost += arr[i];
    }
    return vrednost;
}

int main()
{
    int intN, doubleN;
    cout<<"Vnesi dolzini na nizite:";
    cin>>intN>>doubleN;
    int arrInt[intN];
    double arrDouble[doubleN];
    for(int i = 0; i < intN; i++){
        cout<<"Vnesi element:";
        cin>>arrInt[i];
    }
    for(int i = 0; i < doubleN; i++){
        cout<<"Vnesi element:";
        cin>>arrDouble[i];
    }
    cout<<"Suma na int:"<<suma(arrInt, 0, intN - 1, intN)<<endl;
    cout<<"Suma na double:"<<suma(arrDouble, 0, doubleN - 1, doubleN)<<endl;

    return 0;
}
