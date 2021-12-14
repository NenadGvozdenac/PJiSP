// Proizvodi su opisani na sledeći način:

// Naziv (jedna reč, maksimalno 20 karaktera)
// vrsta (jedna reč, maksimalno 15 karaktera)
// cena (realan broj)
// Za proizvode iz ulazne datoteke uraditi sledeće:

// Učitati proizvode u jednostruko spregnutu listu. Novi elementi dodaju se tako da lista bude sortirana po ceni u rastućem redosledu.
// Na osnovu argumenta komandne linije koji označava vrstu proizvoda, na standardni izlaz (ekran Terminala) ispisati sledeće informacije:
// cena (zaokruženo na dve decimale, ispisano sa %6.2lf format specifikatorom)
// naziv (ispisano sa %-12s format specifikatorom)
// vrsta (ispisano sa %s format specifikatorom)
// Ispisati da proizvodi ne postoje u slučaju da nijedan proizvod nije zadate vrste (pogledati primere ispisa programa).

// ./proizvodi proizvodi.txt prehrambeni

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct proizvod_st {

    char NAZIV[20+1];
    char VRSTA[15+1];
    double CENA;

    struct proizvod_st* SLEDECI;
};

typedef struct proizvod_st PROIZVOD;

FILE* safe_fopen(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Greska pri ulazu u tekstualnu datoteku, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

void inicijalizuj_glavu(PROIZVOD** glava) {
    *glava = NULL;
}

PROIZVOD* inicijalizuj_cvor(char* NAZIV, double CENA, char* VRSTA) {
    PROIZVOD* proizvod = (PROIZVOD*)malloc(sizeof(PROIZVOD));
    if(proizvod == NULL) {
        printf("Greska, nema dovoljno memorije.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(proizvod->NAZIV, NAZIV);
    strcpy(proizvod->VRSTA, VRSTA);
    proizvod->CENA = CENA;

    proizvod->SLEDECI = NULL;

    return proizvod;
}

void ubaci_u_listu(PROIZVOD** glava, PROIZVOD* novi) {

    if(*glava == NULL) {
        *glava = novi;
        return;
    } else if(novi->CENA < (*glava)->CENA) {
        novi->SLEDECI = (*glava);
        (*glava) = novi;
        return;
    } else {
        PROIZVOD* tekuci = (*glava);

        while(tekuci) {
            if(tekuci->SLEDECI == NULL) {
                tekuci->SLEDECI = novi;
                novi->SLEDECI = NULL;
                return;
            } else if(novi->CENA < tekuci->SLEDECI->CENA) {
                novi->SLEDECI = tekuci->SLEDECI;
                tekuci->SLEDECI = novi;
                return;
            }

            tekuci = tekuci->SLEDECI;
        }
    }
}

void citaj_iz_fajla(FILE* fajl, PROIZVOD** proizvod) {

    char NAZIV[20+1];
    char VRSTA[15+1];
    double CENA;

    while(fscanf(fajl, "%s %lf %s", NAZIV, &CENA, VRSTA) != EOF) {
        ubaci_u_listu(proizvod, inicijalizuj_cvor(NAZIV, CENA, VRSTA));
    }
}

void ispisi_na_konzolu_sve(PROIZVOD* glava) {

    while(glava) {
        printf("%-12s %6.2lf %s\n", glava->NAZIV, glava->CENA, glava->VRSTA);
        glava = glava->SLEDECI;
    }
}

void ispisi_na_konzolu_odredjenje(PROIZVOD* glava, char* vrsta, bool* postoji) {
    while(glava) {
        if(strcmp(vrsta, glava->VRSTA) == 0) {
            *postoji = true;
            printf("%6.2lf %-12s %s\n", glava->CENA, glava->NAZIV, glava->VRSTA);
        }
        glava = glava->SLEDECI;
    }

    if(*postoji == false) {
        printf("Ne postoji nijedan proizvod vrste %s!", vrsta);
    }
}

void izbrisi_listu(PROIZVOD** glava) {
    while(*glava) {
        PROIZVOD* tekuci = *glava;
        (*glava) = (*glava)->SLEDECI;
        free(tekuci);
        tekuci = NULL;
    }
}

int main(int argn, char** argv) {

    if(argn != 3) {
        printf("Greska pri ulazu u datoteku, izlaz.\n");
        exit(EXIT_FAILURE);
    } 

    FILE* ulaz = safe_fopen(argv[1], "r");

    bool postoji = false;

    PROIZVOD* glava;
    inicijalizuj_glavu(&glava);
    citaj_iz_fajla(ulaz, &glava);
    //ispisi_na_konzolu_sve(glava);
    ispisi_na_konzolu_odredjenje(glava, argv[2], &postoji);

    izbrisi_listu(&glava);

    fclose(ulaz);

    return EXIT_SUCCESS;
}