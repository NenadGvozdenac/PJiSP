// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura element_st sadrži sledeća polja:

// hemijski simbol (jedna reč, do 2 karaktera)
// ime (jedna reč, do 20 karaktera)
// atomska težina (prirodan broj)
// vrsta (jedna reč, do 20 karaktera)
// Naravno, struktura element_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Na osnovu zadate vrste hemijskog elementa vrsta iz formirane liste upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture element_st:

// hemijski simbol (koristiti "%-2s" format specifikator)
// atomska težina (koristiti "%3u" format specifikator)
// vrsta
// i potom u istu izlaznu datoteku upisati informaciju o najtežem hemijskom elementu koji pripada zadatoj vrsti.

// Primer poziva:

// ./najtezi metal uzorak_vino.txt analiza.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element_st {

    char HEMIJSKI_SIMBOL[2+1];
    char IME[20+1];
    int ATOMSKA_TEZINA;
    char VRSTA[20+1];

    struct element_st* SLEDECI;
};

typedef struct element_st ELEMENT;

FILE* safe_fopen(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Greska opet si zajebo.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

void inicijalizuj_glavu(ELEMENT** glava) {
    *glava = NULL;
}

ELEMENT* napravi_cvor(char* HEMIJSKI_SIMBOL, char* IME, int ATOMSKA_TEZINA, char* VRSTA) {
    ELEMENT* glava = (ELEMENT*)malloc(sizeof(ELEMENT));
    if(glava == NULL) {
        printf("Zajebo si memoriju druze\n");
        exit(EXIT_FAILURE);
    }

    strcpy(glava->HEMIJSKI_SIMBOL, HEMIJSKI_SIMBOL);
    strcpy(glava->IME, IME);
    glava->ATOMSKA_TEZINA = ATOMSKA_TEZINA;
    strcpy(glava->VRSTA, VRSTA);

    glava->SLEDECI = NULL;

    return glava;
}

void ubaci_u_listu(ELEMENT** glava, ELEMENT* novi) {
    if(*glava == NULL) {
        *glava = novi;
        return;
    }

    ubaci_u_listu(&((*glava)->SLEDECI), novi);
}

void citaj_iz_fajla(ELEMENT** glava, FILE* fajl) {

    char HEMIJSKI_SIMBOL[2+1];
    char IME[20+1];
    int ATOMSKA_TEZINA;
    char VRSTA[20+1];

    while(fscanf(fajl, "%s %s %d %s", HEMIJSKI_SIMBOL, IME, &ATOMSKA_TEZINA, VRSTA) != EOF) {
        ELEMENT* temporari = napravi_cvor(HEMIJSKI_SIMBOL, IME, ATOMSKA_TEZINA, VRSTA);
        ubaci_u_listu(glava, temporari);
    }
}

void ispisi_listu_u_konzolu(ELEMENT* glava) {
    while(glava != NULL) {
        printf("%-2s %3u %s\n", glava->HEMIJSKI_SIMBOL, glava->ATOMSKA_TEZINA, glava->VRSTA);
        glava = glava->SLEDECI;
    }
}

void ispisi_listu_u_fajl(FILE* fajl, ELEMENT* glava) {
    while(glava != NULL) {
        fprintf(fajl, "%-2s %3u %s\n", glava->HEMIJSKI_SIMBOL, glava->ATOMSKA_TEZINA, glava->VRSTA);
        glava = glava->SLEDECI;
    }
}

void izbrisi_listu(ELEMENT** glava) {

    ELEMENT* tekuci;

    while(*glava) {
        tekuci = *glava;
        *glava = (*glava)->SLEDECI;
        free(tekuci);
        tekuci = NULL;
    }
}

void ispisi_najtezi_element_u_fajl(FILE* fajl, ELEMENT* glava, ELEMENT** najtezi) {
    while(glava) {
        if(glava->ATOMSKA_TEZINA > (*najtezi)->ATOMSKA_TEZINA) {
            (*najtezi) = glava;
        }

        glava = glava->SLEDECI;
    }

    printf("Najtezi %s je %s (%s), atomska tezina %d.", (*najtezi)->VRSTA, (*najtezi)->IME, (*najtezi)->HEMIJSKI_SIMBOL, (*najtezi)->ATOMSKA_TEZINA);
    fprintf(fajl, "\nNajtezi %s je %s (%s), atomska tezina %d.", (*najtezi)->VRSTA, (*najtezi)->IME, (*najtezi)->HEMIJSKI_SIMBOL, (*najtezi)->ATOMSKA_TEZINA);
}

int main(int argn, char** argv) {
    if(argn != 4) {
        printf("Zajebo si.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz  = safe_fopen(argv[2], "r");
    FILE* izlaz = safe_fopen(argv[3], "w");

    ELEMENT* glava;
    inicijalizuj_glavu(&glava);
    citaj_iz_fajla(&glava, ulaz);
    ispisi_listu_u_konzolu(glava);
    ispisi_listu_u_fajl(izlaz, glava);
    ELEMENT* najtezi = glava;
    ispisi_najtezi_element_u_fajl(izlaz, glava, &najtezi);

    izbrisi_listu(&glava);

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}