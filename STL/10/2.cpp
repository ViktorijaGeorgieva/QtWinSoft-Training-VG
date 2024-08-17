/*Креирај класа Garaza во која има Avtomobil што може да има проблеми со својот Motor. Употреби try блок во конструкторот на Garaza за фаќање на
 * исклучокот од Motor кога се иницијализира Avtomobil. Фрли друг исклучок од catch блокот во конструкторот на  Garaza и фати го во main( ).*/
#include <iostream>
#include <exception>

using namespace std;

class Motor{
public:
    Motor(){
        cout<<"Kreiranje motor."<<endl;
        throw 0;
    }
    ~Motor(){
        cout<<"Unistuvanje motor."<<endl;
    }
};

class Avtomobil:public Motor{
    public:
        Avtomobil():Motor(){
            cout<<"Kreiranje avtomobil."<<endl;
        }
        ~Avtomobil(){
            cout<<"Unistuvanje avtomobil."<<endl;
        }
};

class Garaza{
public:
    Garaza(){
        try{
            cout<<"Kreiranje garaza."<<endl;
            Avtomobil avtomobil;
        }catch(int){
            cout<<"Exception garaza."<<endl;
            throw exception();
        }
    }
    ~Garaza(){
        cout<<"Unistuvanje garaza."<<endl;
    }
};

int main()
{
    try{
        Garaza garaza;
    }catch(exception &e){
        cout<<"Exception main."<<endl;
    }

    return 0;
}
