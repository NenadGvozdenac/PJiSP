// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura gorivo_st sadrži sledeća polja:

// skraćena oznaka grada (jedna reč, tačno 2 karaktera)
// tip goriva (jedna reč, do 10 karaktera)
// cena goriva (pozitivan realan broj)
// Naravno, struktura gorivo_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Na osnovu zadatog tipa goriva tip_goriva (gas, benzin ili dizel) iz formirane liste upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture gorivo_st:

// cena (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator)
// skraćena oznaka grada
// tip goriva
// i potom u istu izlaznu datoteku upisati informaciju koja je prosečna cena zadatog tipa goriva (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator).

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct gorivo_st {
    char GRAD[2+1];
    char TIP[10+1];
    double CENA;

    struct gorivo_st* SLEDECI;
};

typedef struct gorivo_st GORIVO;

FILE* file_open(char* naziv, char* mod) {
    
    FILE* fajl = fopen(naziv, mod);

    if(fajl == NULL) {
        printf("Greska pri otvaranju fajla.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

GORIVO* napravi_glavu() {
    GORIVO* glava = NULL;
    return glava;
}

GORIVO* inicijalizuj_gorivo(char* GRAD, char* TIP, double CENA) {

    GORIVO* cvor = (GORIVO*)malloc(sizeof(GORIVO));

    strcpy(cvor->GRAD, GRAD);
    strcpy(cvor->TIP, TIP);
    cvor->CENA = CENA;

    cvor->SLEDECI = NULL;
    
    return cvor;
}

void dodaj_gorivo_u_listu(GORIVO** glava, GORIVO* novi) {

    if((*glava) == NULL) {
        (*glava) = novi;
        return;
    }

    dodaj_gorivo_u_listu(&(*glava)->SLEDECI, novi);
}

void ucitaj_gorivo(FILE* fajl, GORIVO** glava) {

    GORIVO* temp = inicijalizuj_gorivo("", "", 0);

    while(fscanf(fajl, "%s %s %lf", temp->GRAD, temp->TIP, &(temp->CENA)) != EOF) {
        GORIVO* trenutni = inicijalizuj_gorivo(temp->GRAD, temp->TIP, temp->CENA);
        dodaj_gorivo_u_listu(glava, trenutni);
    }
}

void ispisi_goriva(GORIVO* glava) {

    while(glava) {

        printf("%s %s %lf\n", glava->GRAD, glava->TIP, glava->CENA);

        glava = glava->SLEDECI;

    }
}

int main(int argn, char** argv) {

    if(argn != 4) {
        printf("Greska pri unosu podataka, primer unosa: `./gorivo benzin cene.txt izvestaj.txt`\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz = file_open(argv[2], "r");
    FILE* izlaz = file_open(argv[3], "w");

    GORIVO* glava = napravi_glavu();
    ucitaj_gorivo(ulaz, &glava);
    ispisi_goriva(glava);

    fclose(ulaz);
    fclose(izlaz);

    return EXIT_SUCCESS;
}