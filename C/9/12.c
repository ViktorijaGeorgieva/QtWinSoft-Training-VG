/*12.	Да се внесат два полинома со степени n m соодветно. Да се внесат нивните коефициенти и да се најде нивниот збир.*/
#include <stdio.h>

int main()
{
    int i, j, m, n, max;
    int polinom1[10]={0}, polinom2[10]={0}, zbir[10];
    printf("Vnesi go stepenot na prviot polinom\n");
    scanf("%d", &n);
    printf("Vnesi go stepenot na vtoriot polinom\n");
    scanf("%d", &m);
    printf("Vnesi gi koeficientite na prviot polinom\n");
    max = m;
    if(n > max)
    {
        max = n;
    }
    for(i = max - n; i < max; i++)
    {
        scanf("%d", &polinom1[i]);
    }
    printf("Vnesi gi koeficientite na vtoriot polinom\n");
    for(i = max - m; i < max; i++)
    {
        scanf("%d", &polinom2[i]);
    }


    for(i = 0; i < max; i++)
    {
        zbir[i] = polinom1[i] + polinom2[i];
    }
    for(i = 0, j = max; j > 0, i < max - 1; i++, j--)
    {
        printf("%dx^%d + ", zbir[i], j);
    }
    printf("%dx^%d\n", zbir[i], j);
    return 0;
}
