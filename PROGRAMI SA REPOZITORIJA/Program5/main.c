// Unosom sa tastature je zadat niz X od maksimalno 30 celobrojnih elemenata. 
// Naci broj elemenata niza cija je vrednost veca od srednje vrednosti niza. 
// Na izlazu štampati niz X, srednju vrednost niza (SRVX) i broj elemenata niza cija je vrednost veca od srednje vrednosti niza.

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

int main() {

    int brojEl;
    double SRVX = 0;
    int veciodSRVX = 0;

    do {
        printf("Unesite broj elemenata: ");
        scanf("%i", &brojEl);

    } while(brojEl < 1 || brojEl > MAXSIZE);

    int A[brojEl];

    for(int i = 0; i < brojEl; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%i", &A[i]);

        SRVX += (float)A[i];
    }

    for(int i = 0; i < brojEl; i++) {
        printf("A[%d]: %d\n", i, A[i]);
    }

    SRVX = SRVX / (float)brojEl;

    printf("Srednja vrednost X je: %.2lf\n", SRVX);

    for(int i = 0; i < brojEl; i++) {
        if((float)A[i] > SRVX) {
            printf("Element A[%d], (%d) je veci od srednje vrednosti %.2lf.\n", i, A[i], SRVX);
            veciodSRVX++;
        }
    }

    printf("Elemenata vecih od srednje vrednosti niza ima %d.\n", veciodSRVX);

    return 0;
}