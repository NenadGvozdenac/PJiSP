#include <stdio.h>
#include <string.h>
#include <ctype.h>  

#define MAX 101

int main () {
    char str[MAX], bezrazmaka[MAX];
    int j = 0, brojac = 0;

    char nazad[MAX];

    printf("Unesite text (malim slovima): ");
    gets(str);

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] != ' ') {
            bezrazmaka[j] = str[i];
            j++;
            brojac++;
        }
    }

    bezrazmaka[brojac] = '\0';

    int k = brojac;

    for(int i = 0; i < brojac; i++) {
        nazad[i] = bezrazmaka[k-1];
        k--;
    }

    nazad[brojac] = '\0';

    printf("Prvi string je: %s\nDrugi string je: %s\n\n", bezrazmaka, nazad);

    for(int i = 0; i < brojac/2; i++) {
        if(nazad[i] != bezrazmaka[i]) {
            printf("NISU PALINDROM I KAKO SE ZOVE OVO STO RADIM\n");
            return -1;
        }
    }

    printf("JESU PALINDROM I KAKO SE ZOVE OVO STO RADIM\n");

    return 0;
}