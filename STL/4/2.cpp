/*Напиши програма што определува дали два збора се анаграми. Два збора се нарекуваат анаграми ако се состојат од исти букви (Пр. стакло и слатко).
 * Притоа користи vector. За споредба  на еднаквост на два вектори може да се користи: std::equal( v1.begin(), v1.end(), v2.begin() ); која враќа
 * bool вредност.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string zbor1, zbor2;
    cout<<"Vnesi zbor:";
    getline(cin, zbor1);
    cout<<"Vnesi zbor:";
    getline(cin, zbor2);
    if(zbor1.length() != zbor2.length()){
        cout<<"Zborovite ne se anagrami."<<endl;
        return 0;
    }
    vector<char> vector1(zbor1.begin(), zbor1.end());
    vector<char> vector2(zbor2.begin(), zbor2.end());
    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());
    if(equal(vector1.begin(), vector1.end(), vector2.begin()))
        cout<<"Zborovite se anagrami."<<endl;
    else
        cout<<"Zborovite ne se anagrami."<<endl;

    return 0;
}
