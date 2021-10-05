#include <stdio.h>

double povrsinaKvadrata(double stranica) {
    return stranica * stranica;
}

int main() {
    
    double stranica = 0;

    printf("Unesite duzinu stranice kvadrata -> ");
    scanf("%lf", &stranica);

    if(stranica < 0 || stranica > 100) {
        printf("Stranica kvadrata je nevazeca.");
        return 0;
    }

    printf("Povrsina kvadrata je : %.1lf", povrsinaKvadrata(stranica));

    return 1;
}