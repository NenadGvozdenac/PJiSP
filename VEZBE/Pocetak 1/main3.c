#include <stdio.h>
#include <math.h>

int main() {

    float A;

    printf("Unesite A: ");
    scanf("%f", &A);

    if(A < 0)
        printf("-7");
    else if(A >= 0 && A < 1) {
        printf("%f", (float)(4 + pow(A, 1.0/4.0)));
    } else if(A >= 1 && A < 13) {
        printf("%f", (float)(2 * sqrt((float)A) - 5));
    } else {
        printf("%f", (float)pow(A, 2) / 9);
    }

    return 0;
}