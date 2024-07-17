/*За даден природен број n да се испечатат следниве фигури со користење на рекурзија.
n
n-1 n
n-2 n-1 n
...
1 2 3 ... n-2 n-1 n
...
n-2 n-1 n
n-1 n
n
*/
#include <stdio.h>

void pecatiRekurzivno(int start, int end);

int main() {
    int n;
    printf("Vnesi broj:");
    scanf("%d", &n);
    pecatiRekurzivno(n, n);
    return 0;
}

void pecatiRekurzivno(int start, int end) {
    int i;
    if (start < 1) {
        return;
    }
    for (i = start; i <= end; i++) {
        printf("%d ", i);
    }
    printf("\n");
    pecatiRekurzivno(start - 1, end);
    for (i = start; i <= end; i++) {
        printf("%d ", i);
    }
    printf("\n");
}
