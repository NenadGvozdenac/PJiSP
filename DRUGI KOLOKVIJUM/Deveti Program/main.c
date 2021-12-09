// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura knjiga_st sadrži sledeća polja:

// ime pisca (jedna reč, do 20 karaktera)
// prezime pisca (jedna reč, do 20 karaktera)
// naslov knjige (jedna reč, do 30 karaktera)
// cena po komadu (pozitivan broj)
// broj prodatih kopija (pozitivan broj)
// Naravno, struktura knjiga_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Učitati knjige u jednostruko spregnutu listu i uraditi sledeće:

// Sortirati knjige po ceni u rastućem redosledu pri dodavanju u listu

// Izračunati ukupnu zaradu svake knjige korišćenjem cene po komadu i broja prodatih kopija.

// Na standardni izlaz (ekran Terminala) ispisati sledeće informacije:

// prezime pisca
// ime pisca
// naslov knjige
// ukupna zarada
// Pronaći knjigu koja je zaradila najviše novca i ispisati njene podatke na standardni izlaz (ekran Terminala)

// ./knjige knjige.txt

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct knjiga_st {
    char IME_PISCA[20+1];
    char PREZIME_PISCA[20+1];
    char NASLOV_KNJIGE[30+1];

    int CENA_KNJIGE;
    int BROJ_PRODATIH_KOPIJA;

    struct knjiga_st* SLEDECE;
};

typedef struct knjiga_st KNJIGA;

FILE* safe_fopen(char* NAZIV, char* MOD) {

    FILE* naziv = fopen(NAZIV, MOD);

    if(naziv == NULL) {
        printf("Greska pri ukljucivanju fajla, greska.\n");
        exit(EXIT_FAILURE);
    }

    return naziv;
}

KNJIGA* inicijalizuj_cvor(char* IME, char* PREZIME, char* NASLOV, int CENA, int PRODATE_KOPIJE) {

    KNJIGA* knjiga = (KNJIGA*)malloc(sizeof(KNJIGA));

    if(knjiga == NULL) {
        printf("Greska pri alociranju memorije, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(knjiga->IME_PISCA, IME);
    strcpy(knjiga->PREZIME_PISCA, PREZIME);
    strcpy(knjiga->NASLOV_KNJIGE, NASLOV);
    knjiga->CENA_KNJIGE = CENA;
    knjiga->BROJ_PRODATIH_KOPIJA = PRODATE_KOPIJE;
    knjiga->SLEDECE = NULL;

    return knjiga;
}

void ubaci_u_cvor(KNJIGA** glava, KNJIGA* novi) {
    if((*glava) == NULL) {
        (*glava) = novi;
        return;
    } else if((*glava)->CENA_KNJIGE > novi->CENA_KNJIGE) {
        novi->SLEDECE = (*glava);
        (*glava) = novi;
        return;
    } else {
        KNJIGA* tekuci = (*glava);
        while(tekuci) {
            if(tekuci->SLEDECE == NULL) {
                tekuci->SLEDECE = novi;
                novi->SLEDECE = NULL;
                return;
            } else if(tekuci->SLEDECE->CENA_KNJIGE > novi->CENA_KNJIGE) {
                novi->SLEDECE = tekuci->SLEDECE;
                tekuci->SLEDECE = novi;
                return;
            }
            tekuci = tekuci->SLEDECE;
        }
    }
}

void ucitaj_u_listu(FILE* fajl, KNJIGA** knjiga) {
    KNJIGA* temp = inicijalizuj_cvor("", "", "", 0, 0);
    while(fscanf(fajl, "%s %s %s %d %d", temp->IME_PISCA, temp->PREZIME_PISCA, temp->NASLOV_KNJIGE, &(temp->CENA_KNJIGE), &(temp->BROJ_PRODATIH_KOPIJA)) != EOF) {
        KNJIGA* temporari = inicijalizuj_cvor(temp->IME_PISCA, temp->PREZIME_PISCA, temp->NASLOV_KNJIGE, temp->CENA_KNJIGE, temp->BROJ_PRODATIH_KOPIJA);
        ubaci_u_cvor(knjiga, temporari);
    }
}

void pronadji_najveci(KNJIGA* glava, int* CENA, KNJIGA** najveci) {
    while(glava) {
        int trenutna_cena = glava->CENA_KNJIGE * glava->BROJ_PRODATIH_KOPIJA;
        if(trenutna_cena > (*CENA)) {
            (*CENA) = trenutna_cena;
            (*najveci) = glava;
        }
        glava = glava->SLEDECE;
    }
}

void ispisi_na_konzolu(KNJIGA* knjiga) {

    while(knjiga) {
        printf("%s %s %s %i %i\n", knjiga->IME_PISCA, knjiga->PREZIME_PISCA, knjiga->NASLOV_KNJIGE, knjiga->CENA_KNJIGE, knjiga->BROJ_PRODATIH_KOPIJA);
        knjiga = knjiga->SLEDECE;
    }

}

void ispisati_najvecu_zaradu(KNJIGA* knjiga, int cena) {

    printf("Knjiga koja je zaradila najvise novca je %s %s %s %d %d.", knjiga->PREZIME_PISCA, knjiga->IME_PISCA, knjiga->NASLOV_KNJIGE, knjiga->CENA_KNJIGE, knjiga->BROJ_PRODATIH_KOPIJA);

}

int main(int argn, char** argv) {

    if(argn != 2) {
        printf("Greska pri pokretanju programa, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    FILE* ulaz = safe_fopen(argv[1], "r");

    KNJIGA* glava = NULL;
    KNJIGA* najveca = NULL;
    int najveca_cena = 0;
    ucitaj_u_listu(ulaz, &glava);
    pronadji_najveci(glava, &najveca_cena, &najveca);
    ispisi_na_konzolu(glava);
    ispisati_najvecu_zaradu(najveca, najveca_cena);

    return EXIT_FAILURE;
}