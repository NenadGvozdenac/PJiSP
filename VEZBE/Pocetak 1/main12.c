// Dati su prirodni brojevi n, m (n <= m). Napisati program koji određuje koji
// od brojeva od n do m predstavljaju prestupne godine. Godina je prestupna
// ukoliko je zadovoljen sledeći skup uslova:
// 1. broj godine je deljiv sa četiri, i
// 2. važi jedno od sledećih pravila:
// • broj godine nije deljiv sa 100
// • broj godine je deljiv sa 400

#include <stdio.h>

void ispisi_prestupne(int poc, int kraj) {

    for(int i = poc; i <= kraj; i++) {

        if(i % 4 == 0) {

            if(i % 100 != 0 || i % 400 == 0) {
                printf("%d godina je prestupna.\n", i);
            } 
            
        }

    }

}

int main() {

    int pocGodina, krajGodina;

    do {

        printf("Unesite N: ");
        scanf("%d", &pocGodina);

        printf("Unesite M: ");
        scanf("%d", &krajGodina);

    } while(pocGodina > krajGodina);

    ispisi_prestupne(pocGodina, krajGodina);

    return 0;
}