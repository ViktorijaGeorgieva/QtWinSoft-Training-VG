/*Да се најде обиколката и плоштината на правилен n-аголник.*/
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float d;
    float P, L;

    printf("Kolku strani ima n-agolnikot?");
    scanf("%d", &n);
    printf("Dolzina na strana:");
    scanf("%f", &d);
    P = ((n * d * d) / (4 * tan(3.14 / n)));
    L = n * d;
    printf("Plostina na %d-agolnikot e %.2f\n", n, P);
    printf("Perimetarot na %d-agolnikot e %.2f\n", n, L);
    return 0;
}
