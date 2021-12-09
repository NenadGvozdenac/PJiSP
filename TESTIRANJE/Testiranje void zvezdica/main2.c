#include <stdio.h>

#define MAX_SIZE 30

void dodavanje(int a[], int *n){
	
	int i;

	do{
		printf("Unesite broj clanova niza: ");
		scanf("%d", n);
	} while(*n <= 0 || *n > MAX_SIZE);

	for(i = 0; i < *n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void ispis(int a[], int n) {

	int i;
	
	printf("[");
	for(i = 0; i < n; i++){
		if(i > 0){
			printf(", ");		
		}
		printf("%d", a[i]);
	}
	printf("]\n");
}

int suma_elemenata(int a[], int n) {
	
	int i, suma = 0;
	
	for(i = 0; i < n; i++){
		suma += a[i];
	}
	
	return suma;
}
	
float srednja_vrednost(int suma, int n){
	return (1.0*suma)/(1.0*n);
}

int minimum(int a[], int n){
	int i, min = a[0];
	
	for(i = 1; i < n; i++)
		if(min > a[i])
			min = a[i];
	
	return min;
}

int maksimum(int a[], int n){
	int i, max = a[0];
	
	for(i = 1; i < n; i++)
		if(max < a[i])
			max = a[i];

	return max;
}

int main(){
	
	int a[MAX_SIZE], n;

	dodavanje(a, &n);
	ispis(a, n);
	
	printf("\n\nSuma elemenata je: %d\n", suma_elemenata(a, n));
	printf("Srednja vrednost niza je: %.2f\n", srednja_vrednost(suma_elemenata(a, n), n));
	printf("Minimum niza je: %d\n", minimum(a, n));
	printf("Maksimum niza je: %d\n\n", maksimum(a, n));
	
	return 0;
}