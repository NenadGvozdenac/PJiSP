#include <stdio.h>

int main() {

    long long n = 0;

    printf("Unesite N: ");
    scanf("%d", &n);

    while(1) {

        if(n % 2 == 0) {
            n = n / 2;
        } else if(n % 2 == 1) {
            n = 3 * n + 1;
        } 
        
        if(n == 1) {
            printf("%d ", n);
            break;
        }

        printf("%d ", n);
    }

    return 0;
}