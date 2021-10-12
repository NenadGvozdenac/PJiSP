/*
 Unosom sa tastature je zadat niz A, neoznačenih celih brojeva od maksimalno 30 elemenata. Transformisati niz (bez pomoćnog) tako da se svaki element niza pojavi samo jednom.
 Na izlazu štampati broj elemenata zadatog niza, elemente zadatog niza, broj elemenata transformisanog niza i elemente niza.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

int postoji_u_nizu(int niz[], int brel, int el) {
    for(int i = 0; i < brel; i++) {
        if(el == niz[i]) {
            return 1;
        }
    }

    return 0;
}

void ispis(int niz[], int brel, char c) {
    printf("-------------\n");
    for(int i = 0; i < brel; i++) {
        printf("Element %c[%d]: %d\n", c, i, niz[i]);
    }
    printf("-------------\n");
}

void sortiraj(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int niz[], int brel) {

    for(int i = 0; i < brel - 1; i++) {
        for(int j = 0; j < brel - i - 1; j++) {
            if(niz[j] > niz[j+1]) {
                sortiraj(&niz[j], &niz[j+1]);
            }
        }
    }

}

int main(int argn, char* argv[]) {

    int velicina_niza = 0;

    do {
        printf("Unesite velicinu niza: ");
        scanf("%d", &velicina_niza);
    } while(velicina_niza < 1 || velicina_niza > MAXSIZE);

    unsigned int *A = malloc(velicina_niza * sizeof(unsigned));

    // UNOS A NIZA
    for(int i = 0; i < velicina_niza; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    ispis(A, velicina_niza, 'A');

    unsigned *B = malloc(velicina_niza * sizeof(unsigned));
    int k = 0, pronasao = 0, prvi_put_video = 1;

    for(int i = 0; i < velicina_niza; i++) {
        for(int j = 0; j < velicina_niza; j++) {
            if (i == j) continue;

            if(A[i] == A[j]) {

                if(postoji_u_nizu(B, k, A[i])) {
                    pronasao = 0;
                } else {
                    pronasao = 1;
                }

                break;
            } else {
                pronasao = 1;
            }
        }

        if(pronasao == 1) {
            B[k] = A[i];
            k++;
            pronasao = 0;
        }
    }

    // ako zelimo sortirati, ovo unchekirati
    sort(B, k);

    ispis(B, k, 'B');

    return 0;
}