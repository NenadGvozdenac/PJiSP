// Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde struktura restoran_st sadrži sledeća polja:

// naziv restorana (jedna reč, do 10 karaktera)
// vrsta kuhinje (jedna reč, do 20 karaktera)
// prosečna ocena korisnika (pozitivan realan broj)
// Naravno, struktura restoran_st sadrži i polja potrebna za pravilno formiranje binarnog stabla.

// Binarno stablo urediti po ključu „prosečna ocena korisnika”, u opadajućem redosledu. Potom iz formiranog binarnog stabla upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture restoran_st:

// prosečna ocena korisnika (zaokružena na 1 decimalu, koristiti "%3.1f" format specifikator)
// naziv restorana (koristiti "%-10s" format specifikator)
// vrsta kuhinje
// i potom u istu izlaznu datoteku upisati informaciju o najgore ocenjenom restoranu.

// Primer poziva programa:

// ./restorani novi-sad.txt izvestaj.txt

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct restoran_st {

    char NAZIV[10+1];
    char VRSTA[20+1];
    double OCENA;

    struct restoran_st* levi;
    struct restoran_st* desni;
};

typedef struct restoran_st RESTORAN;

FILE* safe_fopen(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Greska pri otvaranju .txt fajla, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

void inicijalizuj_glavu(RESTORAN** glava) {
    *glava = NULL;
}

RESTORAN* inicijalizuj_cvor(char* NAZIV, char* VRSTA, double OCENA) {
    RESTORAN* restoran = (RESTORAN*)malloc(sizeof(RESTORAN));

    if(restoran == NULL) {
        printf("Greska pri alokaciji memorije, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(restoran->NAZIV, NAZIV);
    strcpy(restoran->VRSTA, VRSTA);
    restoran->OCENA = OCENA;

    restoran->levi = NULL;
    restoran->desni = NULL;

    return restoran;
}

void ubaci_u_binarno_stablo(RESTORAN** glava, RESTORAN* novi) {
    if(*glava == NULL) {
        *glava = novi;
        return;
    } else {
        if((*glava)->OCENA <= novi->OCENA) {
            ubaci_u_binarno_stablo(&(*glava)->levi, novi);
        } else {
            ubaci_u_binarno_stablo(&(*glava)->desni, novi);
        }
    }
}

void citaj_iz_fajla(RESTORAN** glava, FILE* fajl) {
    char NAZIV[11];
    char VRSTA[21];
    double OCENA;

    while(fscanf(fajl, "%s %s %lf", NAZIV, VRSTA, &OCENA) != EOF) {
        RESTORAN* restoran = inicijalizuj_cvor(NAZIV, VRSTA, OCENA);
        ubaci_u_binarno_stablo(glava, restoran);
    }
}

void ispisi_iz_stabla_u_konzolu(RESTORAN* glava) {
    if(glava == NULL) {
        return;
    } else {
        ispisi_iz_stabla_u_konzolu(glava->levi);
        printf("%3.1f %-10s %s\n", glava->OCENA, glava->NAZIV, glava->VRSTA);
        ispisi_iz_stabla_u_konzolu(glava->desni);
    }
}

void ispisi_iz_stabla_u_fajl(RESTORAN* glava, FILE* fajl) {
    if(glava == NULL) {
        return;
    } else {
        ispisi_iz_stabla_u_fajl(glava->levi, fajl);
        fprintf(fajl, "%3.1f %-10s %s\n", glava->OCENA, glava->NAZIV, glava->VRSTA);
        ispisi_iz_stabla_u_fajl(glava->desni, fajl);
    }
}

RESTORAN* pronadji_najgori_u_stablu(RESTORAN* glava) {
    if(glava == NULL) {
        return NULL;
    } else if(glava->desni == NULL) {
        return glava;
    }

    return pronadji_najgori_u_stablu(glava->desni);
}

void ispisi_najgori_u_fajl(RESTORAN* glava, FILE* fajl) {
    if(glava == NULL) {
        fprintf(fajl, "Ne postoji najgori restoran u gradu!");
    } else {
        fprintf(fajl, "\nNajgori restoran u gradu je:\n%3.1f %-10s %s", glava->OCENA, glava->NAZIV, glava->VRSTA);
    }
}

void brisi_stablo(RESTORAN** glava) {
    if(*glava == NULL) {
        return;
    } else {
        brisi_stablo(&(*glava)->levi);
        brisi_stablo(&(*glava)->desni);
        free(*glava);
        (*glava) = NULL;
    }
}

int main(int argn, char** argv) {

    if(argn != 3) {
        printf("Greska pri otvaranju programa, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz  = safe_fopen(argv[1], "r");
    FILE* izlaz = safe_fopen(argv[2], "w");

    RESTORAN* glava;
    inicijalizuj_glavu(&glava);
    citaj_iz_fajla(&glava, ulaz);
    // ispisi_iz_stabla_u_konzolu(glava);
    ispisi_iz_stabla_u_fajl(glava, izlaz);
    RESTORAN* najgori = pronadji_najgori_u_stablu(glava);
    ispisi_najgori_u_fajl(najgori, izlaz);

    brisi_stablo(&glava);

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}