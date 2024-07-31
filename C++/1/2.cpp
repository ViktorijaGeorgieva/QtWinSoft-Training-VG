/*Нaпиши С++ програм со две посебни функции кои едноставно ја триплираат вредноста на променливата count дефинирана во main. Овие функции се:
a.	Функцијата tripleCallByValue која предава копија од count, ја триплира нејзината вредност и ја враќа новата вредност
b.	Функцијата tripleCallByReference која ja предава count како референцен параметар, ја триплира самата променлива и ја враќа новата вредност на
count
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int tripleCallByValue(int);
void tripleCallByReference(int &);

int main()
{
    int count;
    cout<<"Vnesi ja vrednosta na count:";
    cin>>count;
    cout<<"Pred tripleCallByValue count e "<<count<<endl;
    cout<<"Od tripleCallByValue count e "<<tripleCallByValue(count)<<endl;
    cout<<"Po tripleCallByValue count e "<<count<<endl;
    cout<<"Pred tripleCallByReference count e "<<count<<endl;
    tripleCallByReference(count);
    cout<<"Po tripleCallByReference count e "<<count<<endl;
    return 0;
}

int tripleCallByValue(int count){
    return count * 3;
}

void tripleCallByReference(int &count){
    count *= 3;
}
