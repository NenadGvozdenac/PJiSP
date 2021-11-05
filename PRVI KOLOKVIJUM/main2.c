#include <stdio.h>
#include <string.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING];

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAX_STRING, stdin);

    string[strlen(string) - 1] = '\0';

    int brojRazmaka = 1;

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == ' ')
            brojRazmaka++;
    }

    printf("Razmaka ima %d.", brojRazmaka);

    return 0;
}