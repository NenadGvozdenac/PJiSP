#include "klasa.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Stablo Stablo;

Stablo* unesiLevi(Stablo* glava, int podatak) {

    Stablo* novoStablo = malloc(sizeof(Stablo));

    glava->levi = novoStablo;
    glava->desni = NULL;

    novoStablo->podatak = podatak;

    return glava;
}

Stablo* unesiDesni(Stablo* glava, int podatak) {

    Stablo* novoStablo = malloc(sizeof(Stablo));

    glava->desni = novoStablo;
    glava->levi = NULL;

    novoStablo->podatak = podatak;

    return glava;
}

void ispisi_sve(Stablo* stablo) {

    printf("%d\n", stablo->podatak);
}

int main() {

    Stablo* stablo = malloc(sizeof(Stablo));

    stablo = unesiLevi(stablo, 5);
    stablo = unesiDesni(stablo, 10);

    stablo->levi = unesiLevi(stablo->levi, 7);
    stablo->levi = unesiDesni(stablo->levi, 15);

    stablo->desni = unesiLevi(stablo->desni, 20);
    stablo->desni = unesiDesni(stablo->desni, 30);

    ispisi_sve(stablo);

    return 0;
}