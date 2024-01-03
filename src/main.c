#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile("A");
	Matrix* b = readFromFile("B");
	if (A == NULL || b == NULL) {
		fprintf(stderr, "Błąd wczytywania macierzy.\n");
		return 1;
	}
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("Macierz A:\n");
	printToScreen(A);
	printf("Macierz b:\n");
	printToScreen(b);

	res = eliminate(A,b);
	if (res == 1) {
		fprintf(stderr, "Macierz Osobliwa.\n");
		return 1;
	}
	
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		printf("Macierz Wynikowa:\n");
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
