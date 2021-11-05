#include <stdio.h>
#include <math.h>

#define MAX_NIZ 20

int main() {

    int niz[MAX_NIZ], n = 0;

    do {
        printf("Unesite broj elemenata niza: ", n);
        scanf("%d", &n);
    } while(n < 1 || n > MAX_NIZ);

    for(int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &niz[i]);
    }

    float suma = 0;

    for(int i = 0; i < n; i++) {
        suma += (float)niz[i];
    }

    suma /= (float) n;

    printf("Srednja vrednost niza je %.2f.\n", suma);

    float trenutna_vrednost = fabs(suma - niz[0]), vrednost = 0;;

    for(int i = 1; i < n; i++) {
        if(fabs(suma - niz[i]) < trenutna_vrednost) {
            trenutna_vrednost = fabs(suma - niz[i]);
            vrednost = niz[i];
        }
    }

    printf("Najbliza vrednost je %.2f.\n", vrednost);

    return 0;
}