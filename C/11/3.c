/*Да се пронајдат на Интернет кодовите за бројки и букви во Морзеовата азбука. Да се напише програм кој чита текст фраза и ја дава нејзината
 * вредност во Морзеовата азбука. Да се направи и друга функција на која и се предава Морзеов текст, а треба како резултат да се добие текст
 * фраза во говорен јазик.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void odGovorenVoMorzeov(char* tekst);
void odMorzeovVoGovoren(char* tekst);

int main()
{
    int izbor;
    while(1)
    {
        printf("0 - Kraj\n"
               "1 - Od govoren vo Morzeov\n"
               "2 - Od Morzeov vo govoren\n");
        scanf("%d", &izbor);

        if (izbor == 0)
            break;

        if (izbor == 1)
        {
            char tekst[1000];
            printf("Vnesi tekst: ");
            scanf(" %[^\n]%*c", tekst);
            odGovorenVoMorzeov(tekst);
        }
        else if (izbor == 2)
        {
            char tekst[1000];
            printf("Vnesi tekst: ");
            scanf(" %[^\n]%*c", tekst);
            odMorzeovVoGovoren(tekst);
        }
    }

    printf("\n");
}

void odGovorenVoMorzeov(char* tekst)
{
    printf("Morzeov kod: ");
    while (1)
    {
        if (*tekst == '\0')
            break;

        char c = toupper(*tekst++);

        switch (c)
        {
        case 'A': printf(".- "); break;
        case 'B': printf("-... "); break;
        case 'C': printf("-.-. "); break;
        case 'D': printf("-.. "); break;
        case 'E': printf(". "); break;
        case 'F': printf("..-. "); break;
        case 'G': printf("--. "); break;
        case 'H': printf(".... "); break;
        case 'I': printf(".. "); break;
        case 'J': printf(".--- "); break;
        case 'K': printf("-.- "); break;
        case 'L': printf(".-.. "); break;
        case 'M': printf("-- "); break;
        case 'N': printf("-. "); break;
        case 'O': printf("--- "); break;
        case 'P': printf(".--. "); break;
        case 'Q': printf("--.- "); break;
        case 'R': printf(".-. "); break;
        case 'S': printf("... "); break;
        case 'T': printf("- "); break;
        case 'U': printf("..- "); break;
        case 'V': printf("...- "); break;
        case 'W': printf(".-- "); break;
        case 'X': printf("-..- "); break;
        case 'Y': printf("-.-- "); break;
        case 'Z': printf("--.. "); break;
        case '0': printf("----- "); break;
        case '1': printf(".---- "); break;
        case '2': printf("..--- "); break;
        case '3': printf("...-- "); break;
        case '4': printf("....- "); break;
        case '5': printf("..... "); break;
        case '6': printf("-.... "); break;
        case '7': printf("--... "); break;
        case '8': printf("---.. "); break;
        case '9': printf("----. "); break;
        case '.': printf(".-.-.- "); break;
        case ',': printf("--..-- "); break;
        case '!': printf("-.-.-- "); break;
        case '?': printf("..--.. "); break;
        case ' ': printf("---- "); break;
        }
    }
    printf("\n");
}

void odMorzeovVoGovoren(char* tekst)
{
    char* znak;

    znak = strtok(tekst, " ");

    while(znak != NULL)
    {
        if (strcmp(znak, ".-")      == 0) printf("A");
        else if (strcmp(znak, "-...")   == 0) printf("B");
        else if (strcmp(znak, "-.-.")   == 0) printf("C");
        else if (strcmp(znak, "-..")    == 0) printf("D");
        else if (strcmp(znak, ".")      == 0) printf("E");
        else if (strcmp(znak, "..-.")   == 0) printf("F");
        else if (strcmp(znak, "--.")    == 0) printf("G");
        else if (strcmp(znak, "....")   == 0) printf("H");
        else if (strcmp(znak, "..")     == 0) printf("I");
        else if (strcmp(znak, ".---")   == 0) printf("J");
        else if (strcmp(znak, "-.-")    == 0) printf("K");
        else if (strcmp(znak, ".-..")   == 0) printf("L");
        else if (strcmp(znak, "--")     == 0) printf("M");
        else if (strcmp(znak, "-.")     == 0) printf("N");
        else if (strcmp(znak, "---")    == 0) printf("O");
        else if (strcmp(znak, ".--.")   == 0) printf("P");
        else if (strcmp(znak, "--.-")   == 0) printf("Q");
        else if (strcmp(znak, ".-.")    == 0) printf("R");
        else if (strcmp(znak, "...")    == 0) printf("S");
        else if (strcmp(znak, "-")      == 0) printf("T");
        else if (strcmp(znak, "..-")    == 0) printf("U");
        else if (strcmp(znak, "...-")   == 0) printf("V");
        else if (strcmp(znak, ".--")    == 0) printf("W");
        else if (strcmp(znak, "-..-")   == 0) printf("X");
        else if (strcmp(znak, "-.--")   == 0) printf("Y");
        else if (strcmp(znak, "--..")   == 0) printf("Z");
        else if (strcmp(znak, "-----")  == 0) printf("0");
        else if (strcmp(znak, ".----")  == 0) printf("1");
        else if (strcmp(znak, "..---")  == 0) printf("2");
        else if (strcmp(znak, "...--")  == 0) printf("3");
        else if (strcmp(znak, "....-")  == 0) printf("4");
        else if (strcmp(znak, ".....")  == 0) printf("5");
        else if (strcmp(znak, "-....")  == 0) printf("6");
        else if (strcmp(znak, "--...")  == 0) printf("7");
        else if (strcmp(znak, "---..")  == 0) printf("8");
        else if (strcmp(znak, "----.")  == 0) printf("9");
        else if (strcmp(znak, ".-.-.-") == 0) printf(".");
        else if (strcmp(znak, "--..--") == 0) printf(",");
        else if (strcmp(znak, "-.-.--") == 0) printf("!");
        else if (strcmp(znak, "..--..") == 0) printf("?");
        else if (strcmp(znak, "----")   == 0) printf(" ");

        znak = strtok(NULL, " ");
    }
    printf("\n");
}
