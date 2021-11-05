#include <stdio.h>

int main() {

    int A = 5;  // deklarisemo vrednost A je 5

    int* pointer;   // deklaracija vrednosti A

    // Ako probamo ispisivati vrednost ovoga pointera, koristimo %p
    printf("Pointer: %p", pointer);
    // Ispisuje vrednost adrese u memoriji ovoga pointera

    // Ako hocemo da postavljamo vrednost na referencu A, postavljamo ga ovako
    pointer = &A;

    // Pokazujemo vrednosti, pointer je promenio memorijsku lokaciju i vrednost
    printf("\nPointer A: %p, Vrednost %d, A: %d", pointer, *pointer, A);

    *pointer = 8;
    // Ovim smo promenili vrednost *pointera na 8
    printf("\nPointer A: %p, Vrednost %d, A: %d", pointer, *pointer, A);

    A = 15;
    // Sada smo promenili vrednost A na 15
    printf("\nPointer A: %p, Vrednost: %d, A: %d", pointer, *pointer, A);

    int B = 20;

    pointer = &B;

    // Pokazujemo vrednosti, pointer je promenio memorijsku lokaciju i vrednost
    printf("\nPointer B: %p, Vrednost: %d, B: %d", pointer, *pointer, B);

    // Menjamo vrednost B-a na 30 da isprobamo 
    B = 30;
    
    printf("\nPointer B: %p, Vrednost: %d, B: %d", pointer, *pointer, B);

    return 0;
}