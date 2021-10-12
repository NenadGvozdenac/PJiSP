// Dat je celobrojni niz od maksimalno 30 elemenata. Obrnuti redosled elemenata u nizu (bez upotrebe pomoćnog niza) i zatim odštampati rezultat.

// Za sledeće ulazne podatke [3, 7, 4, 1, 5] rešenje je [5, 1, 4, 7, 3].

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 30

int main() {

    int brojEl;

    do {
        printf("Unesite broj elemenata niza A: ");
        scanf("%i", &brojEl);
    } while(brojEl < 1 || brojEl > 30);

    int A[brojEl];

    for(int i = 0; i < brojEl; i++) {
        printf("Unesite A[%i]: ", i);
        scanf("%i", &A[i]);
    }

    for(int i = 0, j = brojEl - 1; i < brojEl / 2; i++, j--) {
        if(i == j)  break;

        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    for(int i = 0; i < brojEl; i++) {
        printf("A[%i]: %i\n", i, A[i]);
    }

    return EXIT_SUCCESS;
}