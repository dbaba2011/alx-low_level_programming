#include "search_algos.h"

/**
 * @list: A pointer to the  head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *node, *jump_value;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	step_size = sqrt(size);
	for (node = jump_value = list; jump_value->index + 1 < size && jump_value->n < value;)
	{
		node = jump_value;
		for (step += step_size; jump_value->index < step; jump_value = jump_value->next)
		{
			if (jump_value->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump_value->index, jump_value->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump_value->index);

	for (; node->index < jump_value->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
