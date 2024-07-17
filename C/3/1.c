/*Напиши програм кој како влез зема два цели броја и ги споредува. Потоа го испечатува поголемиот број проследен со коментарот e pogolem od и
 * го испечатува и помалиот број. Ако броевите се еднакви, програмот треба да испечати Broevite se ednakvi.*/
#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Vnesi dva celi broevi\n");
    scanf("%d %d", &num1, &num2);
    if(num1 > num2){
        printf("%d e pogolem od %d\n", num1, num2);
    } else if(num2 > num1){
        printf("%d e pogolem od %d\n", num2, num1);
    } else{
        printf("Broevite se ednakvi\n");
    }
    return 0;
}
