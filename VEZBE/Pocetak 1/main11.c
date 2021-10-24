// Napisati program koji učitava prirodan broj n, a zatim koristeći funkciju
// prost štampa sve proste brojeve manje od datog broja n.

#include <stdio.h>

void ispisi_proste(int n) {

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {

            if(i == j)  continue;

            if(i % j == 0) {
                break;
            } else if(j == n && i % j != 0) {
                printf("%d\n", i);
            }

        }
    }

}

int main() {

    int n;

    do {
        printf("Unesite N: ");
        scanf("%d", &n);

    } while(n < 1);

    ispisi_proste(n);

    return 0;
}