#include <stdio.h>
#include <stddef.h>
#define MAX 30

int main () {

	int X[MAX], num1, num2, min_indx, max_indx, temp;
	int i, j, n;
	
	do {	
        printf("unesi broj elemenata niza: ");
		scanf("%d", &n);
	} while (!(n > 0 && n <= MAX));
	
	printf("Unesi vrednosti niza: \n");
	for (i = 0; i < n; i++) {
		printf("X[%d] = ", i);
		scanf("%d", &X[i]); 
	}

	num1 = X[i];
	num2 = X[i]; 
	
	for(i = 0;i < n-1; i++){
		max_indx = i;
		for (j = i + 1; j < n; j++) 
			{ if (X[max_indx] > X[j]) { 
                    max_indx = j;
			    }
			}
		temp = X[i];
		X[i] = X[max_indx];
		X[max_indx] = temp;
	}
	printf("\n\n\n");
	for (i = 0; i < n; i++) {
		printf("X[%d] = %d \t", i, X[i]);
		printf("\n");
    	}
    	
	num1 = X[0];
	num2 = X[n-1];
	printf("max razlika je: %d - %d = %d\n", num1, num2, num1 - num2);
	num1 = X[n-1];
	num2 = X[n-2];
	printf("max zbir je: %d - %d = %d\n", num1, num2, num1 + num2);
	
	return 0;
}	