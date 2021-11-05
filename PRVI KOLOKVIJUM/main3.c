#include <string.h>
#include <stdio.h>

#define MAX_SIZE 101

int main() {

    char string[MAX_SIZE];

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAX_SIZE, stdin);

    int brojMalih = 0, brojVelikih = 0;

    string[strlen(string) - 1] = '\0';

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] >= 'a' && string[i] <= 'z') {
            brojMalih++;
        } else if(string[i] >= 'A' && string[i] <= 'Z') {
            brojVelikih++;
        }
    }

    printf("Malih slova ima %d. Velikih slova ima %d. %s.", 
        brojMalih, 
        brojVelikih, 
        brojMalih < brojVelikih ? "Malih slova ima manje" : "Velikih slova ima manje"
    );

    return 0;
}