// Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde struktura projekcija_st sadrži sledeća polja:

// Skraćena oznaka grada (jedna reč, tačno 2 karaktera)
// Naziv bioskopa (jedna reč, do 10 karaktera)
// Naziv filma (jedna reč, do 8 karaktera)
// Naziv žanra (jedna reč, do 9 karaktera)
// Cena ulaznice (pozitivan realan broj)
// Naravno, struktura projekcija_st sadrži i polja potrebna za pravilno formiranje binarnog stabla.

// Na osnovu zadatog grada grad i žanra zanr iz formiranog binarnog stabla upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture projekcija_st:

// Skraćena oznaka grada (koristiti "%2s" format specifikator)
// Naziv bioskopa (koristiti "%-10s" format specifikator)
// Naziv filma (koristiti "%-8s" format specifikator)
// Naziv žanra (koristiti "%-9s" format specifikator)
// Cena ulaznice (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator)
// i potom u istu izlaznu datoteku upisati informaciju koja je projekcija najpovoljnija za zadati grad i žanr.

// Primer poziva:

// ./povoljne_ulaznice NS Animated projekcije.txt analiza.txt

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct projekcija_st {
    char OZNAKA_GRADA[2+1];
    char NAZIV_BIOSKOPA[10+1];
    char NAZIV_FILMA[8+1];
    char NAZIV_ZANRA[9+1];
    double CENA_ULAZNICE;

    struct projekcija_st* LEVI;
    struct projekcija_st* DESNI;
};

typedef struct projekcija_st PROJEKCIJA;

