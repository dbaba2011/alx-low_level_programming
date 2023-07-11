#include "search_algos.h"


/**
 * @list: pointer to the head of the skip list to traverse
 * @value: value to search for
 * Return: pointer on the first node where value is located, or NULL if list
 * is NULL or value not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp_value = NULL, *stop = NULL;

	if (!list)
		return (NULL);

	temp_value = list;
	while (temp_value && temp_value->express && temp_value->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       temp_value->express->index, temp_value->express->n);
		temp_value = temp_value->express;
	}
	stop = temp_value;
	while (stop && stop->next != stop->express)
		stop = stop->next;
	
	if (temp_value->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       temp_value->express->index, temp_value->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       temp_value->index, temp_value->express->index);
	}
	
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
		       temp_value->index, stop->index);

	while (temp_value != stop && temp_value->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       temp_value->index, temp_value->n);
		temp_value = temp_value->next;
	}
	printf("Value checked at index [%lu] = [%i]\n",
	       temp_value->index, temp_value->n);

	if (temp_value == stop)
		return (NULL);
	return (temp_value);
}

