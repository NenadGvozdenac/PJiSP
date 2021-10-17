// Dat je niz A od maksimalno 10 pozitivnih celobrojnih elemenata. Učitati n elemenata a zatim:

// ispisati sadržaj celokupnog niza
// proveriti da li postoje parovi susednih elemenata za koje važi da su neparni
// Ograničenja:

// sprovesti zaštitu unosa nad podatkom n

#include <stdio.h>

#define MAXSIZE 10

int main() {

    int n = 0;

    do {

        printf("Unesite velicinu niza: ");
        scanf("%d", &n);

    } while(n < 1 || n > 10);

    int A[n];

    for(int i = 0; i < n; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < n - 1; i++) {

        if(A[i] % 2 != 0 && A[i+1] % 2 != 0) {
            printf("A[%d] i A[%d] su neparni : %d, %d\n", i, i+1, A[i], A[i+1]);
        }

    }

    return 0;
}