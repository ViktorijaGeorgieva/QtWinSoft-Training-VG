/*Да се најдат природните броеви чиј квадрат и куб (заедно) ги содржат сите цифри 0,1, 2, .. , 9 по еднаш.*/
#include <stdio.h>

int check(int squared, int cubed);

int main()
{
    int i;
    printf("Broevi cij kvadrat i kub (zaedno) gi sodrzat site cifri od 0 do 9 po ednas:");
    for(i = 0; i < 100000; i++){
        if(check(i * i, i * i * i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

int check(int squared, int cubed){
    int i, d;
    int niza[10] ={0};
    while(squared != 0){
        d = squared % 10;
        niza[d]++;
        squared /= 10;
    }
    while(cubed != 0){
        d = cubed % 10;
        niza[d]++;
        cubed /= 10;
    }
    for(i = 0; i < 10; i++){
        if(niza[i] != 1){
            return 0;
        }
    }
    return 1;
}
