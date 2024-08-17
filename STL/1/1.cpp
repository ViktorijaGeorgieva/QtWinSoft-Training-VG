/*Напиши function template за сортирање и програма во која се врши внесување, сортирање и печатење на поле од int елементи и поле од double 
 * елементи. Може да се користи било кој алгоритам за сортирање. */
#include <iostream>

using namespace std;

template<class T>
void sortiranje(T *arr, int const n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                T tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main()
{
    int brNaIntElementi, brNaDoubleElementi;

    cout<<"Vnesi broj na elementi vo int nizata:";
    cin>>brNaIntElementi;

    int arrInt[brNaIntElementi];

    for(int i = 0; i < brNaIntElementi; i++){
        cout<<"Vnesi element:";
        cin>>arrInt[i];
    }

    cout<<"Vnesi broj na elementi vo double nizata:";
    cin>>brNaDoubleElementi;

    double arrDouble[brNaDoubleElementi];

    for(int i = 0; i < brNaDoubleElementi; i++){
        cout<<"Vnesi element:";
        cin>>arrDouble[i];
    }

    sortiranje(arrInt, brNaIntElementi);
    sortiranje(arrDouble, brNaDoubleElementi);

    cout<<"Int nizata sortirana:";
    for(int i = 0; i < brNaIntElementi; i++){
        cout<<arrInt[i]<<" ";
    }

    cout<<"Double nizata sortirana:";
    for(int i = 0; i < brNaDoubleElementi; i++){
        cout<<arrDouble[i]<<" ";
    }

    return 0;
}


