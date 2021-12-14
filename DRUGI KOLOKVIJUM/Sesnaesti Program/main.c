// Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde struktura vatromet_st sadrži sledeća polja:

// naziv vatrometa (do 20 karaktera, bez razmaka)
// glasnoca (dBm, pozitivan ceo broj)
// cena (RSD, pozitivan ceo broj)
// Naravno, struktura vatromet_st sadrži i polja potrebna za pravilno formiranje binarnog stabla.

// Na osnovu zadate glasnoće max_glasnoca iz formiranog stabla upisati podatke o vatrometima, sortirane po ceni u rastućem poretku, čija je glasnoća manja ili jednaka argumentu max_glasnoca u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture vatromet_st:

// cena
// naziv vatrometa
// glasnoca
// Potom na osnovu zadate glasnoće pronaći vatromet čija je glasnoća manja od zadate i čiji je odnos glasnoće i cene najveći i ispisati informacije o tom vatrometu kao i samog odnosa u istu izlaznu datoteku.

// Primer poziva programa:

// ./a.exe 110 vatrometi.txt izlaz.txt

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct vatromet_st {
    char    NAZIV[20+1];
    int     GLASNOCA;
    int     CENA;

    struct vatromet_st* LEVI, *DESNI;
};

typedef struct vatromet_st VATROMET;

FILE* safe_fopen(char* NAZIV, char* MOD) {
    FILE* fajl = fopen(NAZIV, MOD);

    if(fajl == NULL) {
        printf("Greska, nisi otvorio fajl kako valja.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

void inicijalizuj_glavu(VATROMET** koren) {
    (*koren) = NULL;
}

VATROMET* inicijalizuj_vatromet(char* NAZIV, int GLASNOCA, int CENA) {
    VATROMET* novi = (VATROMET*)malloc(sizeof(VATROMET));
    if(novi == NULL) {
        printf("NEMAS RAMA JEBIGA ubi se\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novi->NAZIV, NAZIV);
    novi->GLASNOCA = GLASNOCA;
    novi->CENA = CENA;

    novi->LEVI = NULL;
    novi->DESNI = NULL;

    return novi;
}

void ubaci_u_listu(VATROMET* novi, VATROMET** koren) {
    if(*koren == NULL) {
        *koren = novi;
        return;
    } else {
        if((*koren)->CENA >= novi->CENA) {
            ubaci_u_listu(novi, &((*koren)->LEVI));
        } else {
            ubaci_u_listu(novi, &((*koren)->DESNI));
        }
    }
}

void citaj_u_binarno_stablo(FILE* fajl, VATROMET** koren) {
    char    NAZIV[20+1];
    int     GLASNOCA;
    int     CENA;

    while(fscanf(fajl, "%s %i %i", NAZIV, &GLASNOCA, &CENA) != EOF) {
        ubaci_u_listu(inicijalizuj_vatromet(NAZIV, GLASNOCA, CENA), koren);
    }
}

void ispisi_binarno_stablo_u_konzolu_od_veceg_do_manjeg_sortirano(VATROMET* vatromet) {
    if(vatromet == NULL) {
        return;
    } else {
        ispisi_binarno_stablo_u_konzolu_od_veceg_do_manjeg_sortirano(vatromet->LEVI);
        printf("%-15s %-4i %-4i\n", vatromet->NAZIV, vatromet->GLASNOCA, vatromet->CENA);
        ispisi_binarno_stablo_u_konzolu_od_veceg_do_manjeg_sortirano(vatromet->DESNI);
    }
}

void ispisi_binarno_stablo_u_fajl_od_veceg_do_manjeg_sortirano(FILE* fajl, VATROMET* vatromet, char* glasnoca) {
    if(vatromet == NULL) {
        return;
    } else {
        ispisi_binarno_stablo_u_fajl_od_veceg_do_manjeg_sortirano(fajl, vatromet->LEVI, glasnoca);
        if(vatromet->GLASNOCA <= atoi(glasnoca)) 
            fprintf(fajl, "%-15s %-4i %-4i\n", vatromet->NAZIV, vatromet->GLASNOCA, vatromet->CENA);
        ispisi_binarno_stablo_u_fajl_od_veceg_do_manjeg_sortirano(fajl, vatromet->DESNI, glasnoca);
    }
}

void ispisi_bangforbuck(VATROMET* vatromet, double odnos_cena, VATROMET** najbolji) {
    if(vatromet == NULL) {
        return;
    } else {
        ispisi_bangforbuck(vatromet->LEVI, odnos_cena, najbolji);
        if(odnos_cena > (vatromet->CENA / (double)vatromet->GLASNOCA)) {
            odnos_cena = (vatromet->CENA / (double)vatromet->GLASNOCA);
            *najbolji = vatromet;
        }
        ispisi_bangforbuck(vatromet->DESNI, odnos_cena, najbolji);
    }
}

void izbrisi_binarno_stablo(VATROMET** vatromet) {
    while(*vatromet) {
        izbrisi_binarno_stablo(&((*vatromet)->LEVI));
        izbrisi_binarno_stablo(&((*vatromet)->DESNI));
        free(*vatromet);
        *vatromet = NULL;
    }
}

int main(int argn, char** argv) {

    if(argn != 4) {
        printf("Nisi dobro uso u program, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz  = safe_fopen(argv[2], "r");
    FILE* izlaz = safe_fopen(argv[3], "w");

    double odnos_cena = 0;

    VATROMET* koren;
    VATROMET* najbolji = NULL;
    inicijalizuj_glavu(&koren);
    citaj_u_binarno_stablo(ulaz, &koren);
    // ispisi_binarno_stablo_u_konzolu_od_veceg_do_manjeg_sortirano(koren);
    ispisi_binarno_stablo_u_fajl_od_veceg_do_manjeg_sortirano(izlaz, koren, argv[1]);

    odnos_cena = koren->CENA / (double)koren->GLASNOCA;
    ispisi_bangforbuck(koren, odnos_cena, &najbolji);

    if(najbolji == NULL) {
        fprintf(izlaz, "\nThis does not exist...\n");
    } else {
        fprintf(izlaz, "\nNajbolji vatromet sa odnosom glasnoce prema ceni od %.2lf je:\n%i %s %i", 
            (double)koren->GLASNOCA / koren->CENA, 
            najbolji->CENA, 
            najbolji->NAZIV, 
            najbolji->GLASNOCA
        );
    }

    izbrisi_binarno_stablo(&koren);
    
    fclose(ulaz);
    fclose(izlaz);

    return 0;
}