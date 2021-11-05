// Zadatak 6. Uneti prirodan broj n i proveriti da li je savrˇsen. Broj je
// savrˇsen ako je jednak zbiru svojih delilaca (ukljuˇcuju´ci i 1, bez njega
// samog). Izvrˇsiti zaˇstitu unosa. Na izlazu ispisati sve delioce i ako je
// broj savrˇsen ispisati ”broj je savrˇsen”, inaˇce ispisati ”broj nije savrˇsen”.
// Primer: 28 = 1 + 2 + 4 + 7 + 14 broj je savrˇsen

#include <stdio.h>

int main() {

    int n = 0;

    printf("Unesite N: ");
    scanf("%d", &n);

    int sum = 1;

    printf("1");

    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            sum += i;
            printf(" + %d", i);
        }
    }

    printf(" = %d", sum);

    if(sum == n)
        printf("\nSavrsen broj!\n%d == %d", n, sum);
    else
        printf("\nNije savrsen broj!\n%d != %d", n, sum);
    
    return 0;
}