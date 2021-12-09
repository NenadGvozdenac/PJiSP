// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura pizza_st sadrži sledeća polja:

// Cena (prirodan broj)
// Skraćena oznaka države (jedna reč, tačno 3 karaktera)
// Skraćena oznaka grada (jedna reč, tačno 2 karaktera)
// Naziv pizze (jedna reč, do 20 karaktera)
// Naravno, struktura pizza_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Na osnovu zadate oznake države drzava i naziva pizze naziv_pizze iz formirane liste upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture pizza_st:

// Cena (koristiti "%4d" format specifikator)
// Skraćena oznaka države
// Skraćena oznaka grada
// Naziv pizze
// i potom u istu izlaznu datoteku upisati informaciju u koliko gradova se može naći pizza pod zadatim kriterijumima.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

struct pizza_st {

    int cena;
    char drzava[3+1];
    char grad[2+1];
    char naziv[20+1];

    struct pizza_st* sledeci;

};

typedef struct pizza_st PIZZA;

FILE* safe_open(char* NAZIV, char* MOD) {

    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        exit(EXIT_FAILURE);
    }

    return fajl;
}

PIZZA* inicijalizuj_cvor(int CENA, char* DRZAVA, char* GRAD, char* NAZIV) {

    PIZZA* pizza = (PIZZA*)malloc(sizeof(PIZZA));

    if(pizza == NULL) {
        printf("PROBLEM PRI KREIRANJU GLAVE LISTE, IZLAZ.\n");
        exit(EXIT_FAILURE);
    }

    pizza->cena = CENA;
    strcpy(pizza->drzava, DRZAVA);
    strcpy(pizza->grad, GRAD);
    strcpy(pizza->naziv, NAZIV);

    return pizza;
}

void read_from_file(FILE* FAJL, PIZZA** GLAVA, char* TRAZENA_DRZAVA, char* TRAZENA_PIZZA, int* BROJAC) {
    PIZZA* temp = inicijalizuj_cvor(0, "", "", "");
    PIZZA* pocetak_niza = (*GLAVA);

    while(fscanf(FAJL, "%d %s %s %s", &temp->cena, temp->drzava, temp->grad, temp->naziv) != EOF) {
        if(strcmp(TRAZENA_DRZAVA, temp->drzava) == 0 && strcmp(TRAZENA_PIZZA, temp->naziv) == 0)
            (*BROJAC)++;
        PIZZA* cvor = inicijalizuj_cvor(temp->cena, temp->drzava, temp->grad, temp->naziv);
        (*GLAVA)->sledeci = cvor;
        (*GLAVA) = cvor;
    }

    (*GLAVA)->sledeci = NULL;
    (*GLAVA) = pocetak_niza->sledeci;
}

void output_to_file(FILE* FAJL, PIZZA* GLAVA) {
    while(GLAVA) {
        fprintf(FAJL, "%4d %s %s %s\n", GLAVA->cena, GLAVA->drzava, GLAVA->grad, GLAVA->naziv);
        GLAVA = GLAVA->sledeci;
    }
}

void output_to_console(PIZZA* GLAVA) {
    while(GLAVA) {
        printf("%4d %s %s %s\n", GLAVA->cena, GLAVA->drzava, GLAVA->grad, GLAVA->naziv);
        GLAVA = GLAVA->sledeci;
    }
}

int main(int argn, char* argv[]) {

    if(argn != 5) {
        printf("Greska pri unosu. Primer unosa: ./zad SRB Capricciosa pizze.txt analiza.txt");
        exit(EXIT_FAILURE);
    }

    FILE* in = safe_open(argv[3], "r");
    FILE* out = safe_open(argv[4], "w");

    int brojac = 0;

    PIZZA* glava = inicijalizuj_cvor(0, "", "", "");

    read_from_file(in, &glava, argv[1], argv[2], &brojac);
    output_to_file(out, glava);
    output_to_console(glava);

    fprintf(out, "\ncount = %d", brojac);

    fclose(in);
    fclose(out);

    free(glava);

    return 0;
}