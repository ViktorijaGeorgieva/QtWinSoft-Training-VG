/*Во еден систем пристигнуваат процеси кои треба да бидат опслужени. Секој процес има идентификационен број и приоритет. Напиши прграма која за
 * внесена листа на процеси и приоритети ќе прикаже по кој редослед тие ќе бидат опслужени.*/
#include <iostream>
#include <queue>

using namespace std;

class Proces{
public:
    Proces(int, int);
    int getId() const{
        return id;
    }
    int getPrioritet() const{
        return prioritet;
    }
private:
    int id;
    int prioritet;
};

Proces::Proces(int id, int prioritet){
    this->id = id;
    this->prioritet = prioritet;
}

bool operator<(const Proces &p1, const Proces &p2){
    return p1.getPrioritet() < p2.getPrioritet();
}

int main()
{
    priority_queue<Proces> priorityQueue;

    priorityQueue.push(Proces(1, 6));
    priorityQueue.push(Proces(2, 65));
    priorityQueue.push(Proces(3, 48));
    priorityQueue.push(Proces(4, 98));

    while(!priorityQueue.empty()){
        Proces p = priorityQueue.top();
        cout<<"Proces id:"<<p.getId()<<", prioritet:"<<p.getPrioritet()<<endl;
        priorityQueue.pop();
    }

    return 0;
}
