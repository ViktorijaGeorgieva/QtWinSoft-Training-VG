/*Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе карактер ‘n’.
Пример:
          Vnesi broj: 6
          Ushte? (d/n): d
          Vnesi broj: 7
          Ushte? (d/n): d
          Vnesi broj: 3
          Ushte? (d/n): n
                  Sumata e 16
*/
#include <stdio.h>

int main()
{
    int sum = 0, num;
    char ch = 'd';
    while(ch == 'd'){
        printf("Vnesi broj:");
        scanf("%d", &num);
        sum += num;
        printf("Ushte? (d/n):");
        scanf(" %c", &ch);
        if(ch == 'n')
            break;
    }
    printf("Sumata e %d\n", sum);
    return 0;
}
