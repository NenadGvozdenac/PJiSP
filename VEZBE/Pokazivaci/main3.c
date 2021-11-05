#include <stdio.h>

#define MAXSIZE 25

int main() {

    int n = 0, brNegativnih = 0, brPozitivnih = 0;

    do {
        printf("Unesite N: ");
        scanf("%d", &n);
    } while(n < 1 || n > MAXSIZE);

    int A[n];

    for(int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);

        if(A[i] < 0)    
            brNegativnih++;
        else
            brPozitivnih++;
    }

    int Negativni[brNegativnih], Pozitivni[brPozitivnih];

    int brojacNegativni = 0, brojacPozitivni = 0;

    for(int i = 0; i < n; i++) {
        if(A[i] < 0) {
            Negativni[brojacNegativni] = A[i];
            brojacNegativni++;
        } else {
            Pozitivni[brojacPozitivni] = A[i];
            brojacPozitivni++;
        }
    }

    printf("\nPozitivni niz je A[");

    for(int i = 0; i < brojacPozitivni; i++) {
        if(i != brojacPozitivni - 1)
            printf("%d, ", Pozitivni[i]);
        else
            printf("%d].\n", Pozitivni[i]);
    }

    printf("Negativni niz je B[");

    for(int i = 0; i < brojacNegativni; i++) {
        if(i != brojacNegativni - 1)
            printf("%d, ", Negativni[i]);
        else
            printf("%d].\n", Negativni[i]);
    }

    return 0;
}