#include "klase.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor Podatak;

Podatak* unos(Podatak* glava) {
    Podatak* nista = malloc(sizeof(Podatak));

    nista->sledeci = glava;
    printf("Unesite broj koji zelite: ");
    scanf("%d", &nista->podatak);

    return nista;
}

void ispis(Podatak* glava) {

    while(glava->sledeci != NULL) {
        printf("%d ", glava->podatak);
        glava = glava->sledeci;
    }

}

int main() {

    int odabir = 1;

    Podatak* glava = malloc(sizeof(Podatak));
    glava->sledeci = NULL;
    glava->podatak = 0;

    char buffer;

    while(odabir) {
        printf("-----------------------\nUNESITE STA ZELITE DA RADITE: \n1 -> UNOS\n2 -> ISPIS\n\n0 -> IZLAZ\n-----------------------\nODABIR: ");
        scanf("%d", &odabir);

        switch(odabir) {
            case 1: 
                glava = unos(glava);
            break;

            case 2:
                ispis(glava);
                scanf("%c", buffer);
            break;

            case 0:
                printf("HVALA NA KORISCENJU!");
                exit(0);

            default:
                printf("POGRESAN UNOS!");
                return 0;
        }

        system("cls");

    }
    return 0;
}