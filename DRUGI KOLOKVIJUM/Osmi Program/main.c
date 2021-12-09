// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura igrica_st sadrži sledeća polja:

// naziv igre (jedna reč, do 20 karaktera)
// pozicija na rang listi (pozitivan ceo broj)
// da li je igra podržana na Windows operativnom sistemu (tačno jedaj karakter, + ako jeste, - ako nije)
// da li je igra podržana na MacOS operativnom sistemu (tačno jedaj karakter, + ako jeste, - ako nije)
// da li je igra podržana na Linux operativnom sistemu (tačno jedaj karakter, + ako jeste, - ako nije)
// Naravno, struktura igrica_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Igre ispisati na standardni izlaz sortirane po poziciji na rang listi (sortirati prilikom učitavanja u listu) u sledećem formatu:

// pozicija na rang listi
// naziv igre
// i potom ispisati na kojim operativnim sistemima je podržana najbolje rangirana igra.

// Primer poziva programa:

// ./a.out igre.txt

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct igrica_st {

    char NAZIV[20+1];
    int POZICIJA;
    char WINDOWS, MAC, LINUX;

    struct igrica_st* SLEDECE;
};

typedef struct igrica_st IGRICA;

FILE* safe_open(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);
    if(fajl == NULL) {
        printf("GRESKA MAMU TI JEBEM.");
        exit(EXIT_FAILURE);
    }
    return fajl;
}

IGRICA* inicijalizacija_igrice(char* NAZIV, int POZICIJA, char WINDOWS, char MAC, char LINUX) {

    IGRICA* cvor = (IGRICA*)malloc(sizeof(IGRICA));

    if(cvor == NULL) {
        printf("GRESKA MAMU TI JEBEM.");
        exit(EXIT_FAILURE);
    }

    strcpy(cvor->NAZIV, NAZIV);
    cvor->POZICIJA = POZICIJA;
    cvor->WINDOWS = WINDOWS;
    cvor->MAC = MAC;
    cvor->LINUX = LINUX;

    cvor->SLEDECE = NULL;

    return cvor;
}

void ubaci_u_listu(IGRICA** glava, IGRICA* novi) {

    if((*glava) == NULL) {
        (*glava) = novi;
        return;
    } else if((*glava)->POZICIJA > novi->POZICIJA) {
        novi->SLEDECE = *glava;
        (*glava) = novi;
        return;
    } else {
        IGRICA* tekuci = *glava;
        while(tekuci) {
            if(tekuci->SLEDECE == NULL) {
                tekuci->SLEDECE = novi;
                novi->SLEDECE = NULL;
                return;
            } else if(tekuci->SLEDECE->POZICIJA > novi->POZICIJA) {
                novi->SLEDECE = tekuci->SLEDECE;
                tekuci->SLEDECE = novi;
                return;
            }

            tekuci = tekuci->SLEDECE;
        }
    }
}

void citaj_iz_fajla(FILE* fajl, IGRICA** glava) {

    IGRICA* temp = inicijalizacija_igrice("", 0, '-', '-', '-');

    while(fscanf(fajl, "%s %i %c %c %c", temp->NAZIV, &(temp->POZICIJA), &(temp->WINDOWS), &(temp->MAC), &(temp->LINUX)) != EOF) {
        IGRICA* tekuci = inicijalizacija_igrice(temp->NAZIV, temp->POZICIJA, temp->WINDOWS, temp->MAC, temp->LINUX);
        ubaci_u_listu(glava, tekuci);
    }
}

void ispisi_u_konzolu(IGRICA* glava) {

    while(glava) {
        printf("%i %s\n",glava->POZICIJA, glava->NAZIV);
        glava = glava->SLEDECE;
    }

}

void ispisi_najbolju_igru(IGRICA* glava) {

    printf("Najbolje rangirana igrica je %s i podrzana je na sledecim operativnim sistemima: \n", glava->NAZIV);
    if(glava->WINDOWS == '+') {
        printf("Windows\n");
    }
    if(glava->MAC == '+') {
        printf("Mac\n");
    }
    if(glava->LINUX == '+') {
        printf("Linux\n");
    }

}

int main(int argn, char** argv) {
    system("cls");
    if(argn != 2) {
        printf("GRESKA MAMU TI JEBEM.");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz = safe_open(argv[1], "r");

    IGRICA* glava = NULL;

    citaj_iz_fajla(ulaz, &glava);
    ispisi_u_konzolu(glava);
    ispisi_najbolju_igru(glava);
    getch();
    return EXIT_SUCCESS;
}