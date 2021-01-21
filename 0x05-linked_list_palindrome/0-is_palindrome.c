#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *find_prev(listint_t *head, listint_t *next);
/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: pointer to list to be evaluated
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *run;
	int *arr, length = 0, i, j;
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	run = *head;
	while (run->next != NULL)
	{
		run = run->next;
		length++;
	}
	arr = malloc(sizeof(int *) * (length));
	if (arr == NULL)
		return (0);
	run = *head;
	for (i = 0; i <= length && run != NULL; i++)
	{
		arr[i] = run->n;
		run = run->next;
	}
	for (i = 0, j = length; i < j; i++, j--)
	{
		if (arr[i] != arr[j])
			return (0);
	}
	return (1);
}
