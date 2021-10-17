// Dat je niz A od maksimalno 15 celobrojnih elemenata. 
// Učitati n elemenata a zatim naći 2 elementa čiji je zbir najveći. 
// Sprovesti zaštitu unosa nad podatkom n. Ako se vrši sortiranje, svejedno je koji će se algoritam koristiti.

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 15

void ispis(int* niz, int brEl) {

    for(int i = 0; i < brEl; i++) {
        printf("Element A[%i]: %i\n", i, niz[i]);
    }

}

int main() {

    int brojEl = 0;

    do {
        printf("Unesite broj elemenata: ");
        scanf("%i", &brojEl);

    } while(brojEl < 1 || brojEl > MAXSIZE);

    int* A = malloc(brojEl * sizeof(int));

    for(int i = 0; i < brojEl; i++) {
        printf("Element A[%i]: ", i);
        scanf("%i", &A[i]);
    }

    for(int i = 0; i < brojEl - 1; i++) {
        for(int j = 0; j < brojEl - i - 1; j++) {
            if(A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    ispis(A, brojEl);
    
    printf("Najveci zbir je: %i", A[brojEl-1] + A[brojEl - 2]);

    return 0;
}