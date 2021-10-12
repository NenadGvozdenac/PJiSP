// Dat je niz A od maksimalno 15 celobrojnih elemenata. 
// Učitati n elemenata a zatim naći 2 elementa čija je razlika najveća. 
// Sprovesti zaštitu unosa nad podatkom n. 
// Ako se vrši sortiranje, svejedno je koji će se algoritam koristiti.

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15

int* sortiraj(int* niz, int brEl) {

    for(int i = 0; i < brEl - 1; i++) {
        for(int j = 0; j < brEl - i - 1; j++) {

            if(niz[j] < niz[j+1]) {
                int temp = niz[j];
                niz[j] = niz[j+1];
                niz[j+1] = temp;
            }

        }
    }

    return niz;
}

int main() {

    int brojEl = 0;

    do {
        printf("Unesite broj elemenata: ");
        scanf("%i", &brojEl);
    } while(brojEl < 1 || brojEl > MAXSIZE);

    int* A = malloc(sizeof(int) * brojEl);

    for(int i = 0; i < brojEl; i++) {
        printf("Unesite A[%i]: ", i);
        scanf("%i", &A[i]);
    }

    A = sortiraj(A, brojEl);

    printf("\n");
    for(int i = 0; i < brojEl; i++) {
        printf("Element A[%i]: %i\n", i, A[i]);
    }

    printf("Najveca razlika je : %i.", A[0] - A[brojEl - 1]);

    return 0;
}