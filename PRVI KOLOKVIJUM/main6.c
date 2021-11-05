#include <stdio.h>
#include <string.h>

#define MAX_STRING 101

int main() {

    char string1[MAX_STRING], string2[MAX_STRING];

    printf("Unesite prvi string (max 100 karaktera): ");
    fgets(string1, MAX_STRING, stdin);
    fflush(stdin);

    string1[strlen(string1) - 1] = '\0';

    printf("Unesite drugi string (max 100 karaktera): ");
    fgets(string2, MAX_STRING, stdin);
    fflush(stdin);

    string2[strlen(string2) - 1] = '\0';

    for(int i = 0; i < strlen(string2); i++) {
        if(string1[i] != string2[i]) {
            printf("Prvi string ne pocinje sa drugim stringom.\n");
            return -1;
        }
    }

    printf("Prvi string pocinje sa drugim stringom.\n");

    return 0;
}