#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix of
 * integers.
 * @a: integer matrix.
 * @size: size of @a.
 */

void print_diagsums(int *a, int size)
{
	int i, sum_id, sum_di;

	for (i = 0, sum_id = 0; i < size * size; i += size + 1)
		sum_id += *(a + i);
	for (i = (size * size) - size, sum_di = 0; i > 0; i -= (size - 1))
		sum_di += *(a + i);
	printf("%d, %d\n", sum_id, sum_di);
}
