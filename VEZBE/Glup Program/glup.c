/*
    Jedan radnik odredjeni posao uradi za M dana, a drugi radnik isti posao uradi za N dana.
    Napisati program kojim se odredjuje za koliko dana bi taj posao bio zavrsen ako bi radili zajedno.
    Vrednosti M i N se unose sa tastature.

*/

#include <stdio.h>

int main() {

    int N, M;

    do {
        printf("Unesite N: ");
        scanf("%d", &N);
    }  while(N < 1);

    do {
        printf("Unesite M: ");
        scanf("%d", &M);
    }  while(M < 1);

    double A = (double)1/M, B = (double)1/N;

    printf("Posao bi bio gotov za %.2lf dana.", 1 / (A + B) );

    return 0;
}