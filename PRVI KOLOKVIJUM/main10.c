#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING], string1[MAX_STRING], string2[MAX_STRING];

    int brojac = 0;

    bool za_unos = false;

    printf("Unesite prvi string (max 100 karaktera): ");
    fgets(string, MAX_STRING, stdin);
    fflush(stdin);

    string[strlen(string) - 1] = '\0';

    printf("Unesite drugi string (max 100 karaktera): ");
    fgets(string1, MAX_STRING, stdin);
    fflush(stdin);

    string1[strlen(string1) - 1] = '\0';

    for(int i = 0; i < strlen(string); i++) {

        za_unos = false;

        for(int j = 0; j < strlen(string1); j++) {

            if(string[i] == string1[j]) {
                za_unos = false;
                break;
            }

            za_unos = true;

        }

        if(za_unos) {
            string2[brojac] = string[i];
            brojac++;
        }

    }

    string2[brojac] = '\0';

    printf("Novi string je '%s'.", string2);

    return 0;
}