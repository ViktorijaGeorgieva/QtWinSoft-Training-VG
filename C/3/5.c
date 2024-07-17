/*Напиши програма која внесува радиус на круг и испечатува негова плоштина и периметар. За вредност на пи да се земе 3.14.*/
#include <stdio.h>

int main()
{
    float radius;
    printf("Vnesi radius na krug\n");
    scanf("%f", &radius);
    printf("Plostina na krug so radius %f e %f\n", radius, radius * radius * 3.14);
    printf("Perimetar na krug so radius %f e %f\n", radius, 2 * radius + 3.14);
    return 0;
}
