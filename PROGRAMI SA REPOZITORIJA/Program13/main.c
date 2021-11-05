// Dat je niz A od maksimalno 10 celobrojnih elemenata. Učitati n elemenata a zatim:

// ispisati sadržaj celokupnog niza
// proveriti da li postoje parovi elemenata za koje važi da su po apsolutnoj vrednosti jednaki
// Ograničenja:

// sprovesti zaštitu unosa nad podatkom n

#include <stdio.h>
#include <math.h>

#define MAXSIZE 10

int main() {

    int n = 0;

    do {

        printf("Unesite broj elemenata niza (max 10): ");
        scanf("%d", &n);

    } while(n < 1 && n > MAXSIZE);

    int A[n];

    for(int i = 0; i < n; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(abs(A[i]) == abs(A[j])) {

                printf("abs(A[%d]) == abs(A[%d]) == %d\n", i, j, abs(A[i]));

            }
        }
    }

    return 0;
}