#include <stdio.h>

int main() {

    int A, B;

    printf("Unesite A: ");
    scanf("%d", &A);

    printf("Unesite B: ");
    scanf("%d", &B);

    printf("Veci od ta dva broja je: %d", (A > B) ? A : B);

    return 0;
}