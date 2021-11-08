#include <stdio.h>
#include <string.h>

#define MAXSIZE 23

int main() {

    char string[MAXSIZE];

    printf("Unesite string (max 22 karaktera): ");
    fgets(string, MAXSIZE, stdin);

    string[strlen(string) - 1] = '\0';

    for(int i = 0, j = strlen(string) - 1; i < strlen(string) / 2; i++, j--) {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }

    printf("String : '%s'", string);

    return 0;
}