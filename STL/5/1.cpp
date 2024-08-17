/*Напиши function template palindrom кој има параметар vector и враќа true ако векторот е палиндром, а false во спротивно. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<class T>
bool palindrom(vector<T> v){
    return equal(v.begin(), v.begin() + v.size() / 2, v.rbegin());
}

int main()
{
    string zbor;

    cout<<"Vnesi zbor:";
    cin>>zbor;

    vector<char> vec(zbor.begin(), zbor.end());

    if(palindrom(vec))
        cout<<zbor<<" e palindrom."<<endl;
    else
        cout<<zbor<<" ne e palindrom."<<endl;

    return 0;
}
