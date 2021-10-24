// Zadatak 7
// Napisati program kojim se štampaju svi trocifreni Armstrongovi brojevi.
// Broj je Armstrongov ako je jednak zbiru kubova svojih cifara.

#include <stdio.h>
#include <math.h>

int main() {

    int zbir = 0, cifra;

    for(int i = 1; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {

                cifra = i * 100 + j * 10 + 1 * k;

                if(cifra == (pow(k, 3) + pow(j, 3) + pow(i, 3))) {

                    printf("%d\n", cifra);

                    cifra = 0;

                }
            }
        }
    }

    return 0;
}