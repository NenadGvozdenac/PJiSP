/*
    Iz zadate ulazne datoteka učitati podatke u jednostruko spregnutu listu, gde struktura meso_st sadrži sledeća polja:

    Skraćena oznaka grada (jedna reč, tačno 2 karaktera)
    Naziv vrste mesa (jedna reč, do 20 karaktera)
    Cena mesa po kilogramu (realan broj)
    Naravno, struktura meso_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

    Na osnovu zadate vrste mesa vrsta_mesa upisati podatke iz formirane liste u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture meso_st:

    Cena mesa po kilogramu (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator)
    Skraćena oznaka grada
    Naziv vrste mesa
    i potom u istu izlaznu datoteku upisati informaciju u kom gradu je zadata vrsta_mesa najpovoljnija.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

struct meso_st {

    char GRAD[2 + 1];
    char NAZIV_MESA[20 + 1];

    double CENA_MESA;

    struct meso_st* SLEDECE;
};

typedef struct meso_st MESO;

FILE* file_safeopen(char* naziv_fajla, char* mode) {

    FILE* file = fopen(naziv_fajla, mode);

    if(file == NULL) {
        printf("Greska pri otvaranju fajla %s. Izlaz.\n", naziv_fajla);
        exit(EXIT_FAILURE);
    }

    return file;

}

MESO* inicijalizuj_cvor(char* GRAD, char* NAZIV, double cena) {

    MESO* glava_cvor = (MESO*)malloc(sizeof(MESO));

    glava_cvor->CENA_MESA = cena;
    strcpy(glava_cvor->GRAD, GRAD);
    strcpy(glava_cvor->NAZIV_MESA, NAZIV);

    return glava_cvor;
}

MESO* read_from_input(FILE* input, char* meso, MESO* glava, int* najmanja) {

    MESO* temp = (MESO*)malloc(sizeof(MESO));
    MESO* pocetak = glava;
    int brojac = 0, brojac1=0;
    *najmanja = pocetak->CENA_MESA;

    while(fscanf(input, "%s %s %lf", temp->GRAD, temp->NAZIV_MESA, &temp->CENA_MESA) != EOF) {
        if(strcmp(temp->NAZIV_MESA, meso) == 0) {
            MESO* cvor = inicijalizuj_cvor(temp->GRAD, temp->NAZIV_MESA, temp->CENA_MESA);
            glava->SLEDECE = cvor;
            glava = cvor;

            if(glava->CENA_MESA < *najmanja) {
               *najmanja = glava->CENA_MESA;
               brojac = brojac1;
            }
            brojac1++;
        }
    }
    glava->SLEDECE = NULL;

    return pocetak->SLEDECE;
}

void output_to_file(FILE* file, MESO* glava) {

    while(glava) {
        fprintf(file, "%s %s %6.2lf\n", glava->GRAD, glava->NAZIV_MESA, glava->CENA_MESA);
        glava = glava->SLEDECE;
    }
}

void output_smallest(FILE* file, MESO* najmanja) {
    
}

int main(int argn, char* argv[]) {

    int najmanja = 0;

    if(argn != 4) {
        printf("Pogresan unos podataka, koriscenje: `./povoljno_meso junetina cene_mesa.txt analiza.txt`.\n");
        exit(EXIT_FAILURE);
    }

    FILE* in;
    FILE* out;

    in = file_safeopen(argv[2], "r");
    out = file_safeopen(argv[3], "w");

    MESO* glava = inicijalizuj_cvor("", "", 0);

    glava = read_from_input(in, argv[1], glava, &najmanja);
    output_to_file(out, glava);

    return 0;
}