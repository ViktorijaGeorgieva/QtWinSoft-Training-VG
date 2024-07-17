/*Да се напише програма која служи како генератор на телефонски броеви. Знаеме дека полесно се паметат поими од броеви, па така некои од компаниите
 * имаат телефонски броеви кои ја означуваат дејноста или името на компанијата.
Нека ни се подредени буквите на следниот начин:
Цифра	Буква
2	ABC
3	DEF
4	GHI
5	JKL
6	MNO
7	PQR
8	STU
9	VWX
0	YZ
а) За даден седумбуквен стринг да се изгенерира бројот на телефон. Пример: “TELEKOM” = 8353566
б) За даден седмоцифрен број да се изгенерираат што поголем број на стрингови. Да се внимава дека 0 има само две букви.
*/
#include <stdio.h>
#include <string.h>

char odBukvaVoCifra(char bukva) {
    switch (bukva) {
    case 'A': case 'B': case 'C': return '2';
    case 'D': case 'E': case 'F': return '3';
    case 'G': case 'H': case 'I': return '4';
    case 'J': case 'K': case 'L': return '5';
    case 'M': case 'N': case 'O': return '6';
    case 'P': case 'Q': case 'R': return '7';
    case 'S': case 'T': case 'U': return '8';
    case 'V': case 'W': case 'X': return '9';
    case 'Y': case 'Z': return '0';
    default: return '\0';
    }
}

void odStringVoTelefonskiBroj(char *input) {
    int i;
    for (i = 0; i < 7; i++) {
        printf("%c", odBukvaVoCifra(input[i]));
    }
    printf("\n");
}

void generirajStringovi(char *cifri, char *current, int pos) {
    int i;
    char *niza[] = {"YZ", "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX"};

    if (pos == 7) {
        printf("%s\n", current);
        return;
    }

    int cifra = cifri[pos] - '0' - 1;
    for (i = 0; niza[cifra][i]; i++) {
        current[pos] = niza[cifra][i];
        generirajStringovi(cifri, current, pos + 1);
    }
}

void generirajStringoviOdTelefonskiBroj(char *cifri) {
    char current[8] = {0};
    generirajStringovi(cifri, current, 0);
}

int main() {
    int izbor;
    char input[8];

    while (1) {
        printf("1 - Generiraj telefonski broj od string\n");
        printf("2 - Generiraj stringovi od telefonski broj\n");
        printf("0 - Kraj\n");
        scanf("%d", &izbor);
        if (izbor == 0) {
            break;
        }
        printf("Vnesi 7 karakteri: ");
        scanf("%s", input);

        switch (izbor) {
        case 1:
            odStringVoTelefonskiBroj(input);
            break;
        case 2:
            generirajStringoviOdTelefonskiBroj(input);
            break;
        default:
            break;
        }
    }

    return 0;
}

