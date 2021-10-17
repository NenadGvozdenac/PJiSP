#include <stdio.h>

int main() {
    int niz[10];
    int n;

    do {

        printf("Unesite velicinu niza: ");
        scanf("%d", &n);

    }   while(n < 1 || n > 10);

    return 0;
}