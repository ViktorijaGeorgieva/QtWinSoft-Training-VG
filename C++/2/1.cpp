/*Напиши програм кој користи функциски урнек min за да го определи помалиот од двата аргументи. Тестирај го прогамот со цели броеви, реални
 * броеви и карактери.*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
T min(T value1, T value2);

int main()
{
    int int1, int2;

    cout<<"Vnesi dva celi broevi: ";
    cin>>int1>>int2;
    cout<<"Pomal e "<<min(int1, int2)<<endl;

    double double1, double2;

    cout<<"Vnesi dve double vrednosti: ";
    cin>>double1>>double2;
    cout<<"Pomal e "<<min(double1, double2)<<endl;

    char char1, char2;

    cout<<"Vnesi dva karakteri: ";
    cin>>char1>>char2;
    cout<<"Pomal e "<<min(char1, char2)<<endl;

    return 0;
}

template <typename T>
T min(T value1, T value2){
    if(value1 <= value2) return value1;
    else return value2;
}
