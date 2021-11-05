#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING];

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAX_STRING, stdin);

    string[strlen(string) - 1] = '\0';

    for(int i = 0; i < strlen(string) - 2; i++) {
        if(string[i] == '.') {
            if(string[i + 1] == ' ' && (string[i + 2] >= 'A' && string[i + 2] < 'Z')) {
                continue;
            } else {
                printf("Postoji izuzetak, nakon svake tacke ne dolaze razmak i veliko slovo.\n");
                return -1;
            }
        }
    }

    printf("Nakon svake tacke dolaze razmak i veliko slovo.\n");

    return 0;
}