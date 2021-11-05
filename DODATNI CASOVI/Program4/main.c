#include <stdio.h>
#include <math.h>

int main() {

    int n = 0;

    printf("Unesite N: ");
    scanf("%d", &n);

    double sum = 0, A = 0, B = 1;

    for(int i = 0; i < n - 1; i++) {

        A = pow(-1, i);

        for(int j = 1; j <= i; j++) {
            B *= j;
        }

        sum += (A / B);

        printf("%.2lf/%.2lf\n", A, B);

        B = 1;
        A = 0;
    }

    printf("1/e = %.3lf", sum);

    return 0;
}