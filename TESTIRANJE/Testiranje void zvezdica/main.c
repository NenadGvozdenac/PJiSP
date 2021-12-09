#include <stdio.h>



void vrsta(void* VREDNOST) {

    int* A = __INT8_TYPE__(VREDNOST);

}

int main() {

    int A = 5;

    vrsta(A);

    return 0;
}