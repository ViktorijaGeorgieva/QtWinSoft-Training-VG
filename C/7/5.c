/*Напиши итеративна верзија на функцијата за фибоначиеви броеви.*/
#include <stdio.h>

int fibonacci(int num);

int main()
{
    int num;
    printf("Vnesi cel broj:");
    scanf("%d", &num);
    printf("Fibonacci(%d): %d\n", num, fibonacci(num));

    return 0;
}

int fibonacci(int num){
    int i, fi, f1 = 0, f2 = 1;

    for(i = 2; i <= num; i++){
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
    }
    return f2;
}
