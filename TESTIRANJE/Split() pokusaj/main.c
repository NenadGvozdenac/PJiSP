#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void split(char* string, char splitter) {

    if(string == NULL)  return;

    int broj_reci = 1;

    for(int i = 0; i < strlen(string); i++) {

        if(string[i] == ' ')
            broj_reci++;

    }

    char reci[broj_reci][15];

    int trenutna_pozicija = 0;
    int trenutna_pozicija_slova = 0;

    for(int i = 0; i < strlen(string); i++) {

        if(string[i] != splitter && string[i] != '\0') {
            reci[trenutna_pozicija][trenutna_pozicija_slova] = string[i];
            trenutna_pozicija_slova++;
        }
        
        if(string[i] == splitter) {
            reci[trenutna_pozicija][trenutna_pozicija_slova] = '\0';
            trenutna_pozicija_slova = 0;
            trenutna_pozicija++;
        }
    }

    for(int i = 0; i < broj_reci; i++) {

        printf("REC %d: %s\n", i + 1, reci[i]);

    }

}

int main() {

    char* string = "Dobar dan ja sam Nenad Gvozdenac! Idem na fakultet tehnickih nauka u Novom Sadu. Prva sam godina, i omiljeni predmet mi je matematika analiza jedan.";

    split(string, ' ');

}