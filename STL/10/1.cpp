/*Напиши програма која демонстрира дека ако е фрлен покажувач на создаден објект, објектот нема да биде уништен. */
#include <iostream>
#include <memory>
#include <exception>

using namespace std;

class Obj{
public:
    Obj(){
        cout<<"Kreiranje"<<endl;
        throw exception();
    }
    ~Obj(){
        cout<<"Unistuvanje"<<endl;
    }
};

int main()
{
    try{
        Obj obj;
    }catch(exception &e){
        cout<<"Ne se unistuva"<<endl;
    }

    return 0;
}
