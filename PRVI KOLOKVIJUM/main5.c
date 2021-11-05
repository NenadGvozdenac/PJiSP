#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING 101

int main() {

    char string[MAX_STRING];
    int N;

    printf("Unesite string (max 100 karaktera): ");
    fgets(string, MAX_STRING, stdin);

    fflush(stdin);
    printf("Unesite N: ");
    scanf("%d", &N);

    N--;

    string[strlen(string) - 1] = '\0';

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == ' ' && N) {
            N--;
        } else if(string[i] != ' ' && !N) {
            printf("%c", string[i]);
        } else if(string[i] == ' ') {
            N = -1;
        }
    }

    return 0;
}