/*Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе -1.*/
#include <stdio.h>

int main()
{
    int sum = 0, num;
    while(1){
        printf("Vnesi broj\n");
        scanf("%d", &num);
        if(num == -1){
            break;
        }
        sum += num;
    }
    printf("Sumata e %d\n", sum);
    return 0;
}
