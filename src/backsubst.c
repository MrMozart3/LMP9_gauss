#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				if(mat->r != mat->c || mat->r < 1 || b->c != 1 || b->r != mat->r) {
								return 2;
				}
				for (int i = mat->r - 1; i >= 0; i--) {
					if (mat->data[i][i] == 0) {
						return 1;
					}
					double temp = b->data[i][0];
					for (int j = i + 1; j < mat->c; j++) {
						temp -= mat->data[i][j] * x->data[j][0];
					}
					x->data[i][0] = temp / mat->data[i][i];
				}
				return 0;
}


