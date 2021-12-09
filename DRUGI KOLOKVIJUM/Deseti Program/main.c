// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura slatkis_st sadrži sledeća polja:

// naziv slatkiša (jedna reč, do 30 karaktera)
// količina šećera na 100 grama (pozitivan realan broj)
// gramaža (pozitivan ceo broj)
// vrsta slatkiša (jedna reč, do 30 karaktera)
// Naravno, struktura slatkis_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Na osnovu zadate vrste saltkiša vrsta iz formirane liste upisati podatke koji pripadaju zadatoj vrsti slatkiša u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture slatkis_st:

// naziv slatkisa
// gramaža
// količina šećera na 100 grama
// i potom u istu izlaznu datoteku upisati informaciju o slatkišu koji ima najveću količinu šećera u pakovanju. Sve realne vrednosti zaokružiti na 2 decimale pri ispisu.

// Primer poziva programa:

// ./slatkis praline slatkisi.txt izvestaj.txt

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct slatkis_st {

    char NAZIV[30+1];
    double KOLICINA_SECERA;
    int GRAMAZA;
    char VRSTA[30+1];

    struct slatkis_st* SLEDECI;
};

typedef struct slatkis_st SLATKIS;

FILE* safe_fopen(char* NAZIV, char* MOD) {

    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Zezno si stvar, fajl se nije otvorio, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

SLATKIS* inicijalizuj_slatkis(char* NAZIV, double KOLICINA, int GRAMAZA, char* VRSTA) {

    SLATKIS* slatkis = (SLATKIS*)malloc(sizeof(SLATKIS));

    if(slatkis == NULL) {
        printf("Zezno si stvar opet, nema dovoljno rama, kako???");
        exit(EXIT_FAILURE);
    }

    strcpy(slatkis->NAZIV, NAZIV);
    strcpy(slatkis->VRSTA, VRSTA);
    slatkis->KOLICINA_SECERA = KOLICINA;
    slatkis->GRAMAZA = GRAMAZA;

    slatkis->SLEDECI = NULL;
    return slatkis;
}

void ubaci_u_listu(SLATKIS** glava, SLATKIS* trenutni) {

    if(*glava == NULL) {
        (*glava) = trenutni;
        return;
    }

    ubaci_u_listu(&(*glava)->SLEDECI, trenutni);
}

void ucitaj_iz_fajla(FILE* ULAZ, SLATKIS** GLAVA) {

    SLATKIS* temp = inicijalizuj_slatkis("", 0.0, 0, "");

    while(fscanf(ULAZ, "%s %lf %i %s", temp->NAZIV, &(temp->KOLICINA_SECERA), &(temp->GRAMAZA), temp->VRSTA) != EOF) {
        SLATKIS* trenutni = inicijalizuj_slatkis(temp->NAZIV, temp->KOLICINA_SECERA, temp->GRAMAZA, temp->VRSTA);
        ubaci_u_listu(GLAVA, trenutni);
    }
}

void ispisi_u_konzolu(SLATKIS* GLAVA) {
    while(GLAVA) {
        printf("%s %.2lf %i %s\n", GLAVA->NAZIV, GLAVA->KOLICINA_SECERA, GLAVA->GRAMAZA, GLAVA->VRSTA);
        GLAVA = GLAVA->SLEDECI;
    }
}

void upisi_u_fajl(SLATKIS* GLAVA, char* VRSTA, FILE* FAJL) {
    while(GLAVA) {
        if(strcmp(GLAVA->VRSTA, VRSTA) == 0) {
            fprintf(FAJL, "%s %i %.2lf %s\n", GLAVA->NAZIV, GLAVA->GRAMAZA, GLAVA->KOLICINA_SECERA, GLAVA->VRSTA);
        }

        GLAVA = GLAVA->SLEDECI;
    }
}

void napisi_najveci_u_fajl(SLATKIS* GLAVA, char* VRSTA, FILE* FAJL, int KOLSECERA) {

    SLATKIS* SLATKIS_SA_NAJVISE_SECERA = NULL;

    while(GLAVA) {
        if(strcmp(GLAVA->VRSTA, VRSTA) == 0 && GLAVA->KOLICINA_SECERA > KOLSECERA) {
            KOLSECERA = GLAVA->KOLICINA_SECERA;
            SLATKIS_SA_NAJVISE_SECERA = GLAVA;
        }

        GLAVA = GLAVA->SLEDECI;
    }

    if(SLATKIS_SA_NAJVISE_SECERA != NULL) {
        printf("\nSlatkis sa najvise secera je: %s.\nKolicina secera je: %.2lf.", 
        SLATKIS_SA_NAJVISE_SECERA->NAZIV, 
        SLATKIS_SA_NAJVISE_SECERA->KOLICINA_SECERA
    );
    } else {
        printf("\nNe postoji secer sa najvise secera.");
    }
}

int main(int argn, char** argv) {

    if(argn != 4) {
        printf("Zezno si stvar, pogresan poziv, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz  = safe_fopen(argv[2], "r");
    FILE* izlaz = safe_fopen(argv[3], "w");

    SLATKIS* glava = NULL;
    ucitaj_iz_fajla(ulaz, &glava);
    ispisi_u_konzolu(glava);
    upisi_u_fajl(glava, argv[1], izlaz);
    napisi_najveci_u_fajl(glava, argv[1], izlaz, 0);

    return EXIT_SUCCESS;
}