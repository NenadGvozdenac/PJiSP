#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "Ana voli milovana!";
    
    int brojac = 0;
    char str2[50];

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }

    printf("%s", str);

    for(int i = 0; i < strlen(str); i++) {

        if(str[i] == ' ')
            continue;
        else if(str[i] == '!' || str[i] == '?' || str[i] == '.' || str[i] == ',')
            continue;
        else {
            str2[brojac] = str[i];
            brojac++;
        }
    }

    for(int i = 0, j = strlen(str2) - 1; i < strlen(str2); i++, j--) {
        if(str2[i] != str2[j]) {
            printf("Nije palindrom.\n");
            return 0;
        }

        printf("%c == %c\n", str2[i], str2[j]);
    }

    printf("Jeste palindrom.\n");

    printf("%s", str2);

    return 0;
}