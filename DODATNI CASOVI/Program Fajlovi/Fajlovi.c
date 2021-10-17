#include <stdio.h>
#include <stdlib.h>

FILE* safe_fopen(char filename[], char mode[]) {
    FILE* fp = fopen(filename, mode);

    if(fp == NULL) {
        printf("Nije moguce otvoriti fajl '%s'", filename);
        exit(1);
    }

    return fp;
}

void close_file(FILE* file) {
    fclose(file);
    printf("Fajl zatvoren.\n");
}

int main(int argn, char* argv[]) {

    if(argn < 0 || argn > 2) {
        printf("Lose unosenje fajla.\n");
        return -1;
    }

    FILE* file = safe_fopen(argv[1], "w");

    fprintf(file, "Dobar dan ja sam Nenad Gvozdenac.\n");

    close_file(file);
    return 0;
}