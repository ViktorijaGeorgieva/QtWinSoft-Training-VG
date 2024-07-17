/*Да се најдат совршените броеви помали од природниот број n.
*/
#include <stdio.h>

int sovrshenBroj(int n);

int main()
{
    int n, i;
    printf("Vnesi broj:");
    scanf("%d", &n);
    sovrshenBroj(n);
    printf("Sovrsheni broevi pomali od %d se: ", n);
    for(i = 2; i < n; i++){
        if(sovrshenBroj(i)){
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

int sovrshenBroj(int n){
    int i, suma = 1;

    for(i = 2;  i * i <= n; i++){
        if(n % i == 0){
            if(i * i != n){
                suma += i + n / i;
            } else{
                suma += i;
            }
        }
    }
    return suma == n && n != 1;
}
