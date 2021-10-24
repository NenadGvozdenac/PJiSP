#include <stdio.h>
#include <math.h>

int main() {

    int A, B, C;

    printf("Unesite element A: ");
    scanf("%d", &A);

    printf("Unesite element B: ");
    scanf("%d", &B);

    printf("Unesite element C: ");
    scanf("%d", &C);

    float arit, harm, geom, kvad;

    arit = (A + B + C) / (float)3;

    geom = (float)pow((A*B*C), (float)1/3);

    kvad = sqrt((pow(A, 2) + pow(B, 2) + pow(C, 2)) / (float)3);

    harm = 3 / ((float)1/A + (float)1/B + (float)1/C);

    printf("Aritmeticka sredina je: %.3f\n", arit);
    printf("Geomertijska sredina je: %.3f\n", geom);
    printf("Kvadratna sredina je: %.3f\n", kvad);
    printf("Harmonijska sredina je: %.3f\n", harm);

    return 0;
}