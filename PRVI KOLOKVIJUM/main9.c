#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING], slovo;

    int brojac = 0;

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAX_STRING, stdin);
    fflush(stdin);

    string[strlen(string) - 1] = '\0';

    printf("Unesite slovo repeticije: ");
    scanf("%c", &slovo);

    for(int i = 0; i < strlen(string); i++) {
        if(strlwr(string)[i] == slovo) {
            brojac++;
        }
    }

    printf("Slovo '%c' se ponavlja %d puta.", slovo, brojac);

    return 0;
}