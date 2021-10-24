// Napisati program koji pronalazi prvi element niza koji je najbliži srednjoj
// vrednosti niza celih brojeva. Niz može da ima najviše 20 elemenata.

#include <stdio.h>
#include <math.h>

#define MAXSIZE 20

int main() {

    int brEl;

    do {

        printf("Unesite broj elemenata: ");
        scanf("%d", &brEl);

    } while(brEl < 1 && brEl > MAXSIZE);

    int A[brEl], sum = 0;

    for(int i = 0; i < brEl; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("\n");

    for(int i = 0; i < brEl; i++) {
        sum += A[i];
    }

    int kanta = 0;

    for(int i = 0; i < brEl - 1; i++) {
        for(int j = 0; j < brEl - 1 - i; j++) {
            if(A[j] > A[j+1]) {
                kanta = A[j];
                A[j] = A[j+1];
                A[j+1] = kanta;
            }
        }
    }

    float suma = (float) sum / brEl;
    int br = 0;

    float minRazlika = fabs(suma - A[0]);

    for(int i = 0; i < brEl; i++) {
        if(fabs(suma - A[i]) < minRazlika) {
            minRazlika = fabs(suma - A[i]);
            br = A[i];
        }
    }

    printf("Suma je %.2f\nMinimalna razlika od sredine je: %.2f\nNajblizi broj je %d", suma, minRazlika, br);

    return 0;
}