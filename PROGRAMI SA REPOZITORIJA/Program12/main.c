// Dat je niz A od maksimalno 10 celobrojnih elemenata. Učitati n elemenata a zatim:

// učitati celobrojnu vrednost x
// ispisati sadržaj celokupnog niza
// odrediti i ispisati verovatnoću da vrednost x bude odabrana slučajnim uzorkovanjem iz niza A (chance)
// Ograničenja:

// sprovesti zaštitu unosa nad podatkom n
// vrednost promenljive chance ispisati na 3 decimale


#include <stdio.h>

#define MAXSIZE 10

int main() {

    int n = 0;

    do {

        printf("Unesite kolicinu elemenata: ");
        scanf("%d", &n);

    } while(n < 1 || n > MAXSIZE);

    int x = 0;
    int A[n];

    printf("Unesite celobrojnu vrednost X: ");
    scanf("%d", &x);

    for(int i = 0; i < n; i++) {
        printf("Unesite element A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        if(x == A[i])
            count++;
    }

    double chance;

    printf("Sansa je: %.3lf", (double) count / n);

    return 0;
}