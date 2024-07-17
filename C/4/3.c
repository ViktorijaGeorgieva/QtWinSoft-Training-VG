/*Модифицирај го претходниот програм (вежба 2) така да просекот се пресметува како децимален број со точност од 3 децимали.*/
#include <stdio.h>

int main()
{
    int counter;
    int grade;
    int total;
    float average;
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

    average = (float) total / numStudents;

    printf( "Srednata vrednost na klasot e %.3f\n", average );
    return 0;
}
