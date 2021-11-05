#include <stdio.h>

#define MAXSIZE 30

int main() {

    int N = 0;

    do {
        printf("Unesite N: ");
        scanf("%d", &N);

    } while(N < 1 || N > MAXSIZE);

    int A[N];

    for(int i = 0; i < N; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    int cekanje = 0;

    for(int i = 0; i < N; i++) {
        cekanje += A[i];
        printf("Korisnik %d ce cekati %d sekundi.\n", i, cekanje);
    }

    return 0;
}