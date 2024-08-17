/*Напиши програма со која сите зборови од текстуална датотека со големина помала од 10 знаци ќе ги запише во друга текстуална датотека.*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string zbor, tekst;
    ofstream createReadFile("readFile.txt", ios::out);
    if(!createReadFile)
        exit(1);
    cout<<"Vnesi tekst:"<<endl;
    getline(cin, tekst);
    createReadFile<<tekst;
    createReadFile.close();
    ifstream readTxt("readFile.txt", ios::in);
    ofstream writeTxt("writeFile.txt", ios::out);
    if(!readTxt)
        exit(1);
    if(!writeTxt)
        exit(1);
    while(readTxt>>zbor){
        if(zbor.length() < 10)
            writeTxt<<zbor<<" ";
    }
    readTxt.close();
    writeTxt.close();

    return 0;
}
