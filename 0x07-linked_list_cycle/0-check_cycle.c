#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: List to check for a loop
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
  listint_t *hare = list, *tortoise = list;

  if (list == NULL)
    return (0);
  while (hare != NULL) {
    hare = hare->next;
    if (hare == tortoise)
      return (1);
    if (hare == NULL)
      return (0);
    hare = hare->next;
    if (hare == tortoise)
      return (1);
    if (hare == NULL)
      return (0);
    tortoise = tortoise->next;
  }
  return (0);
}
