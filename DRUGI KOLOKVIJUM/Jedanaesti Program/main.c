// Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu. Podatke učitati u rastućem redosledu po rednom broju rezervisanog sedišta. Struktura balet sadrži sledeća polja:

// redni broj rezervisanog sedišta (pozitivna celobrojna vrednost)
// naziv baleta (jedna reč, do 8 karaktera)
// rezervisao (jedna reč, do 25 karaktera)
// cena (pozitivna celobrojna vrednost)
// Takođe, struktura balet sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

// Od korisnika zatražiti da unese naziv baleta (jedna reč, do 8 karaktera) i za uneti balet na terminal ispisati naziv baleta, ukupan broj prodatih karata i ukupnu cenu karata. Ispisati i podatke o rezervisanom sedištu, kupcu koji je rezervisao i ceni karte (ispoštovati očekivani izlaz prikazan u stavci pod rednim brojem 4.).

// Napomene:

// Prilikom unosa naziva baleta od strane korisnika voditi računa o tome da program treba da prepozna naziv baleta bez obzira na kombinaciju malih i velikih slova koje je korisnik uneo (pogledati stavku pod rednim brojem 2. npr. ukoliko korisnik unese „zizela”, u izlaznu datoteku treba ispisati informacije o prepoznatom baletu sa nazivom „Zizela”).
// Kroz argumente komandne linije proslediti naziv ulazne datoteke.
// Ukoliko za unete podatke od strane korisnika ne postoje podaci očekivan izlaz je prikazan u stavci pod rednim brojem 5.
// Primer poziva:

// ./a.out balet.txt

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

struct balet {

    int REDNI_BROJ;
    char NAZIV[8+1];
    char REZERVISAO[25+1];
    int CENA;

    struct balet* SLEDECI;
};

typedef struct balet BALET;

FILE* safe_fopen(char* naziv, char* mod) {
    FILE* fajl = fopen(naziv, mod);

    if(fajl == NULL) {
        printf("Greska pri otvaranju datoteke, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    return fajl;
}

BALET* inicijalizuj_balet(int BROJ, char* NAZIV, char* REZERVISAO, int CENA) {
    BALET* balet = (BALET*)malloc(sizeof(BALET));
    if(balet == NULL) {
        printf("Greska pri alociranju memorije, izlaz.\n");
        exit(EXIT_FAILURE);
    }
    balet->REDNI_BROJ = BROJ;
    strcpy(balet->NAZIV, NAZIV);
    strcpy(balet->REZERVISAO, REZERVISAO);
    balet->CENA = CENA;

    balet->SLEDECI = NULL;
    return balet;
}

void ubaci_u_listu(BALET** glava, BALET* novi) {

    if(*glava == NULL) {
        (*glava) = novi;
        return;
    } else if((*glava)->REDNI_BROJ > novi->REDNI_BROJ) {
        novi->SLEDECI = *glava;
        (*glava) = novi;
        return;
    } else {
        BALET* tekuci = (*glava);

        while(tekuci) {
            if(tekuci->SLEDECI == NULL) {
                tekuci->SLEDECI = novi;
                novi->SLEDECI = NULL;
                return;
            } else if(tekuci->SLEDECI->REDNI_BROJ > novi->REDNI_BROJ) {
                novi->SLEDECI = tekuci->SLEDECI;
                tekuci->SLEDECI = novi;
                return;
            }

            tekuci = tekuci->SLEDECI;
        }
    }
}

void ucitaj_u_niz(FILE* fajl, BALET** glava) {

    BALET* temp = inicijalizuj_balet(0, "", "", 0);

    while(fscanf(fajl, "%d %s %s %d", &(temp->REDNI_BROJ), temp->NAZIV, temp->REZERVISAO, &(temp->CENA)) != EOF) {
        BALET* balet = inicijalizuj_balet(temp->REDNI_BROJ, temp->NAZIV, temp->REZERVISAO, temp->CENA);
        ubaci_u_listu(glava, balet);
    }
}

char* UPPERCASE(char* STRING) {
    for(int i = 0; i < strlen(STRING); i++) {
        if(STRING[i] >= 'a' && STRING[i] <= 'z') {
            STRING[i] -= 32;
        }
    }

    return STRING;
}

void normalizuj_string(char* STRING) {
    for(int i = 1; i < strlen(STRING); i++) {
        if(STRING[i] >= 'A' && STRING[i] <= 'Z') {
            STRING[i] += 32;
        }
    }
}

void ispisi_na_konzolu(BALET* glava, char* TRAZENI_BALET) {
    while(glava) {
        if(strcmp(UPPERCASE(TRAZENI_BALET), UPPERCASE(glava->NAZIV)) == 0) {
            printf("Sediste: %2d Rezervisao: %7s Cena: %6d\n", glava->REDNI_BROJ, glava->REZERVISAO, glava->CENA);
        }
        glava = glava->SLEDECI;
    }
}



void pronadji_broj_prodatih_karti(BALET* glava, char* TRAZENI_BALET) { 

    int n = 0, zarada = 0;

    while(glava) {
        if(strcmp(UPPERCASE(TRAZENI_BALET), UPPERCASE(glava->NAZIV)) == 0) {
            normalizuj_string(glava->NAZIV);
            zarada += (glava)->CENA;
            n++;
        }
        glava = glava->SLEDECI;
    }
    normalizuj_string(TRAZENI_BALET);
    if(n != 0) {
        printf("Ukupno prodatih karata za balet pod nazivom %s je %d.\nUkupna zarada je %d dinara.\n\n", TRAZENI_BALET, n, zarada);
    } else {
        printf("Za unete podatke od strane korisnika ne postoje podaci.");
        exit(EXIT_SUCCESS);
    }
}

void izbrisi_listu(BALET** glava) {
    while(*glava) {
        izbrisi_listu(&(*glava)->SLEDECI);
        free(*glava);
        *glava = NULL;
    }
}

int main(int argn, char** argv) {

    system("cls");

    if(argn != 2) {
        printf("Greska pri paljenju programa, izlaz.\n");
        exit(EXIT_FAILURE);
    }

    FILE* fajl = safe_fopen(argv[1], "r");

    BALET* glava = NULL;
    ucitaj_u_niz(fajl, &glava);

    char* naziv_baleta = (char*)malloc(sizeof(char) * 20);

    printf("Naziv baleta: ");
    scanf("%s", naziv_baleta);

    pronadji_broj_prodatih_karti(glava, naziv_baleta);
    ispisi_na_konzolu(glava, naziv_baleta);

    fclose(fajl);
    izbrisi_listu(&glava);

    getch();

    return 0;
}