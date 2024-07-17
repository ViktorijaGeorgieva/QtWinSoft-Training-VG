/*Да се најдат природните броеви во интервалот [n1,n2], кои се деливи со сво-јот спротивен број.*/
#include <stdio.h>

int sprotivenBroj(int n);

int main()
{
    int n1, n2, i;
    printf("Vnesi interval:");
    scanf("%d %d", &n1, &n2);
    printf("Broevi koi se delivi so svojot sprotiven broj:");
    for(i = n1; i <= n2; i++){
        if(i % sprotivenBroj(i) == 0){
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

int sprotivenBroj(int n){
    int sprotiven = 0;
    while (n != 0) {
        sprotiven = sprotiven * 10 + n % 10;
        n /= 10;
    }
    return sprotiven;
}
