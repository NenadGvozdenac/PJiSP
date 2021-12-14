// Napisati program koji iz tekstualne datoteke učitava n elemenata
// strukture tipa auto_st koja se sastoji iz sledećih polja:
// • Marka automobila (jedna reč, do 20 karaktera)
// • Kubikaža (prirodan broj)
// • Godište (prirodan broj)
// Ime ulazne tekstualne datoteke i kubikaža zadaju se kao argumenti
// komandne linije. Na osnovu zadatih informacija pronaći najnoviji auto sa
// kubikažom ne većom od zadate i rezultat upisati u tekstualnu datoteku,
// koja ima naziv oblika <marka_automobila>.txt.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct auto_st {

    char MARKA[20+1];
    int  KUBIKAZA;
    int  GODISTE;

    struct auto_st* SLEDECI;
};

typedef struct auto_st AUTO;

FILE* safe_fopen(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);
    if(fajl == NULL) {
        printf("Greska pri otvaranju ulazne datoteke, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

void inicijalizuj_glavu(AUTO** glava) {
    *glava = NULL;
}

AUTO* inicijalizuj_cvor(char* MARKA, int KUBIKAZA, int GODISTE) {
    AUTO* glava = (AUTO*)malloc(sizeof(AUTO));
    if(glava == NULL) {
        printf("Greska pri alokacije memorije, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(glava->MARKA, MARKA);
    glava->KUBIKAZA = KUBIKAZA;
    glava->GODISTE = GODISTE;

    glava->SLEDECI = NULL;

    return glava;
}

void ubaci_u_listu(AUTO** glava, AUTO* cvor) {
    if(*glava == NULL) {
        *glava = cvor;
        return;
    } else if(cvor->KUBIKAZA < (*glava)->KUBIKAZA) {
        cvor->SLEDECI = *glava;
        *glava = cvor;
        return;
    } else {
        AUTO* tekuci = *glava;
        while(tekuci) {

            if(tekuci->SLEDECI == NULL) {
                tekuci->SLEDECI = cvor;
                cvor->SLEDECI = NULL;
                return;
            } else if(tekuci->SLEDECI->KUBIKAZA > cvor->KUBIKAZA) {
                cvor->SLEDECI = tekuci->SLEDECI;
                tekuci->SLEDECI = cvor;
                return;
            }

            tekuci = tekuci->SLEDECI;
        }
    }
}

void ucitaj_iz_liste(AUTO** glava, FILE* fajl) {

    char MARKA[20+1];
    int KUBIKAZA;
    int GODISTE;

    while(fscanf(fajl, "%s %d %d", MARKA, &KUBIKAZA, &GODISTE) != EOF) {
        ubaci_u_listu(glava, inicijalizuj_cvor(MARKA, KUBIKAZA, GODISTE));
    }
}

void ispisi_u_konzolu(AUTO* glava) {
    while(glava) {
        printf("%-10s %5d %5d\n", glava->MARKA, glava->KUBIKAZA, glava->GODISTE);
        glava = glava->SLEDECI;
    }
}

void pronadji_najveci_koji_ne_prelazi_kubikazu(AUTO* glava, AUTO** najveci, char* kubikaza) {
    int KUBIKAZA = atoi(kubikaza);

    while(glava) {
        
        if(glava->KUBIKAZA > KUBIKAZA) {
            return;
        } else {
            *najveci = glava;
        }

        glava = glava->SLEDECI;
    }

    return;
}

void ispisi_najveci_u_konzolu(AUTO* glava) {
    if(glava) {
        printf("Najveci auto sa kubikazom koja ne prelezi trazenu je %s, kubikaza %d, godiste %d.\n", glava->MARKA, glava->KUBIKAZA, glava->GODISTE);
    } else {
        printf("Ne postoji auto sa kubikazom koja ne prelazi trazenu.\n");
    }
}

int main(int argn, char** argv) {

    if(argn != 3) {
        printf("Greska pri pokretanju programa, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    FILE* fajl = safe_fopen(argv[1], "r");

    AUTO* glava;
    AUTO* najveci = NULL;
    inicijalizuj_glavu(&glava);
    ucitaj_iz_liste(&glava, fajl);
    ispisi_u_konzolu(glava);
    pronadji_najveci_koji_ne_prelazi_kubikazu(glava, &najveci, argv[2]);
    ispisi_najveci_u_konzolu(najveci);

    return 0;
}