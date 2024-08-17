/*Формирај deque d од цели броеви. Потоа формирај vector v од елементите на d, но во обратен редослед. */
#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    deque<int> deque;
    vector<int> vector;
    ostream_iterator<int> output(cout, " ");
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_back(4);
    deque.push_back(5);
    deque.push_back(6);
    deque.push_back(7);
    deque.push_back(8);
    deque.push_back(9);
    deque.push_back(10);

    cout<<"Deque:";
    copy(deque.begin(), deque.end(), output);
    for(int i = 0; i < deque.size(); i++){
        vector.push_back(deque[i]);
    }
    cout<<"Vector:";
    copy(vector.begin(), vector.end(), output);
    reverse(vector.begin(), vector.end());
    cout<<"Vector vo obraten redosled:";
    copy(vector.begin(), vector.end(), output);

    return 0;
}
