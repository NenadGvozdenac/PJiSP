#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void split(const char* string, char c) {

    size_t velicina = strlen(string);

    int kolicina_reci = 1;

    for(int i = 0; i < velicina; i++) {
        if(string[i] == ' ') {
            kolicina_reci++;
        }
    }

    printf("Kolicina reci u stringu je: %d!\n", kolicina_reci);

    char niz_reci[5][10];

    for(int i = 0, j = 0, k = 0; i < strlen(string); i++) {
        if(string[i] != ' ') {
            niz_reci[j][k] = string[i];
            k++;
            printf("%c DODAT\n", niz_reci[j][k]);
        }

        if(string[i] == ' ') {
            j++;
            k=0;
            i++;
        }
    }

    for(int i = 0; i < velicina; i++) {
        printf("%s!\n", niz_reci[i]);
    }

}

int main() {
    
    const char* string = "Cao ja sam Nenad Gvozdenac.";

    split(string, ' ');

    return 0;
}