#include <stdio.h>

int main() {

    int A, B, C;

    printf("Unesite A: ");
    scanf("%d", &A);
    
    printf("Unesite B: ");
    scanf("%d", &B);
    
    printf("Unesite C: ");
    scanf("%d", &C);

    int najmanji = A;

    if(B < najmanji) {
        najmanji = B;
    }

    if(C < najmanji) {
        najmanji = C;
    }

    if(A == B && B == C) {
        printf("Jednaki su svi");
        return 0;
    }

    printf("Najmanji je: %d", najmanji);


    return 0;
}