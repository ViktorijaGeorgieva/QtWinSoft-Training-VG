/*Дадени се три листи од e-mail адреси. Некои адреси се појавуваат само во една од листите, а некои се повторуваат и во другите листи. Напиши
 * програма со која ќе се состави една листа во која ќе се содржат сите адреси по еднаш.*/
#include <iostream>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    list<string> l1, l2, l3;
    set<string> lista;

    l1.push_back("ana@gmail.com");
    l1.push_back("petko@gmail.com");
    l1.push_back("trajce@outlook.com");
    l1.push_back("boban@yahoo.com");

    l2.push_back("boban@yahoo.com");
    l2.push_back("marija@gmail.com");
    l2.push_back("teo@yahoo.com");

    l3.push_back("jovan@outlook.com");
    l3.push_back("vojdan@gmail.com");
    l3.push_back("marija@gmail.com");
    l3.push_back("petko@gmail.com");

    lista.insert(l1.begin(), l1.end());
    lista.insert(l2.begin(), l2.end());
    lista.insert(l3.begin(), l3.end());

    ostream_iterator<string> output(cout, " ");
    copy(lista.begin(), lista.end(), output);

    return 0;
}
