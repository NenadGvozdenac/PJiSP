#include <stdio.h>
#include <string.h>

int main(int argn, char* argv[]) {

    for(int i = 0; i < 5; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}