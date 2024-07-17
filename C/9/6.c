/*Да се најдат природните броеви помали од n, чиј збир на кубовите на цифри-те е еднаков на самиот број.*/
#include <stdio.h>

void zbirKubovi(int n);

int main()
{
    int n;
    printf("Vnesi broj:");
    scanf("%d", &n);
    zbirKubovi(n);
    return 0;
}

void zbirKubovi(int n){
    int i, tmp, d, sum;
    printf("Broevi pomali od %d, cij zbir na kubovite na cifrite e ednakov na samiot broj se: ", n);
    for(i = 1; i < n; i++){
        sum = 0;
        tmp = i;
        while (tmp != 0) {
            d = tmp % 10;
            tmp /= 10;
            sum = sum + (d * d * d);
        }
        if(sum == i){
            printf("%d ", sum);
        }
    }
}
