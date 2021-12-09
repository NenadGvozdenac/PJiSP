// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura kafa_st sadrži sledeća polja:

// naziv kafića (jedna reč, do 20 karaktera)
// vrsta kafe (jedna reč, do 20 karaktera)
// cena kafe (pozitivan realan broj)
// Naravno, struktura kafa_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Na osnovu zadate vrste kafe vrsta_kafe iz formirane liste upisati podatke na standardni izlaz (terminal), u sledećem rasporedu polja strukture kafa_st:

// cena (zaokružena na 2 decimale, koristiti „%6.2f” format specifikator)
// naziv vrste kafe
// naziv kafića
// i potom u na standardni izlaz ispisati informaciju koja je prosečna cena zadate vrste kafe (zaokružena na 2 decimale, koristiti „%6.2f” format specifikator).

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct kafa_st {

    char NAZIV[20+1];
    char VRSTA[20+1];
    double CENA;

    struct kafa_st* SLEDECE;
};

typedef struct kafa_st KAFIC;

FILE* safe_open(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Greska pri otvaranju fajla. Izlaz!\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

KAFIC* inicijalizuj_glavu() {
    KAFIC* glava = NULL;
    return glava;
}

KAFIC* inicijalizuj_glavu(char* naziv, char* vrsta, double cena) {

    KAFIC* cvor = (KAFIC*)malloc(sizeof(KAFIC));

    if(cvor == NULL) {
        printf("Greska. Nedovoljno memorije za alokaciju prostora. Izlaz!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(cvor->NAZIV, naziv);
    strcpy(cvor->VRSTA, vrsta);
    cvor->CENA = cena;

    cvor->SLEDECE = NULL;

    return cvor;
}

void citaj_iz_fajla(FILE* fajl, KAFIC** kafic) {

    KAFIC* kafa = inicijalizuj_kafic("", "", 0);

    while(fscanf(fajl, "%s %s %lf", kafa->NAZIV, kafa->VRSTA, &(kafa)->CENA) != EOF) {
        
    }

}

int main(int argn, char** argv) {

    if(argn != 3) {
        printf("Greska pri pokretanju programa. Izlaz!\n");
        exit(EXIT_FAILURE);
    }

    FILE* fajl = safe_open(argv[2], "r");
    
    KAFIC* glava = inicijalizuj_glavu();
    citaj_iz_fajla(fajl, &glava);

    return EXIT_SUCCESS;
}