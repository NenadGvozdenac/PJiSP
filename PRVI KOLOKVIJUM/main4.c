#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING], string1[MAX_STRING];

    int brojac = 0;

    bool prvi_put_space;

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAX_STRING, stdin);

    string[strlen(string) - 1] = '\0';

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] != ' ') {
            string1[brojac] = string[i];
            brojac++;
            prvi_put_space = true;
        } else if(string[i] == ' ') {
            if(prvi_put_space) {
                string1[brojac] = string[i];
                brojac++;
                prvi_put_space = false;
            }
        }
    }

    string1[brojac] = '\0';

    if(string1[brojac - 1] == ' '){
        string1[brojac-1] = '\0';
    }

    printf("Novi string je '%s'.", string1);

    return 0;
}