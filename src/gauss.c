#include "gauss.h"
#include "math.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	for (int j = 0; j < mat->c; j++) 
	{
		double max = 0;
		for (int i = j; i < mat->r; i++)
		{
			if(fabs(mat->data[i][j]) > max)
			{
				max = fabs(mat->data[i][j]);
			}
		}
		if (max == 0)
		{
			return 1;
		}
		if (mat->data[j][j] != max) {
			for (int i = j; i < mat->r; i++) {
				if (mat->data[i][j] == max) {
					double *temp = mat->data[i];
					mat->data[i] = mat->data[j];
					mat->data[j] = temp;
					double temp2 = b->data[i][0];
					b->data[i][0] = b->data[j][0];
					b->data[j][0] = temp2;
				}
			}
		}
		for (int i = j + 1; i < mat->r; i++)
		{
			double temp = mat->data[i][j] / mat->data[j][j];
			for (int k = j; k < mat->c; k++)
			{
				mat->data[i][k] -= mat->data[j][k] * temp;
			}
			b->data[i][0] -= b->data[j][0] * temp;
		}
	}
	return 0;
}

