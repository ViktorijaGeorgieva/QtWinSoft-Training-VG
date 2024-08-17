/*Преклопи го printArray така што ќе добие уште два целобројни аргументи lowSubscript и highSubscript. Повик на оваа функција треба да ги отпечати
 * елементите помеѓу lowSubscript и highSubscript. Ако нивните вредности излегуваат од димензиите на полето, printArray треба да врати 0, во
 * спротивно бројот на отпечатени елементи. Во main да се тестира функционирањето на двете верзии на printArray врз полињата a, b и c.*/
#include <iostream>

using namespace std;

template<class T>
void printArray(const T *arr, const int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void printArray(const T *arr, const int n, const int lowSubscript, const int highSubscript){
    if(lowSubscript <= 0 || lowSubscript > n || lowSubscript > highSubscript || highSubscript > n)
        cout<<"0"<<endl;
    else{
        for(int i = lowSubscript - 1; i < highSubscript; i++){
            cout<<arr[i];
        }
        cout<<endl;
        cout<<highSubscript - lowSubscript + 1<<endl;
    }
}

int main()
{
    const int aN = 6;
    const int bN = 9;
    const int cN = 12;
    int lowSubscript, highSubscript;
    int a[aN] = {1, 2, 3, 4, 5, 6};
    double b[bN] = {1.0, 1.1, 1.6, 2.3, 2.6, 3.1, 3.6, 4.2, 4.6};
    char c[cN] = "HELLO WORLD";
    cout<<"a:"<<endl;
    printArray(a, aN);
    cout<<"b:"<<endl;
    printArray(b, bN);
    cout<<"c:"<<endl;
    printArray(c, cN);
    cout<<"Vnesi lowSubscript i highSubscript za a:";
    cin>>lowSubscript>>highSubscript;
    cout<<"Elementite pomegju "<<lowSubscript<<" i "<<highSubscript<<" na a se:"<<endl;
    printArray(a, aN, lowSubscript, highSubscript);
    cout<<"Vnesi lowSubscript i highSubscript za b:";
    cin>>lowSubscript>>highSubscript;
    cout<<"Elementite pomegju "<<lowSubscript<<" i "<<highSubscript<<" na b se:"<<endl;
    printArray(b, bN, lowSubscript, highSubscript);
    cout<<"Vnesi lowSubscript i highSubscript za c:";
    cin>>lowSubscript>>highSubscript;
    cout<<"Elementite pomegju "<<lowSubscript<<" i "<<highSubscript<<" na c se:"<<endl;
    printArray(c, cN, lowSubscript, highSubscript);

    return 0;
}
