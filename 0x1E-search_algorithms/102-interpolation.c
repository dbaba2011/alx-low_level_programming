#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using an interpolation search algorithm
 * @array: pointer to first element of array to search
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low_value = 0;
	size_t high_value = size - 1;
	size_t pos;

	if (!array)
		return (-1);

	while ((array[high_value] != array[low_value]) &&
	       (value >= array[low_value]) && (value <= array[high_value]))
	{
		pos = low_value + (((double)(high_value - low_value) / (array[high_value] - array[low_value]))
			    * (value - array[low_value]));
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] < value)
			low_value = pos + 1;
		else if (value < array[pos])
			high_value = pos - 1;
		else
			return (pos);
	}
	if (value == array[low_value])
	{
		printf("Value checked array[%lu] = [%d]\n", low_value, array[low_value]);
		return (low_value);
	}
	pos = low_value + (((double)(high_value - low_value) / (array[high_value] - array[low_value]))
		     * (value - array[low_value]));
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1);
}
