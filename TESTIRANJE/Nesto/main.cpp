#include <stdio.h>

#include <iostream>

#define MAX_SIZE 30 //kopirao samo

int main() {
	int a[MAX_SIZE];
	int i, j, n, max, max_idx, min, min_idx;
	int c, d;
	
	do {
	printf("Broj clanova niza: ");
	scanf("%d", &n);
	} while (n < 0 || n >= MAX_SIZE);
	
	for (i = 0; i < n; i ++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("\na = {");
	for (i = 0; i < n; i++) {
		if (i < n - 1) {
			printf("%d, ", a[i]);
		} else {
			printf("%d", a[i]);
		}
	}
	printf("}\n");
	
	min = a[0]; 
    max = a[0];

	for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
            }
        }
    }

	printf("Unesite donje ogranicenje: ");
	scanf("%d", &c);
	
	printf("Unesite gornje ogranicenje: ");
	scanf("%d", &d);

	for(int i = 0; i < n; i++) {

		if(a[i] < c) {
			continue;
		}

		min_idx = a[i];
		break;
	}

	for(int i = n - 1; i > 0; i--) {

		if(a[i] > d) {
			continue;
		}

		max_idx = a[i];
		break;
	}
	
	printf("minimalna vrednost: %d\n", min_idx);
	printf("maksimalna vrednost: %d\n", max_idx);
	
	return 0;
}


