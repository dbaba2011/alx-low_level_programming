#include "search_algos.h"
/**
 * binary_search- implementation of the binary search algorithim
 * @array: array to search
 * @size: size of array
 * @value: value to search
 * Return: index of value
 */
int binary_search(int *array, size_t size, int value)
{
	int val;

	if (array == NULL)
		return (-1);
	val = helper_binary(array, 0, size - 1, value);
	return (val);
}

/**
 * helper_binary-helper function for binary search
 * @array: arrar to search
 * @left: pointer to left
 * @right: pointer to the right
 * @value: value to search for
 * Return: index of value
 */
int helper_binary(int *array, size_t left, size_t right, int value)
{
	size_t mid = (right + left) / 2;

	if (left > right)
		return (-1);
	print_array(array, left, right);
	if (array[mid] == value)
		return (mid);
	else if (value > array[mid])
	{
		left = mid + 1;
		return (helper_binary(array, left, right, value));
	}
	else
	{
		right = mid - 1;
		return (helper_binary(array, left, right, value));
	}
	return (-1);
}
/**
 * print_array - prints the array
 * @array: array to search]
 * @start: start of the array
 * @end: end of the array
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}
