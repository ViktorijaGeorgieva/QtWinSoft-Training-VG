/*Програмот p05_03.c преработи го така да колонската репрезентација на вредностите на депозитот за секоја година биде порамнет одлево.*/
#include <stdio.h>
#include <math.h>

int main()
{
    double amount;
    double principal = 1000.0;
    double rate = .05;
    int year;

    printf( "%4s%25s\n", "Godina", "Vrednost na depozitot" );

    for ( year = 1; year <= 10; year++ ) {
        amount = principal * pow( 1.0 + rate, year );
        printf( "%4d%13.2f\n", year, amount );
    }

    return 0;
}
