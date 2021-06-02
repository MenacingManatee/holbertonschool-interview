#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: head of the linked list
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (head == NULL)
		return (NULL);
	tortoise = head->next;
	hare = head->next;
	if (hare == NULL)
		return (NULL);
	while (head)
	{
		hare = hare->next;
		if (hare == NULL)
			return (NULL);
		if (hare == head)
			return (head);
		if (hare == tortoise)
		{
			head = head->next;
			tortoise = head->next;
			hare = head->next;
			continue;
		}
		hare = hare->next;
		if (hare == NULL)
			return (NULL);
		if (hare == head)
			return (head);
		if (hare == tortoise)
		{
			head = head->next;
			tortoise = head->next;
			hare = head->next;
			continue;
		}
		tortoise = tortoise->next;
	}
	return (NULL);
}
