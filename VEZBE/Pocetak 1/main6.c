#include <stdio.h>

int main() {

    int n;

    printf("Unesite N: ");
    scanf("%d", &n);

    int sum = 1;

    while(n > 1) {
        sum *= n;
        n--;
    }

    printf("Faktorijel je: %d", sum);

    return 0;
}