/*За текст внесен од тастатура прикажи ги сите зборови од кои се состои текстот по еднаш, во абецеден редослед. */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void podstringovi(string tekst, vector<string> &v);

int main()
{
    string tekst;
    cout<<"Vnesi tekst:";
    getline(cin, tekst);
    vector<string> vector;
    podstringovi(tekst, vector);
    sort(vector.begin(), vector.end());
    for(int i = 0; i < vector.size(); i++){
        cout<<vector[i]<<endl;
    }
    return 0;
}

void podstringovi(string tekst, vector<string> &v){
    int start = 0;
    string tmp;
    vector<char> vectorChar(tekst.begin(), tekst.end());
    for(int i = 0; i< vectorChar.size() - 1; i++){
        if(vectorChar[i]==' '){
            tmp = tekst.substr(start, i - start);
            if(find(v.begin(), v.end(), tmp) == v.end())
                v.push_back(tmp);
            start = i + 1;
        }
    }
    tmp = tekst.substr(start);
    if(find(v.begin(), v.end(), tmp) == v.end())
        v.push_back(tmp);
}
