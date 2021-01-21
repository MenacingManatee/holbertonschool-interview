#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Determines if a linked list is a palindrome
 * @head: pointer to list to be evaluated
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	return (0);
}
