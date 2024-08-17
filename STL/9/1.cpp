/*Креирај два вектори со случаен број на елементи кој е во интервалот [1, 1000). Потоа ископирај го вториот вектор во првиот со copy. Претходно
 * провери дали првиот вектор има големина поголема или еднаква на големината на првиот. Ако не е, да се изврши фрлање на исклучок пред да се изврши
 * копирањето на векторот. Постапката да се повторува во циклус во кој е сместена try-catch секвенца. */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <exception>

using namespace std;

int slucaenBroj(){
    return rand() % 1000 + 1;
}

int main()
{
    srand(time(0));
    int br1 = slucaenBroj();
    int br2 = slucaenBroj();
    vector<int> v1(br1);
    vector<int> v2(br2);
    generate(v1.begin(), v1.end(), slucaenBroj);
    generate(v2.begin(), v2.end(), slucaenBroj);
    ostream_iterator<int> output(cout, " ");
    try{
        if(v2.size() < v1.size())
            throw exception();
        copy(v2.begin(), v2.begin() + v1.size(), v1.begin());
        cout<<"v1:"<<endl;
        copy(v1.begin(), v1.end(), output);
        cout<<endl;
        cout<<"v2:"<<endl;
        copy(v2.begin(), v2.end(), output);
        cout<<endl;
    }catch(exception &e){
        cout<<"v2 nema golemina pogolema ili ednakva na v1";
    }

    return 0;
}
