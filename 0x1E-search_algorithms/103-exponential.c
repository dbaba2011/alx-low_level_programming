#include "search_algos.h"

int binary_search_helper(int *array, int value,
			 size_t low, size_t high);
size_t min(size_t a, size_t b);

/**
 * @a: first value
 * @b: second value
 *
 * Return: `a` if lower or equal to `b`, `b` otherwise
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * @array: pointer to first element of array to seach
 * @value: value to search for
 * @low: starting index
 * @high: ending index
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int binary_search_helper(int *array, int value,
			 size_t low, size_t high)
{
	size_t mid_value, i;

	if (!array)
		return (-1);

	while (low <= high)
	{
		mid_value = (low + high) / 2;
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
			printf("%i%s", array[i], i == high ? "\n" : ", ");
		if (array[mid_value] < value)
			low = mid_value + 1;
		else if (array[mid_value] > value)
			high = mid_value - 1;
		else
			return ((int)mid_value);
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

int exponential_search(int *array, size_t size, int value)
{
	size_t low_value, high_value, bound_value = 1;

	if (!array || size == 0)
		return (-1);

	while (bound_value < size && array[bound_value] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound_value, array[bound_value]);
		bound_value *= 2;
	}

	low_value = bound_value / 2;
	high_value = min(bound_value, size - 1);
	/* 'found' message generated even if array[high_value] < value */
	printf("Value found between indexes [%lu] and [%lu]\n", low_value, high_value);
	return (binary_search_helper(array, value, low_value, high_value));
}
