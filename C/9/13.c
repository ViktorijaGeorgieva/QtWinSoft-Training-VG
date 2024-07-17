/*13.	Да се генерираат следниве дводимензионални полиња со m-редици и n-колони.
1	12	13			...
2	11	14			...
3	10	15			...
4	9	16			...
5	8	17			...
6	7	18	19		
*/
#include <stdio.h>

int main()
{
    int m, n, i, j, br = 1, odgoreNadolu = 1, matrica[50][50];
    printf("Vnesi m:");
    scanf("%d", &m);
    printf("Vnesi n:");
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        if (odgoreNadolu) {
            for (i = 0; i < m; i++) {
                matrica[i][j] = br;
                br++;
            }
            odgoreNadolu = 0;
        } else {
            for (i = m - 1; i >= 0; i--) {
                matrica[i][j] = br;
                br++;
            }
            odgoreNadolu = 1;
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }

    return 0;
}
