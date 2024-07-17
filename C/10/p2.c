/*Да се модифицира програмот за делење карти така да по мешањето подели 5 карти од рака за покер. Да се одреди дали раката содржи:
а) пар.
б) два пара
в) трилинг (пр. три десетки)
г) четири карти од ист број (пр. четири асови)
д) боја (сите пет карти да се од иста боја, на пр, детелина)
ѓ) кента (5 подредени карти од иста боја, пр. 3,4,5,6,7 срце)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototipovi */
void meshaj( int wDeck[][ 13 ] );
int deli( const int wDeck[][ 13 ], const char *wFace[], const char *wSuit[] );
int proveri(int redici[5], int koloni[5]);

int main()
{
    /* inicijaliziraj ja nizata na boi */
    const char *boja[ 4 ] = { "Srce", "Karo", "List", "Detelina" };

    /* inicijaliziraj ja nizata na brojki */
    const char *brojka[ 13 ] = { "As", "Dva", "Tri", "Chetiri", "Pet", "Shest", "Sedum", "Osum", "Devet", "Deset", "Dzandar", "Dama", "Pop" };

    /* inicijaliziraj niza na spil */
    int spil[ 4 ][ 13 ] = { 0 };

    srand( time( 0 ) ); /* generator na sluchajni broevi */

    meshaj( spil );
    deli( spil, brojka, boja );

    return 0; /* uspeshen kraj */

} /* kraj main */

/* meshaj gi kartite vo shpilot */
void meshaj( int wDeck[][ 13 ] )
{
    int row;    /* broj na red */
    int column; /* broj na kolona */
    int card;   /* brojach */

    /* za sekoja od 52-te karti,
   odberi sluchajno mesto vo shpilot */
    for ( card = 1; card <= 52; card++ ) {

        /* biraj nova sluchajna lokacija dodeka ne najdesh
      slobodno mesto */
        do {
            row = rand() % 4;
            column = rand() % 13;
        } while( wDeck[ row ][ column ] != 0 ); /* kraj do...while */

        /* pojtavi ja kartata na izbranoto mesto vo spilot */
        wDeck[ row ][ column ] = card;
    } /* kraj for */
} /* kraj na funkcijata meshaj */

/* deli gi kartite vo shpilot */
int deli( const int wDeck[][ 13 ], const char *wFace[], const char *wSuit[] )
{
    int card;   /* brojach na karti */
    int row;    /* brojach na redovi */
    int column; /* brojach na koloni */
    int i = 0;
    int redici[5], koloni[5];


    /* podeli ja sekoja od 52-te karti */
    for ( card = 1; card <= 5; card++ ) {

        /* pomini niz redovite na wDeck */
        for ( row = 0; row <= 3; row++ ) {

            /* pomini niz kolonite na wDeck za tekovniot red */
            for ( column = 0; column <= 12; column++ ) {

                /* ako mestoto ja sodrzhi tekovnata karta, prikazhi ja kartata */
                if ( wDeck[ row ][ column ] == card ) {
                    printf( "%s %s%c", wFace[ column ], wSuit[ row ], card == 5 ? '\n' : ' ' );
                    redici[i] = row;
                    koloni[i] = column;
                    i++;
                } /* kraj if */
            } /* kraj for */
        } /* kraj for */
    } /* kraj for */
    return proveri(redici, koloni);
} /* kraj na funkcijata deli */

int proveri(int redici[5], int koloni[5]){
    int i, j, count = 1, straight = 0, max = 1, flag = 0;
    int suitCount[4] = {0};
    int faceCount[13] = {0};
    for (i = 0; i < 5; i++)
    {
        suitCount[redici[i]]++;
        faceCount[koloni[i]]++;
    }
    for (i = 0; i < 13; i++)
    {
        if (faceCount[i] > max)
        {
            max = faceCount[i];
        }
        if (faceCount[i] == 2)
        {
            flag++;
        }
    }
    for (i = 0; i < 5; i++)
    {
        count = 1;
        for (j = i + 1; j < 5; j++)
        {
            if (koloni[i] == koloni[j])
                count++;
        }
        if (count > max)
        {
            max = count;
            flag++;
        }
    }
    count = 1;
    for (i = 0; i < 4; i++)
    {
        if (redici[i] == redici[i + 1])
            count++;
    }
    for (i = 0; i < 9; i++)
    {
        if (faceCount[i] == 1 && faceCount[i + 1] == 1 && faceCount[i + 2] == 1 && faceCount[i + 3] == 1 && faceCount[i + 4] == 1)
        {
            straight = 1;
            break;
        }
    }
    if (count == 5)
    {
        printf("Igracot ima boja\n");
        return 4;
    }
    else if (straight)
    {
        printf("Igracot ima kenta\n");
        return 6;
    }
    else if (max == 4)
    {
        printf("Igracot ima cetiri karti od ist broj\n");
        return 5;
    }
    else if (max == 3)
    {
        printf("Igracot ima triling\n");
        return 3;
    }
    else if (max == 2 && flag == 2)
    {
        printf("Igracot ima dva para\n");
        return 2;
    }
    else if (max == 2)
    {
        printf("Igracot ima par\n");
        return 1;
    }
    else
    {
        printf("Igracot nema nishto\n");
        return 0;
    }
}
