#include <stdio.h>
#define MAXSIZE 20

int main() {

    int n;

    do {
        printf("Unesite N: ");
        scanf("%d", &n);
    } while(n < 1 || n > MAXSIZE);

    int A[n];

    for(int i = 0; i < n; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(A[j] > A[j+1]) {
                int kanta = A[j];
                A[j] = A[j+1];
                A[j+1] = kanta;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    return 0;
}