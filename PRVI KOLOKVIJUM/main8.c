#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING], string1[MAX_STRING];
    int j = 0;

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAX_STRING, stdin);

    string[strlen(string) - 1] = '\0';

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] != '?' && string[i] != '!') {
            string1[j] = string[i];
            j++;
        } else if(string[i] == '?') {
            string1[j] = '\0';
            strcat(string1, ", pitamo se.");
            j+=strlen(", pitamo se.");
        } else if(string[i] == '!') {
            string1[j] = '\0';
            strcat(string1, ", vicemo.");
            j+=strlen(", vicemo.");
        }
    }

    string1[j] = '\0';

    printf("Novi string je '%s'.", string1);

    return 0;
}