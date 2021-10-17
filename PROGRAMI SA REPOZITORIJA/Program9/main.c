// Dat je niz A od maksimalno 15 dvocifrenih prirodnih brojeva. 
// Učitati n elemenata a zatim proveriti da li postoje parovi elemenata za koje važi da je zbir kvadrata njihovih cifara jednak. 
// Sprovesti zaštitu unosa nad podatkom n.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 15

int main() {

    int velicinaNiza = 0;

    do {
        printf("Unesite velinu niza: ");
        scanf("%d", &velicinaNiza);

    } while(velicinaNiza < 1 || velicinaNiza > MAXSIZE);

    int A[velicinaNiza];

    for(int i = 0; i < velicinaNiza; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);

        if(A[i] < 10 || A[i] > 99) {
            printf("Greska. Uneti podatak nije dvocifren!\n");
            i--;
        }
    }

    int D, J;
    int zbir = 0;
    int count = 0;

    for(int i = 0; i < velicinaNiza; i++) {
        D = A[i] / 10;
        J = A[i] % 10;

        zbir = pow(D, 2) + pow(J, 2);

        printf("Zbir A[%d] je: %d\n", i, zbir);
    }

    for(int i = 0; i < velicinaNiza; i++) {
        D = A[i] / 10;
        J = A[i] % 10;

        zbir = pow(D, 2) + pow(J, 2);

        for(int j = i + 1; j < velicinaNiza; j++) {

            int z = pow(A[j] / 10, 2) + pow(A[j] % 10, 2);

            if(z == zbir) {
                printf("Zbir A[%d] == Zbir A[%d] == %d\n", i, j, zbir);
                count++;
            }
        }
    }
    printf("Count : %d", count);

    return 0;
}