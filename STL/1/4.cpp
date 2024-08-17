/*Преклопи го function template-от printArray со non-template функција која печати поле од int во четири порамнети колони. */
#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
void printArray(const T *arr, const int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printArray(const int *arr, const int n){
    for(int i = 0; i < n; i++){
        cout<<setw(4)<<arr[i];
        if((i + 1) % 4 == 0)
            cout<<endl;
    }
    cout<<endl;
}

int main()
{
    const int aN = 6;
    const int bN = 9;
    const int cN = 12;
    int a[aN] = {1, 2, 3, 4, 5, 6};
    double b[bN] = {1.0, 1.1, 1.6, 2.3, 2.6, 3.1, 3.6, 4.2, 4.6};
    char c[cN] = "HELLO WORLD";
    int d[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    cout<<"a:"<<endl;
    printArray(a, aN);
    cout<<"b:"<<endl;
    printArray(b, bN);
    cout<<"c:"<<endl;
    printArray(c, cN);
    cout<<"d:"<<endl;
    printArray(d, 16);

    return 0;
}
