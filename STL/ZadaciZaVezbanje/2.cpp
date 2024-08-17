/*Напиши програма за играње на играта ’бесилка’. Креирај класа која содржи char и bool за индикација дали знак веќе бил погоден. Одбери збор и вчитај
 * го во вектор со објекти од таа класа. Менувањето и прикажувањето на елементите од векторот изврши го со STL алгоритми. Играчот во циклус внесува
 * збор кој смее да се состои само од мали букви. Ако зборот содржи и други знаци програмата да фрли исклучок. За секој збор се прикажуваат знаците
 * што ги погодил и знак ’-’ за знаците што сеуште не ги погодил. Користи бројач на погодувања. Играчот победува ако го погоди зборот пред бројачот
 * да добие вредност 0.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

using namespace std;

#include "Bukva.h"

bool sodrziSamoMaliBukvi(string const &str){
    return all_of(str.begin(), str.end(), [](char const &c){
        return isalpha(c) && islower(c);
    });
}

int main()
{
    int counter;
    bool pogodil = true;
    string zbor = "besilka";
    if(!sodrziSamoMaliBukvi(zbor)){
        throw logic_error("Zborot smee da se sostoi samo od mali bukvi.");
    }
    cout<<"Vnesi broj na obidi za pogoduvanje na zborot so "<<zbor.length()<<" bukvi:"<<endl;
    cin>>counter;
    vector<Bukva> bukvi;
    ostream_iterator<Bukva> output(cout, " ");
    for(int i = 0; i < zbor.length(); i++){
        bukvi.push_back(Bukva(zbor.at(i)));
    }
    while(counter > 0){
        pogodil = true;
        cout<<"Ti preostanuvaat uste "<<counter<<" obidi."<<endl;
        copy(bukvi.begin(), bukvi.end(), output);
        cout<<endl;
        char tmp;
        cout<<"Vnesi bukva:"<<endl;
        cin>>tmp;
        for(auto &bukva:bukvi){
            if(bukva.getBukva() == tmp)
                bukva.setPogodenaBukva();
            if(!bukva.getPogodenaBukva())
                pogodil = false;
        }
        if(pogodil)
            break;
        counter--;
    }
    if(pogodil)
        cout<<"Go pogodi zborot "<<zbor;
    else
        cout<<"Ne go pogodi zborot "<<zbor;

    return 0;
}
