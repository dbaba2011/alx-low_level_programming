#include "search_algos.h"

int binary_search_recursion(int *array, int value,
			    size_t low, size_t high);

/**
 * @array: pointer to first element of array to seach
 * @value: value to search for
 * @low: starting index in array
 * @high: ending index in array
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */
int binary_search_recursion(int *array, int value,
			    size_t low, size_t high)
{
	size_t mid_value, i;

	if (!array)
		return (-1);

	mid_value = (low + high) / 2;
	printf("Searching in array: ");
	for (i = low; i <= high; i++)
		printf("%i%s", array[i], i == high ? "\n" : ", ");

	if (array[low] == value)
		return ((int)low);

	if (array[low] != array[high])
	{
		if (array[mid_value] < value)
			return (binary_search_recursion(array, value,
							mid_value + 1, high));
		if (array[mid_value] >= value)
			return (binary_search_recursion(array, value,
							low, mid_value));
	}

	return (-1);
}

/**
 * @array: pointer to first element of array to search
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t low_value = 0;
	size_t high_value = size - 1;

	if (!array)
		return (-1);

	return (binary_search_recursion(array, value, low_value, high_value));
}
