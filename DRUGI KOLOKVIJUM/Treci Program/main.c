// Iz zadate datoteke učitati podatke u jednostruko spregnutu listu (podaci se dodaju na kraj liste), pri čemu se struktura rodjus_st sastoji od sledećih polja:

// naziv pića(jedna reč, do 30 karaktera)
// cena pića (realan broj)
// količina pića (pozitivan ceo broj)
// Naravno, struktura rodjus_st sadrži i podatke potrebne za pravilno formiranje jednostruko spregnute liste. 
// Potrebno je izračunati da li će moći da se kupe sva pića za unetu količinu novca (prosleđuje se kao parametar komandne linije, pogledati primere). 
// Rezultat je potrebno ispisati na standardni izlaz. Naziv ulazne datoteke i količina novca se prosleđuje kroz parametre komandne linije.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct rodjus_st {

    char naziv[30+1];
    double cena;
    int kolicina;

    struct rodjus_st* sledeci;
};

typedef struct rodjus_st RODJUS;

FILE* safe_open(char* FAJL, char* MOD) {

    FILE* fajl = fopen(FAJL, MOD);

    if(fajl == NULL) {
        printf("GRESKA PRI PRAVLJENJU FAJLA, IZLAZ.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

RODJUS* inicijalizuj_cvor(char* NAZIV, double CENA, int KOLICINA) {

    RODJUS* rodjendan = (RODJUS*)malloc(sizeof(RODJUS));

    if(rodjendan == NULL) {
        printf("GRESKA PRI ALOCIRANJU MEMORIJE ZA GLAVU, IZLAZ.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(rodjendan->naziv, NAZIV);
    rodjendan->cena = CENA;
    rodjendan->kolicina = KOLICINA;

    return rodjendan;
}

void citaj_iz_fajla(FILE* FAJL, RODJUS** RODJENDAN, double* UKUPNO_POTROSENO) {

    RODJUS* POCETAK = *RODJENDAN;
    RODJUS* TEMP = inicijalizuj_cvor("", 0.0, 0);
    int brojac = 0;

    while(fscanf(FAJL, "%s %lf %i", TEMP->naziv, &TEMP->cena, &TEMP->kolicina) != EOF) {
        RODJUS* CVOR = inicijalizuj_cvor(TEMP->naziv, TEMP->cena, TEMP->kolicina);
        (*RODJENDAN)->sledeci = CVOR;
        (*RODJENDAN) = CVOR;

        while(brojac < TEMP->kolicina) {
            (*UKUPNO_POTROSENO) += TEMP->cena;
            brojac++;
        }

        brojac = 0;
    }

    (*RODJENDAN)->sledeci = NULL;
    (*RODJENDAN) = POCETAK->sledeci;
}

void napisi_u_konzolu(RODJUS* RODJENDAN) {
    while(RODJENDAN) {
        printf("%s %.2lf %i\n", RODJENDAN->naziv, RODJENDAN->cena, RODJENDAN->kolicina);
        RODJENDAN = RODJENDAN->sledeci;
    }
}

int main(int argn, char* argv[]) {

    if(argn != 3) {
        printf("POGRESAN ULAZ.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ULAZ = safe_open(argv[1], "r");

    RODJUS* GLAVA = inicijalizuj_cvor("", 0.0, 0);

    double UKUPNO_POTROSENO = 0;

    citaj_iz_fajla(ULAZ, &GLAVA, &UKUPNO_POTROSENO);
    napisi_u_konzolu(GLAVA);

    printf("%s", 
        UKUPNO_POTROSENO > atof(argv[2]) ? 
            "Nema dovoljno novca, kupovina se ne može u celosti obaviti." : 
            "Kupovina je obavljena."
    );

    return 0;
}