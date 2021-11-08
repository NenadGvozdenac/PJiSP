#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIZE 81

int main() {

    char string[MAXSIZE];

    int brojSamoglasnika = 0, brojCifara = 0;

    printf("Unesite string (max 80 karaktera): ");
    fgets(string, MAXSIZE, stdin);

    string[strlen(string) - 1] = '\0';

    for(int i = 0; i < strlen(string); i++) {

        if(string[i] >= '0' && string[i] <= '9') {
            int broj = string[i] - 48;

            if(broj % 2 == 0) {
                printf("%d je parna cifra.\n", broj);
                brojCifara++;
            } 
        }

        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
            printf("%c je samoglasnik.\n", string[i]);
            brojSamoglasnika++;
        }
    }

    printf("parnih cifara = %d\n", brojCifara);
    printf("samoglasnika = %d\n", brojSamoglasnika);

    printf("vise_parnih_cifara = %d", brojCifara - brojSamoglasnika > 0 ? 1 : 0);

    return 0;
}