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

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct element_st {

    char HEMIJSKI_SIMBOL[2+1];
    char IME[20+1];
    int ATOMSKA_TEZINA;
    char VRSTA[20+1];

    struct element_st* SLEDECI;
};

typedef struct element_st ELEMENT;

FILE* file_open(char* IME_FAJLA, char* MOD_OTVARANJA) {

    FILE* fajl = fopen(IME_FAJLA, MOD_OTVARANJA);

    if(fajl == NULL) {
        printf("GRESKA PRI OTVARANJU FAJLA %s.\n", IME_FAJLA);
        exit(EXIT_FAILURE);
    }

    return fajl;
}

ELEMENT* inicijalizuj_cvor(char* HEM_SIMBOL, char* IME, int ATOM_TEZINA, char* VRSTA) {

    ELEMENT* cvor = (ELEMENT*)malloc(sizeof(ELEMENT));

    if(cvor == NULL) {
        printf("GRESKA PRI ALOKACIJI CVORA.\n");
        exit(EXIT_FAILURE);
    }

    cvor->ATOMSKA_TEZINA = ATOM_TEZINA;
    strcpy(cvor->IME, IME);
    strcpy(cvor->HEMIJSKI_SIMBOL, HEM_SIMBOL);
    strcpy(cvor->VRSTA, VRSTA);

    cvor->SLEDECI = NULL;

    return cvor;
}

void citaj_podatke_iz_fajla(FILE* ULAZNI_FAJL, ELEMENT** GLAVA) {

    ELEMENT* temp = inicijalizuj_cvor("", "", 0, "");
    ELEMENT* pocetak = *GLAVA;

    while(fscanf(ULAZNI_FAJL, "%s %s %i %s", temp->HEMIJSKI_SIMBOL, temp->IME, &(temp->ATOMSKA_TEZINA), temp->VRSTA) != EOF) { 
        ELEMENT* cvor = inicijalizuj_cvor(temp->HEMIJSKI_SIMBOL, temp->IME, temp->ATOMSKA_TEZINA, temp->VRSTA);
        (*GLAVA)->SLEDECI = cvor;
        (*GLAVA) = cvor;
    }

    (*GLAVA)->SLEDECI = NULL;
    (*GLAVA) = pocetak->SLEDECI;
    free(pocetak);
}

ELEMENT* pronadji_najtezi(ELEMENT* GLAVA, char* vrsta, int* tezina, bool* pronadjen) {

    ELEMENT* temp = inicijalizuj_cvor("", "", 0, "");
    (*pronadjen) = false;

    while(GLAVA) {
        if(strcmp(GLAVA->VRSTA, vrsta) == 0) {
            (*pronadjen) = true;
            if(GLAVA->ATOMSKA_TEZINA > (*tezina)) {
                (*tezina) = GLAVA->ATOMSKA_TEZINA;
                temp = GLAVA;
            }
        }
        GLAVA = GLAVA->SLEDECI;
    }

    return temp;
}

void ispisi_na_konzolu(ELEMENT* GLAVA, ELEMENT* NAJTEZI, bool PRONADJEN, char* VRSTA) {
    while(GLAVA) {
        printf("%s %s %i %s\n", GLAVA->HEMIJSKI_SIMBOL, GLAVA->IME, GLAVA->ATOMSKA_TEZINA, GLAVA->VRSTA);
        GLAVA = GLAVA->SLEDECI;
    }

    if(PRONADJEN)
        printf("\nNajtezi %s je %s (%s), atomska tezina %i.", NAJTEZI->VRSTA, NAJTEZI->IME, NAJTEZI->HEMIJSKI_SIMBOL, NAJTEZI->ATOMSKA_TEZINA);
    else
        printf("\nU uzorku nije pronadjen ni jedan %s!", VRSTA);
}

void ispisi_u_fajl(FILE* FAJL, ELEMENT* GLAVA, ELEMENT* NAJTEZI, bool PRONADJEN, char* VRSTA) {

    while(GLAVA) {
        fprintf(FAJL, "%-2s %3u %s\n", GLAVA->HEMIJSKI_SIMBOL, GLAVA->ATOMSKA_TEZINA, GLAVA->VRSTA);
        GLAVA = GLAVA->SLEDECI;
    }

    if(PRONADJEN) 
        fprintf(FAJL, "\nNajtezi %s je %s (%s), atomska tezina %i.", NAJTEZI->VRSTA, NAJTEZI->IME, NAJTEZI->HEMIJSKI_SIMBOL, NAJTEZI->ATOMSKA_TEZINA);
    else 
        fprintf(FAJL, "\nU uzorku nije pronadjen ni jedan %s!", VRSTA);
}

void izbrisi_listu(ELEMENT** GLAVA) {

    while((*GLAVA) != NULL) {
        izbrisi_listu(&(*GLAVA)->SLEDECI);
        free(*GLAVA);
        *GLAVA = NULL;
    }

}

int main(int argn, char** argv) {

    if(argn != 4) {
        printf("GRESKA PRI POKRETANJU PROGRAMA, PRIMER ULAZA: ./najtezi metal uzorak_vino.txt analiza.txt\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz  = file_open(argv[2], "r");
    FILE* izlaz = file_open(argv[3], "w");

    ELEMENT* glava = inicijalizuj_cvor("", "", 0, "");
    ELEMENT* najtezi;

    int tezina = 0;
    bool pronadjen;

    citaj_podatke_iz_fajla(ulaz, &glava);

    najtezi = pronadji_najtezi(glava, argv[1], &tezina, &pronadjen);

    ispisi_na_konzolu(glava, najtezi, pronadjen, argv[1]);
    ispisi_u_fajl(izlaz, glava, najtezi, pronadjen, argv[1]);

    izbrisi_listu(&glava);

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}