/*Да се открие и опише што работи следниот програм?*/
/*Ги поместува битовите налево 32 пати и брои колку пати најважниот бит е 1.
 * Ако збирот на битови е парен број печати 1, ако е непарен печати 0.*/
#include <stdio.h>

int misterija( unsigned bitovi );

int main()
{
    unsigned x;
    printf( "Vnesi cel broj: " );
    scanf( "%u", &x );
    printf( "Rezultatot e %d\n", misterija( x ) );
    return 0;
}

int misterija( unsigned bitovi )
{
    unsigned i;
    unsigned maska = 1 << 31;
    unsigned total = 0;

    for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
        if ( ( bitovi & maska ) == maska ) {
            total++;
        }
    }
    return !( total % 2 ) ? 1 : 0;
}

