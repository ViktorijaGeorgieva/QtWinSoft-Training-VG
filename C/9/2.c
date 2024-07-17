/*Да се реши систем од три равенки со три непознати.*/
#include <stdio.h>

void reshiSistemOdRavenki(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3);

int main()
{
    float a1, b1, c1, d1;
    float a2, b2, c2, d2;
    float a3, b3, c3, d3;

    printf("Vnesi gi vrednostite na a1, b1, c1 i d1:");
    scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
    printf("Vnesi gi vrednostite na a2, b2, c2 i d2:");
    scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
    printf("Vnesi gi vrednostite na a3, b3, c3 i d3:");
    scanf("%f %f %f %f", &a3, &b3, &c3, &d3);
    reshiSistemOdRavenki(a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3);

    return 0;
}

void reshiSistemOdRavenki(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3){
    float D, Dx, Dy, Dz;

    D = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);

    if (D == 0) {
        printf("Nema reshenie.\n");
    } else {
        Dx = d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);
        Dy = a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);
        Dz = a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);

        float x = Dx / D;
        float y = Dy / D;
        float z = Dz / D;

        printf("x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
    }
}
