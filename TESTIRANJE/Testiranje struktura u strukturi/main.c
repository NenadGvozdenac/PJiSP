#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Godina_rodjenja {

    int dan, mesec, godina;

} Godina_rodjenja;

typedef struct Ucenik {

    char ime[10], prezime[20];

    Godina_rodjenja godina;

} Ucenik;

Godina_rodjenja split(char string[]) {

    Godina_rodjenja godina;
    int j = 0, k = 0;

    int preskoci = 0;
    char niz_stringova[20][20];

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == '/')
            string[i] = ' ';
    }

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == ' ') {
            k = 0;
            j++;
            continue;
        }

        niz_stringova[j][k] = string[i];
        printf("ADDED %c\n", niz_stringova[j][k]);

        if(string[i] != ' ') {
            k++;
        }
    }

    printf("%s %s %s", niz_stringova[0], niz_stringova[1], niz_stringova[2]);

    return godina;
}

int main() {
    
    Ucenik ucenik;
    char godina[10];

    printf("Unesite ime: ");
    scanf("%s", ucenik.ime);

    printf("Unesite prezime: ");
    scanf("%s", ucenik.prezime);

    printf("Unesite dan/mesec/godinu: ");
    scanf("%s", godina);

    ucenik.godina = split(godina);

    getch();

    return 0;
}