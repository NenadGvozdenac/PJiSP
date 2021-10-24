/*
    Napisati program koji ispituje da li je dati prirodan broj n prost. Broj je
    prost ako je deljiv samo sa jedan i sa samim sobom.
*/

#include <stdio.h>

int main() {

    int A, nije_prost = 0;
    
    printf("Unesite A: ");
    scanf("%d", &A);

    for(int i = 2; i < A; i++) {
        if(A % i == 0) {
            nije_prost = 1;
        }
    }

    printf("Dat broj %d %s prost.", A, (nije_prost == 1) ? "NIJE" : "JESTE");

    return 0;
}