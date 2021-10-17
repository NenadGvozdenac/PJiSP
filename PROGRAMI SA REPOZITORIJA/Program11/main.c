// Dat je niz A od maksimalno 10 celobrojnih elemenata. Učitati n elemenata a zatim:

// učitati pozitivnu celobrojnu vrednost x
// ispisati sadržaj celokupnog niza
// odrediti koliko elemenata (počevši od kraja niza ka početku) je potrebno obuhvatiti da bi njihova suma bila veća od x
// Ograničenja:

// sprovesti zaštitu unosa nad podatkom n
// smatrati da će suma celokupnog niza A uvek biti veća od x

#include <stdio.h>

#define MAXSIZE 10

int main() {

    int n = 0;

    do {
        printf("Unesite velicinu niza (max %d): ", MAXSIZE);
        scanf("%d", &n);

    } while(n < 1 || n > MAXSIZE);

    int A[n];
    int x;

    printf("Unesite velicinu broja X: ");
    scanf("%d", &x);

    for(int i = 0; i < n; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    int sum = 0;

    for(int i = n - 1; i >= 0; i--) {
        sum += A[i];
        if(sum > x) {
            printf("sum(A[%d]: %d\n", i, sum);
            break;
        }

        printf("sum(A[%d]: %d\n", i, sum);
    }

    return 0;
}