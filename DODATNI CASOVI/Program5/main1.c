/*
    Učitati broj članova reda (n) a zatim odrediti približnu vrednost broja 1/4 primenom sledeće matematičke formule:
    Ograničenja:

    sprovesti zaštitu unosa nad podatkom n
    sve realne promenljive trebaju biti tipa double
    ne koristiti promenljive tipa niz
*/


#include <stdio.h>

#define MAX_SIZE 20

int main() {

    int n = 0;

    do {    
        printf("Unesite broj clanova reda: ");
        scanf("%d", &n);
    } while(n < 1 || n > MAX_SIZE);

    double suma = 0;
    double B = 0;
    for(float i = 1; i <= (float) n; i++) {
        B = i*(i+1)*(i+2);
        suma += 1/B;
        printf("clan[i=%.1lf] = %lf\n", i, 1/B);

        B = 0;
    }

    printf("sum = %lf", suma);

    return 0;
}