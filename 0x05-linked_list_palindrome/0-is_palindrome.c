#include <stdio.h>
#include "lists.h"

listint_t *find_prev(listint_t *head, listint_t *next);
/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: pointer to list to be evaluated
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *last, *first;
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	last = *head;
	first = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	while (first != last && first->next != last)
	{
		if (first->n != last->n)
			return (0);
		first = first->next;
		last = find_prev(*head, last);
	}
	if (first == last || first->n == last->n)
		return (1);
	return (0);
}
/**
 * find_prev - Finds the previous node
 * @head: Pointer to the head node
 * @next: Node to find the previous of
 *
 * Return: Previous node, or NULL
 */
listint_t *find_prev(listint_t *head, listint_t *next)
{
	if (head == NULL) /* Shouldn't happen, jic */
		return (NULL);
	if (head->next == next)
		return (head);
	return (find_prev(head->next, next));
}
