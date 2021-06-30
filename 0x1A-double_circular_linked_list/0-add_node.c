#include "list.h"

List *create_node(char *str);
/**
 * add_node_end - adds a node to the end of a list
 * @list: double pointer to list head
 * @str: String value of the new node
 *
 * Return: Address of new node, or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *res = create_node(str);
	List *head = *list;

	if (res == NULL)
		return (NULL);
	if (*list == NULL)
	{
		*list = res;
		return (res);
	}
	else
	{
		while (head->next != NULL && head->next != (*list))
			head = head->next;
		head->next = res;
		res->prev = head;
		res->next = *list;
		(*list)->prev = res;
	}
	return (res);
		
}

/**
 * add_node_begin - Adds a anode to the beginning of a List
 * list: pointer to head node
 * @str: String value of new node
 *
 * Return: Address of new node, or nULL
 */
List *add_node_begin(List **list, char *str)
{
	List *res = create_node(str);
	List *head = *list;

	if (res == NULL)
		return (NULL);
	res->next = (*list);
	if (*list != NULL)
	{
		while (head->next != NULL && head->next != *list)
			head = head->next;
		res->prev = head;
		head->next = res;
		(*list)->prev = res;
	}
	*list = res;
	return (res);
}
/**
 * create_node - creates a List node
 * @str: string value to be stored
 *
 * Return: address of new node, or NULL
 */
List *create_node(char *str)
{
	List *res = malloc(sizeof(List));

	if (res == NULL)
		return (NULL);
	res->str = str;
	res->next = res;
	res->prev = res;
	return (res);
}
