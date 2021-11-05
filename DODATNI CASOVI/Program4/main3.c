#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101 //100 karaktera i \o

int main() {

    // Deklaracija stringa
    char str[MAX_SIZE];

    // Unos stringa preko fgets() metode
    printf("Unesite string: ");
    fgets(str, MAX_SIZE, stdin);
    fflush(stdin);

    // Ispisivanje originalnog stringa, ima \n na kraju
    printf("Originalan string je: %s\n", str);
    // Ispisivanje velicine originalnog stringa sa \n. Prebrojava sve karaktere koji postoje
    printf("Velicina stringa je: %d\n", strlen(str));

    // Nacin otklanjanja \n u stringu, postavljanje \0 na mesto \n, te brisajuci ga
    str[strlen(str)-1] = '\0';

    // Ispisivanje novog stringa, vidimo da nema vise entera
    printf("Novi string je: %s\n", str);
    // Ispisivanje velicine stringa, vidimo da je za jedan manja
    printf("Nova velicina stringa je: %d\n", strlen(str));

    /*
        Bitne funkcije za rad sa stringovima
    */

    // int strcmp(const char*, const char*);  
    // funkcija koja kao povratni tip vraca integer.
    // Mogucnosti vracanja su -1, 0 i 1
    // vraca 0 ako su oba stringa identicki ista, vraca -1 ako je (po ascii tabeli) prvi string veci od drugog, a 1 ako je drugi veci od prvog

    char niz1[] = "Prvi string";
    char niz2[] = "Drugi string";

    int rezultat = strcmp(niz1, niz2);

    if(rezultat == 0)
        printf("Stringovi su isti.\n");
    else
        printf("Stringovi nisu isti.\n");

    // char* strcpy(const char*, const char*);
    // funkcija koja kopira drugi parametar (niz) u prvi (niz)
    // Vraca char*, medjutim obicno se koristi kao void

    char niz3[] = "Prvi niz";
    char niz4[15];

    strcpy(niz4, niz3);

    printf("Kopirani niz: %s\n", niz4);

    // char* strstr(const char*, const char*);
    // funkcija koja proverava da li je substring (drugi niz) u stringu (prvom nizu)
    // vraca char*, ako nije NULL onda znaci da on postoji tamo, inace ne postoji

    char niz5[] = "Fakultet Tehnickih Nauka";
    char niz6[] = "Tehnickih";

    if(strstr(niz5, niz6) != NULL) {
        printf("U stringu %s, postoji string %s.\n", niz5, niz6);
    }

    // void puts(const char*);
    // funkcija koja ispisuje string na ekran, radi similarno kao i printf()
    
    char niz7[] = "Dobar dan";
    strupr(niz7);
    puts(niz7);

    return 0;
}