/*Модифицирај го програмот p04_02.c така да наместо да е предефинирана вредноста на променливата counter, треба на корисникот да му се овозможи
 * тој да внесе колку ученици има во класот.*/
#include <stdio.h>

int main()
{
    int counter;
    int grade;
    int total;
    int average;
    int numStudents;

    total = 0;
    counter = 1;
    printf("Vnesi broj na ucenici vo klasot\n");
    scanf("%d", &numStudents);

    while (counter <= numStudents) {
        printf( "Vnesi ocena: " );
        scanf( "%d", &grade );
        total = total + grade;
        counter = counter + 1;
    }

    average = total / numStudents;

    printf( "Srednata vrednost na klasot e %d\n", average );

    return 0;
}
