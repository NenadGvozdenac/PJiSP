// Dat je niz A od maksimalno 10 celobrojnih elemenata. Učitati n elemenata a zatim:

// 1. ispisati sadržaj celokupnog niza, od poslednjeg elementa ka početnom
// 2. odrediti i ispisati kvadratnu sredinu celokupnog niza (KS)
// 3. odrediti i ispisati aritmetičku sredinu elemenata niza koji su na neparnim indeksima (AS)

// Ograničenja:
// - sprovesti zaštitu unosa nad podatkom n
// - sve realne promenljive trebaju biti tipa double
// - sve realne brojeve ispisivati zaokružene na 2 decimale

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXSIZE 10

int main() {

    int broj_elemenata = 0, br_neparnih = 0;

    double KS = 0, AS = 0;

    do {
        printf("n = ");
        scanf("%i", &broj_elemenata);

    } while(broj_elemenata < 1 || broj_elemenata > MAXSIZE);

    int* A = malloc(sizeof(int) * broj_elemenata);

    for(int i = 0; i < broj_elemenata; i++) {
        printf("Unesite A[%i] element: ", i);
        scanf("%i", &A[i]);

        if(i % 2 != 0) {
            AS += (double)A[i];
            br_neparnih++;
        }
        KS += pow(A[i], 2);
    }

    AS = AS / br_neparnih;
    KS = sqrt(KS / broj_elemenata);

    for(int i = broj_elemenata - 1; i >= 0; i--) {
        printf("A[%i] = %i\n", i, A[i]);
    }

    printf("\n");

    printf("KS = %.2lf\nAS = %.2lf", KS, AS);

    return EXIT_SUCCESS;
}