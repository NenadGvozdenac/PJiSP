// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura restoran_st sadrži sledeća polja:

// naziv restorana (jedna reč, do 10 karaktera)
// vrsta kuhinje (jedna reč, do 20 karaktera)
// prosečna ocena korisnika (pozitivan realan broj)
// Naravno, struktura restoran_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Na osnovu zadate vrste kuhinje vrsta iz formirane liste upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture restoran_st:

// prosečna ocena korisnika (zaokružena na 1 decimalu, koristiti "%3.1f" format specifikator)
// naziv restorana (koristiti "%-10s" format specifikator)
// vrsta kuhinje
// i potom u istu izlaznu datoteku upisati informaciju o najbolje ocenjenom restoranu koji služi hranu zadate vrste kuhinje.

// Primer poziva:

// ./restorani italijanski novi-sad.txt izvestaj.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct restoran_st {

    char NAZIV[10+1];
    char VRSTA_KUHINJE[20+1];
    double PROSECNA_OCENA;

    struct restoran_st* SLEDECE;
};

typedef struct restoran_st RESTORAN;

FILE* safe_open(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Greska pri pravljenju fajla.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

RESTORAN* inicijalizuj_cvor(char* NAZIV, char* VRSTA, double OCENA) {
    RESTORAN* restoran = (RESTORAN*)malloc(sizeof(RESTORAN));

    if(restoran == NULL) {
        printf("NEDOVOLJNO RAMA!!!!!!!!!!!!!!!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(restoran->NAZIV, NAZIV);
    strcpy(restoran->VRSTA_KUHINJE, VRSTA);
    restoran->PROSECNA_OCENA = OCENA;

    restoran->SLEDECE = NULL;
    return restoran;
}

void ucitaj_u_listu(RESTORAN** glava, RESTORAN* novi) {

    if((*glava) == NULL) {
        (*glava) = novi;
        return;
    } else if((*glava)->PROSECNA_OCENA < novi->PROSECNA_OCENA) {
        novi->SLEDECE = *glava;
        (*glava) = novi;
        return;
    } else {
        RESTORAN* tekuci = *glava;
        while(tekuci) {
            if(tekuci->SLEDECE == NULL) {
                tekuci->SLEDECE = novi;
                novi->SLEDECE = NULL;
                return;
            } else if(tekuci->SLEDECE->PROSECNA_OCENA < novi->PROSECNA_OCENA) {
                novi->SLEDECE = tekuci->SLEDECE;
                tekuci->SLEDECE = novi;
                return;
            }

            tekuci = tekuci->SLEDECE;
        }
    }

    // RESTORAN* tekuci = (*glava);

    // while(tekuci != NULL) {
    //     tekuci = tekuci->SLEDECE;
    // }

    // if(tekuci == NULL) {
    //     tekuci = novi;
    //     return;
    // }/
}

void citaj_iz_fajla(FILE* fajl, RESTORAN** glava, double* ocena, RESTORAN** najbolji, char* vrsta, bool* postoji) {

    RESTORAN* temp = inicijalizuj_cvor("", "", 0);
    (*postoji) = false;

    while(fscanf(fajl, "%s %s %lf", temp->NAZIV, temp->VRSTA_KUHINJE, &(temp->PROSECNA_OCENA)) != EOF) {
        RESTORAN* novi_restoran = inicijalizuj_cvor(temp->NAZIV, temp->VRSTA_KUHINJE, temp->PROSECNA_OCENA);
        ucitaj_u_listu(glava, novi_restoran);

        if(novi_restoran->PROSECNA_OCENA > (*ocena) && strcmp(novi_restoran->VRSTA_KUHINJE, vrsta) == 0) {
            (*postoji) = 1;
            (*ocena) = novi_restoran->PROSECNA_OCENA;
            (*najbolji) = novi_restoran;
        }
    }
}

void ispisi_u_konzolu(RESTORAN* glava) {
    while(glava) {
        printf("%s %s %.2lf\n", glava->NAZIV, glava->VRSTA_KUHINJE, glava->PROSECNA_OCENA);
        glava = glava->SLEDECE;
    }
}

void ispisi_u_fajl(FILE* fajl, RESTORAN* glava) {
    while(glava) {
        fprintf(fajl, "%-10s %s %3.1lf\n", glava->NAZIV, glava->VRSTA_KUHINJE, glava->PROSECNA_OCENA);
        glava = glava->SLEDECE;
    }
}

void ispisi_najbolji_restoran_u_fajl(FILE* fajl, RESTORAN* najbolji, char* vrsta, bool postoji) {

    if(postoji) {
        fprintf(fajl, "\nNajbolje ocenjen %s restoran u gradu je:\n%.2lf %s %s", 
            vrsta, 
            najbolji->PROSECNA_OCENA, 
            najbolji->NAZIV, 
            najbolji->VRSTA_KUHINJE
        );
    } else fprintf(fajl, "\nU gradu ne postoji %s restoran!", vrsta);
}

int main(int argn, char** argv) {

    if(argn != 4) {
        printf("Greska pri pokretanju programa.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz  = safe_open(argv[2], "r");
    FILE* izlaz = safe_open(argv[3] , "w");

    RESTORAN* glava = NULL;
    RESTORAN* najbolji_restoran = NULL;
    double najbolja_ocena = 0;
    bool postoji;
    citaj_iz_fajla(ulaz, &glava, &najbolja_ocena, &najbolji_restoran, argv[1], &postoji);
    ispisi_u_konzolu(glava);
    //ispisi_u_fajl(izlaz, glava);
    //ispisi_najbolji_restoran_u_fajl(izlaz, najbolji_restoran, argv[1], postoji);

    fclose(ulaz);
    fclose(izlaz);

    return EXIT_SUCCESS;
}