#include <stdio.h>
#include <string.h>

#define MAXSIZE 101

int main() {

    char string[MAXSIZE], slovo, string1[MAXSIZE];
    int brojac = 0;

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAXSIZE, stdin);

    string[strlen(string) - 1] = '\0';

    printf("Unesite karakter: ");
    scanf("%c", &slovo);

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == slovo) {
            continue;
        }
        string1[brojac] = string[i];
        brojac++;
    }

    string1[brojac] = '\0';

    for(int i = 0; i < strlen(string1); i+=2) {
        if(strlen(string1) % 2 != 0) {
            if(i != strlen(string1) - 1) {
                char temp = string1[i];
                string1[i] = string1[i+1];
                string1[i+1] = temp;
            }
        } else {
            char temp = string1[i];
            string1[i] = string1[i+1];
            string1[i+1] = temp;
        }
    }

    printf("Nov string je '%s'.", string1);

    return 0;
}