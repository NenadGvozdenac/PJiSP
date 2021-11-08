#include <stdio.h>
#include <string.h>

#define MAXSIZE 23

int main() {

    char string[MAXSIZE], string1[MAXSIZE], string2[MAXSIZE];
    int brojac = 0, brojReci = 0;

    printf("Unesite string (max 22 karaktera): ");
    fgets(string, MAXSIZE, stdin);

    string[strlen(string) - 1] = '\0';

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] != ' ') {
            string1[brojac] = string[i];
            brojac++;
        }
        if(string[i] == ' ') {
            brojReci = 1;
            break;
        }
    }

    string1[brojac] = '\0';

    brojac = 0;

    for(int i = strlen(string) - 1; i >= 0; i--) {
        if(string[i] != ' ') {
            string2[brojac] = string[i];
            brojac++;
        }
        if(string[i] == ' ') {
            break;
        }
    }

    string2[brojac] = '\0';
    strrev(string2);

    if(brojReci != 0) {
        strcat(string1, " ");
        strcat(string1, string2);
    } else {
        strcpy(string2, string1);
        strcat(string1, " ");
        strcat(string1, string2);
    }

    for(int i = 0; i < strlen(string1); i++) {
        if(string1[i] >= 'a' && string1[i] <= 'z') {
            string1[i] -= 32;
        }
    }

    printf("Krajnji string: '%s'", string1);

    return 0;
}