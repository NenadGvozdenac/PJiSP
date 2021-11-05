#include <stdio.h>

#define MAXSIZE 30

int main() {

    int n = 0;

    do {
        printf("Unesite broj elemenata: ");
        scanf("%d", &n);

    } while(n < 1 || n > MAXSIZE);

    int A[n], BR = 0, brojac = 0;

    printf("Unesite ceo broj BR: ");
    scanf("%d", &BR);

    for(int i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);

        if(A[i] == BR)
            brojac++;
    }

    printf("Broj %d se pojavljuje %d puta u nizu A = [", BR, brojac);
    
    for(int i = 0; i < n; i++) {
        if(i != n - 1)
            printf("%d, ", A[i]);
        else
            printf("%d].", A[i]);
    }

    return 0;
}