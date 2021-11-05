#include <stdio.h>

#define KOD int main() {float PRVI, DRUGI; int OPERACIJA; printf("Unesite parametar 1: ");scanf("%f", &PRVI);printf("Unesite parametar 2: ");scanf("%f", &DRUGI);printf("Unesite operaciju (1 - Mnozenje, 2 - Deljenje): ");scanf("%d", &OPERACIJA);float REZULTAT = 0;switch(OPERACIJA) {case 1:for(int i = 0; i < DRUGI; i++) {REZULTAT += PRVI;}break;case 2:while(PRVI >= DRUGI) {REZULTAT++;PRVI -= DRUGI;}break;default:printf("Pogresna operacija.\n");return -1;}printf("Rezultat je: %.1f!\n", REZULTAT);return 0;}
KOD;