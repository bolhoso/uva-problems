#include <stdio.h>

#define MAX 50

void parray (int *a, int l){
	printf (" ==> ");
	while (--l >= 0) {
		printf ("%d ", *(a++));
	}
	printf ("\n");
}

int sort (int *train, int len) {
	int i, j, aux;
	int xchanges = 0;

	i = 0;
	while (train[i] == i - 1) {
		i++;
	}
			
	while (i < len - 1) {
		for (j = i + 1; j < len; j++) {
			if (train[i] > train[j]) {

				aux = train[i];
				train[i] = train [j];
				train[j] = aux;

				xchanges++;

			}
		}
		
		i++;
	}

	return xchanges;
}

int main () {
	int nof_tests;

	scanf ("%d\n", &nof_tests);
	while (nof_tests > 0) {
		nof_tests--;

		int length ,train [MAX];
		scanf ("%d\n", &length);

		int i;
		for (i = 0; i < length; i++) {
			scanf ("%d\n", &(train [i]));
		}

		printf ("Optimal train swapping takes %d swaps.\n", sort (train, length));
	}

	return 0;
}
