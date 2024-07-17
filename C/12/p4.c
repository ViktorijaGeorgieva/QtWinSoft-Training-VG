/*Да се напише програм кој дефинира тип vraboten, кој има полиња за ID, име, презиме, возраст, пол, брачна состојба, кредибилност (цел број од 0-100
 * кој означува кредитна историја, што поголем број, тоа бил вработениот поуспешен во враќање кредити), адреса, тековна плата и поранешна плата.

Да се овозможи внесување на повеќе вработени во низа и да се направат 3 сортирања (sort_kred, sort_tekovnaPlata, sort_minataPlata) по кредибилност,
по тековна и по поранешна плата.

Да се направи и функција koregiraj_vraboten која овозможува предефинирање на податоците за еден вработен внесен преку неговиот ID.

Да се направи и функција koregiraj_kredibilnost која за сите вработени ја корегира нивната кредибилност на следниот начин:
ако тековната плата им е поголема од претходната, тогаш ја зголемува кредибилноста за 3 и ја изедначува тековната со поранешната плата,
ако тековната плата е помала од претходната, тогаш ја намалува кредибилноста за 3 и ја изедначува тековната од поранешната плата,
инаку ништо не менува за вработениот.

Да се обезбеди мени кое на корисникот на апликацијата ќе му овозможи која функција да ја повика. Може да има максимум 50 вработени, но корисникот на
апликацијата го внесува бројот на вработени кои сака да ги внесе, на почетоткот на користењето на апликацијата.
*/
#include <stdio.h>
#include <string.h>

#define MAX_VRABOTENI 50

typedef struct {
    int ID;
    char ime[50];
    char prezime[50];
    int vozrast;
    char pol;
    char bracnaSostojba[10];
    int kredibilnost; // 0-100
    char adresa[100];
    float tekovnaPlata;
    float minataPlata;
} vraboten;

void vnesiVraboteni(vraboten vraboteni[], int broj);
void sort_kred(vraboten vraboteni[], int broj);
void sort_tekovnaPlata(vraboten vraboteni[], int broj);
void sort_minataPlata(vraboten vraboteni[], int broj);
void koregiraj_vraboten(vraboten vraboteni[], int broj, int ID);
void koregiraj_kredibilnost(vraboten vraboteni[], int broj);

int main() {
    int ID, broj, izbor;

    printf("Vnesi broj na vraboteni: ");
    scanf("%d", &broj);

    if (broj > MAX_VRABOTENI) {
        printf("Moze da ima maksimum 50 vraboteni.\n");
        return 1;
    }

    vraboten vraboteni[broj];
    vnesiVraboteni(vraboteni, broj);

    while (1) {
        printf("\nMeni:\n");
        printf("1 - Sortiraj po kredibilnost\n");
        printf("2 - Sortiraj po tekovna plata\n");
        printf("3 - Sortiraj po minata plata\n");
        printf("4 - Koregiraj vraboten po ID\n");
        printf("5 - Koregiraj kredibilnost na site vraboteni\n");
        printf("0 - Kraj\n");
        printf("Izbor: ");
        scanf("%d", &izbor);

        switch (izbor) {
        case 1:
            sort_kred(vraboteni, broj);
            break;
        case 2:
            sort_tekovnaPlata(vraboteni, broj);
            break;
        case 3:
            sort_minataPlata(vraboteni, broj);
            break;
        case 4:
            printf("Vnesi ID na vraboteniot: ");
            scanf("%d", &ID);
            koregiraj_vraboten(vraboteni, broj, ID);
            break;
        case 5:
            koregiraj_kredibilnost(vraboteni, broj);
            break;
        case 0:
            return 0;
        default:
            printf("Izberi od 0 do 5.\n");
        }
    }

    return 0;
}

