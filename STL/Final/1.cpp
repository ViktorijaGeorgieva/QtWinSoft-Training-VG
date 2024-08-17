/*Креирај class temlate Pole што реализира поле од било кој тип. Имплементирај function template max за определување на најголем елемент во полето.
 * Во main креирај полиња од int, char и string, пополни ги со по 5 произволни елементи и прикажи најголем елемент за секое поле. */
#include <iostream>
#include <string>

using namespace std;

template<class T>
class Pole{
public:
    Pole();
    void pecatenje() const;
    void setElement(T vrednostElement);
    T getElement(int indeks) const{
        return arr[indeks];
    }
    int getCounter() const{
        return counter;
    }
private:
    T arr[30];
    int counter;
};

template<class T>
Pole<T>::Pole():counter(0){}

template<class T>
void Pole<T>::pecatenje() const{
    for(int i = 0; i < counter; i++){
        cout<<arr[i]<<" ";
    }
}

template<class T>
void Pole<T>::setElement(T vrednostElement){
    arr[counter++] = vrednostElement;
}

template<class T>
T max(Pole<T> *arr){
    T max = arr->getElement(0);
    for(int i = 1; i < arr->getCounter(); i++){
        if(arr->getElement(i) > max)
            max = arr->getElement(i);
    }

    return max;
}

template<>
string max(Pole<string> *arr){
    string max = arr->getElement(0);
    for(int i = 0; i < arr->getCounter(); i++){
        if(arr->getElement(i).length() > max.length())
            max = arr->getElement(i);
    }

    return max;
}

int main()
{
    Pole<int> poleInt;
    Pole<char> poleChar;
    Pole<string> poleString;
    cout<<"Vnesi 5 celi broevi:";
    for(int i = 0; i < 5; i++){
        int tmp;
        cin>>tmp;
        poleInt.setElement(tmp);
    }
    cout<<"Vnesi 5 karakteri:";
    for(int i = 0; i < 5; i++){
        char tmp;
        cin>>tmp;
        poleChar.setElement(tmp);
    }
    cout<<"Vnesi 5 zborovi:";
    for(int i = 0; i < 5; i++){
        string tmp;
        cin>>tmp;
        poleString.setElement(tmp);
    }
    cout<<"Int:"<<endl;
    poleInt.pecatenje();
    cout<<endl;
    cout<<"Char:"<<endl;
    poleChar.pecatenje();
    cout<<endl;
    cout<<"String:"<<endl;
    poleString.pecatenje();
    cout<<endl;
    cout<<"Najgolem int element:"<<max(&poleInt)<<endl;
    cout<<"Najgolem char element:"<<max(&poleChar)<<endl;
    cout<<"Najgolem string element:"<<max(&poleString)<<endl;

    return 0;
}
