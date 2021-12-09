#include <stdio.h>

void iterativno_resenje(int* niz, int brojac) {
    for(int i = 2; i < brojac; i++) {
        niz[i] = niz[i-1] + niz[i-2];
    }
}

void ispisi_resenje(int* niz, int brojac) {
    for(int i = 0; i < brojac; i++) {
        printf("%d = %d\n", i, niz[i]);
    }
}

int main() {

    int fib[24], i=0;

    fib[0] = 0;
    fib[1] = 1;

    printf("Unesite broj: ");
    scanf("%d", &i);

    iterativno_resenje(fib, i);
    ispisi_resenje(fib, i);

    return 0;
}