void vnesiVraboteni(vraboten vraboteni[], int broj) {
    int i;
    for (i = 0; i < broj; i++) {
        printf("Vnesi podatoci za vraboten %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &vraboteni[i].ID);
        printf("Ime: ");
        scanf("%s", vraboteni[i].ime);
        printf("Prezime: ");
        scanf("%s", vraboteni[i].prezime);
        printf("Vozrast: ");
        scanf("%d", &vraboteni[i].vozrast);
        printf("Pol: ");
        scanf(" %c", &vraboteni[i].pol);
        printf("Bracna sostojba: ");
        scanf("%s", vraboteni[i].bracnaSostojba);
        printf("Kredibilnost: ");
        scanf("%d", &vraboteni[i].kredibilnost);
        printf("Adresa: ");
        scanf(" %[^\n]%*c", vraboteni[i].adresa);
        printf("Tekovna plata: ");
        scanf("%f", &vraboteni[i].tekovnaPlata);
        printf("Minata plata: ");
        scanf("%f", &vraboteni[i].minataPlata);
    }
}

void sort_kred(vraboten vraboteni[], int broj) {
    int i, j;
    vraboten tmp;
    for (i = 0; i < broj - 1; i++) {
        for (j = i + 1; j < broj; j++) {
            if (vraboteni[i].kredibilnost < vraboteni[j].kredibilnost) {
                tmp = vraboteni[i];
                vraboteni[i] = vraboteni[j];
                vraboteni[j] = tmp;
            }
        }
    }
    printf("Sortirano po kredibilnost:\n");
    for (i = 0; i < broj; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Kredibilnost: %d\n", vraboteni[i].ID, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].kredibilnost);
    }
}

void sort_tekovnaPlata(vraboten vraboteni[], int broj) {
    int i, j;
    vraboten tmp;
    for (i = 0; i < broj - 1; i++) {
        for (j = i + 1; j < broj; j++) {
            if (vraboteni[i].tekovnaPlata < vraboteni[j].tekovnaPlata) {
                tmp = vraboteni[i];
                vraboteni[i] = vraboteni[j];
                vraboteni[j] = tmp;
            }
        }
    }
    printf("Sortirano po tekovna plata:\n");
    for (i = 0; i < broj; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Tekovna plata: %.2f\n", vraboteni[i].ID, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].tekovnaPlata);
    }
}

void sort_minataPlata(vraboten vraboteni[], int broj) {
    int i, j;
    vraboten tmp;
    for (i = 0; i < broj - 1; i++) {
        for (j = i + 1; j < broj; j++) {
            if (vraboteni[i].minataPlata < vraboteni[j].minataPlata) {
                tmp = vraboteni[i];
                vraboteni[i] = vraboteni[j];
                vraboteni[j] = tmp;
            }
        }
    }
    printf("Sortirano po minata plata:\n");
    for (i = 0; i < broj; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Minata plata: %.2f\n", vraboteni[i].ID, vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].minataPlata);
    }
}

void koregiraj_vraboten(vraboten vraboteni[], int broj, int ID) {
    int i;
    for (i = 0; i < broj; i++) {
        if (vraboteni[i].ID == ID) {
            printf("Koregiranje podatoci za vrabotenot so ID %d:\n", ID);
            printf("Novo ime: ");
            scanf("%s", vraboteni[i].ime);
            printf("Novo prezime: ");
            scanf("%s", vraboteni[i].prezime);
            printf("Nova vozrast: ");
            scanf("%d", &vraboteni[i].vozrast);
            printf("Nov pol: ");
            scanf(" %c", &vraboteni[i].pol);
            printf("Nova bracna sostojba: ");
            scanf("%s", vraboteni[i].bracnaSostojba);
            printf("Nova kredibilnost: ");
            scanf("%d", &vraboteni[i].kredibilnost);
            printf("Nova adresa: ");
            scanf(" %[^\n]%*c", vraboteni[i].adresa);
            printf("Nova tekovna plata: ");
            scanf("%f", &vraboteni[i].tekovnaPlata);
            printf("Nova minata plata: ");
            scanf("%f", &vraboteni[i].minataPlata);
            return;
        }
    }
    printf("Ne postoi vraboten so ID %d.\n", ID);
}

void koregiraj_kredibilnost(vraboten vraboteni[], int broj) {
    int i;
    for (i = 0; i < broj; i++) {
        if (vraboteni[i].tekovnaPlata > vraboteni[i].minataPlata) {
            vraboteni[i].kredibilnost += 3;
            vraboteni[i].minataPlata = vraboteni[i].tekovnaPlata;
        } else if (vraboteni[i].tekovnaPlata < vraboteni[i].minataPlata) {
            vraboteni[i].kredibilnost -= 3;
            vraboteni[i].minataPlata = vraboteni[i].tekovnaPlata;
        }
    }
    printf("Koregirana e kredibilnosta.\n");
}