FILE* safe_fopen(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Greska pri otvaranju datoteka, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

void inicijalizuj_glavu(PROJEKCIJA** projekcija) {
    *projekcija = NULL;
}

PROJEKCIJA* inicijalizuj_projekciju(char* OZNAKA, char* BIOSKOP, char* FILM, char* ZANR, double CENA) {
    PROJEKCIJA* projekcija = (PROJEKCIJA*)malloc(sizeof(PROJEKCIJA));

    if(projekcija == NULL) {
        printf("Greska pri alociranju memorije, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(projekcija->OZNAKA_GRADA, OZNAKA);
    strcpy(projekcija->NAZIV_BIOSKOPA, BIOSKOP);
    strcpy(projekcija->NAZIV_FILMA, FILM);
    strcpy(projekcija->NAZIV_ZANRA, ZANR);
    projekcija->CENA_ULAZNICE = CENA;

    projekcija->LEVI    = NULL;
    projekcija->DESNI   = NULL;

    return projekcija;
}

void ubaci_u_listu(PROJEKCIJA* projekcija, PROJEKCIJA** glava) {
    if(*glava == NULL) {
        *glava = projekcija;
        return;
    } else if(projekcija->CENA_ULAZNICE <= (*glava)->CENA_ULAZNICE) {
        ubaci_u_listu(projekcija, &((*glava)->LEVI));
    } else {
        ubaci_u_listu(projekcija, &((*glava)->DESNI));
    }
}

void citaj_iz_ulaznog_fajla(FILE* fajl, PROJEKCIJA** glava) {

    char OZNAKA_GRADA[2+1];
    char NAZIV_BIOSKOPA[10+1];
    char NAZIV_FILMA[8+1];
    char NAZIV_ZANRA[9+1];
    double CENA_ULAZNICE;

    while(fscanf(fajl, "%s %s %s %s %lf", OZNAKA_GRADA, NAZIV_BIOSKOPA, NAZIV_FILMA, NAZIV_ZANRA, &CENA_ULAZNICE) != EOF) {
        PROJEKCIJA* projekcija = inicijalizuj_projekciju(OZNAKA_GRADA, NAZIV_BIOSKOPA, NAZIV_FILMA, NAZIV_ZANRA, CENA_ULAZNICE);
        ubaci_u_listu(projekcija, glava);
    }
}

void ispisi_binarno_stablo_u_konzolu(PROJEKCIJA* projekcija) {
    if(projekcija == NULL) {
        return;
    } else {
        ispisi_binarno_stablo_u_konzolu(projekcija->LEVI);
        printf("%2s %-10s %-8s %-9s %6.2f\n", 
        projekcija->OZNAKA_GRADA, 
        projekcija->NAZIV_BIOSKOPA, 
        projekcija->NAZIV_FILMA, 
        projekcija->NAZIV_ZANRA, 
        projekcija->CENA_ULAZNICE);
        ispisi_binarno_stablo_u_konzolu(projekcija->DESNI);
    }
}

void ispisi_binarno_stablo_u_fajl(FILE* fajl, PROJEKCIJA* projekcija) {
    if(projekcija == NULL) {
        return;
    } else {
        ispisi_binarno_stablo_u_fajl(fajl, projekcija->LEVI);
        fprintf(fajl, "%2s %-10s %-8s %-9s %6.2f\n", 
        projekcija->OZNAKA_GRADA, 
        projekcija->NAZIV_BIOSKOPA, 
        projekcija->NAZIV_FILMA, 
        projekcija->NAZIV_ZANRA, 
        projekcija->CENA_ULAZNICE);
        ispisi_binarno_stablo_u_fajl(fajl, projekcija->DESNI);
    }
}

void ispisi_najpovoljniju_projekciju_u_fajl(char* PRVI, char* DRUGI, FILE* fajl, PROJEKCIJA* projekcija) {
    if(projekcija == NULL) {
        fprintf(fajl, "\nNiko ne projektuje %s filmove u %s!", PRVI, DRUGI);
    } else {
        fprintf(fajl, "\nNajpovoljnija projekcija za %s filmove u %s je:\n%2s %6.2f", 
        PRVI,
        DRUGI,
        projekcija->NAZIV_FILMA, 
        projekcija->CENA_ULAZNICE);
    }
}

void pronadji_najpovoljniju_projekciju(char* GRAD, char* VRSTA, PROJEKCIJA* projekcija, PROJEKCIJA** tekuci) {

    if(projekcija == NULL) {
        return;
    }

    if((strcmp(projekcija->OZNAKA_GRADA, GRAD) == 0) && (strcmp(projekcija->NAZIV_ZANRA, VRSTA) == 0) && projekcija->CENA_ULAZNICE < (*tekuci)->CENA_ULAZNICE) {
        (*tekuci) = projekcija;
    }

    pronadji_najpovoljniju_projekciju(GRAD, VRSTA, projekcija->LEVI, &(*tekuci));
    pronadji_najpovoljniju_projekciju(GRAD, VRSTA, projekcija->DESNI, &(*tekuci));
}

void brisi_binarnu_stablo(PROJEKCIJA** projekcija) {
    while(*projekcija) {
        brisi_binarnu_stablo(&(*projekcija)->LEVI);
        brisi_binarnu_stablo(&(*projekcija)->DESNI);
        free(*projekcija);
        *projekcija = NULL;
    }
}

int main(int argn, char** argv) {

    system("cls");

    if(argn != 5) {
        printf("Greska pri pozivu programa, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz  = safe_fopen(argv[3], "r");
    FILE* izlaz = safe_fopen(argv[4], "w");

    PROJEKCIJA* glava;
    PROJEKCIJA* tekuci;
    inicijalizuj_glavu(&glava);
    citaj_iz_ulaznog_fajla(ulaz, &glava);
    //ispisi_binarno_stablo_u_konzolu(glava);
    tekuci = glava;
    pronadji_najpovoljniju_projekciju(argv[1], argv[2], glava->LEVI, &tekuci);

    ispisi_binarno_stablo_u_fajl(izlaz, glava);

    if(tekuci == glava) {
        if((strcmp(glava->OZNAKA_GRADA, argv[1]) != 0) || (strcmp(glava->NAZIV_ZANRA, argv[2]) != 0))
           tekuci = NULL;
    }

    ispisi_najpovoljniju_projekciju_u_fajl(argv[2], argv[1], izlaz, tekuci);

    free(tekuci);
    brisi_binarnu_stablo(&glava);

    fclose(ulaz);
    fclose(izlaz);

    return EXIT_SUCCESS;
}