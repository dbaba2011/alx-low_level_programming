#include "search_algos.h"
/**
 * linear_search - uses the linear search algorithim to find an element
 * in an array
 * @array: array to search for element
 * @value: value to be searched for
 * @size: size of array
 * Return: index of value else -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
