/*Напиши програма која внесува 10 цели броеви и и ги доделува на функцијата paren која враќа 1 ако бројот е парен и 0 ако бројот не е парен.*/
#include <stdio.h>

int paren(int num);
int main()
{
    int i, num;
    for(i = 0; i <10; i++){
        scanf("%d", &num);
        printf("%d\n", paren(num));
    }
    return 0;
}

int paren(int num){
    if(num % 2 == 0)
        return 1;
    return 0;
}

