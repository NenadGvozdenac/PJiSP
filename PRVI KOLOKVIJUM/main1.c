#include <stdio.h>
#include <string.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING];

    printf("Unesite string (max 101 karaktera): ");
    fgets(string, MAX_STRING, stdin);

    string[strlen(string) - 1] = '\0';
    
    for(int i = 2; i < strlen(string); i+=3) {
        if(string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        } else if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        } else continue;
    }

    printf("String je '%s'.", string);

    return 0;
}