#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: List to search
 * @value: Value to search for
 *
 * Return: pointer on the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tort = list;
	skiplist_t *hare = list;
	int last;

	if (list == NULL)
		return (NULL);
	hare = hare->express;
	while (hare && hare->n < value)
	{
		if (hare == NULL)
			break;
		printf("Value checked at index [%d] = [%d]\n", (int)hare->index, hare->n);
		tort = hare;
		hare = hare->express;
	}
	if (hare != NULL)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)hare->index, hare->n);
		last = (int)hare->index;
	}
	else
	{
		hare = tort;
		while (hare->next != NULL)
			hare = hare->next;
		last = (int)hare->index;
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)tort->index, last);
	hare = tort->express;
	while (tort != NULL && tort != hare)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)tort->index, tort->n);
		if (tort->n == value)
			return (tort);
		tort = tort->next;
	}
	return (NULL);
}
