// Unosom sa tastature je zadat niz X od maksimalno 50 celobrojnih elemenata. 
// Učitati n elemenata u niz X i formirati nizove A i B, pri čemu su elementi niza A parni elementi niza X, a elementi niza B su elementi niza X sa neparnim indeksom (1,3,5,…).
// Izračunati SRVA srednju vrednost niza A. Na izlazu štampati elemente nizova A, B i SRVA srednju vrednost niza A.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 50

int main(int argn, char* argv[]) {

    int broj_elemenata = 0;
    double sum = 0;

    do {
        printf("Unesite broj elemenata: ");
        scanf("%i", &broj_elemenata);
    } while(broj_elemenata < 1 || broj_elemenata > MAXSIZE);

    int X[broj_elemenata], A[broj_elemenata/2], B[broj_elemenata/2];

    for(int i = 0; i < broj_elemenata; i++) {
        printf("Element X[%d]: ", i);
        scanf("%d", &X[i]);
    }

    printf("-------------\n");

    for(int i = 0, j = 0; i < broj_elemenata; i+=2, j++) {
        A[j] = X[i];
        B[j] = X[i+1];

        sum += (double)A[j];
    } 

    for(int i = 0; i < (broj_elemenata % 2 == 0 ? broj_elemenata / 2 : broj_elemenata / 2 + 1); i++) {
        printf("Element A[%d]: %d.\t", i, A[i]);

        if(broj_elemenata % 2 != 0 && i != broj_elemenata / 2) 
            printf("Element B[%d]: %d.\n", i, B[i]);
    }

    printf("\nSuma skupa A je: %.2lf.", sum = (broj_elemenata % 2 == 0) ? sum / (broj_elemenata / 2) : sum / (broj_elemenata / 2 + 1));

    return EXIT_SUCCESS;
}