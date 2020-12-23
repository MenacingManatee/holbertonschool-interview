#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify - rebalances a binary heap
 * @root: Root node of heap
 *
 */
void heapify(heap_t **root)
{
	heap_t *left, *right, *right2;
	if (*root == NULL)
		return;
	heapify(&(*root)->left);
	heapify(&(*root)->right);
	if ((*root)->left && (*root)->left->n > (*root)->n)
	{
		right = (*root)->right;
		right2 = (*root)->left->right;
		(*root)->right = right2;
		(*root)->left->right = right;
		(*root)->left->parent = (*root)->parent;
		(*root)->parent = (*root)->left;
		left = (*root)->left->left;
		(*root)->parent->left = *root;
		(*root)->left = left;
		(*root)->right->parent = (*root);
		(*root)->parent->right = (*root)->parent;
	}
}

heap_t *find_open_node(heap_t *root)
{
	heap_t *tmp, *res;

	tmp = root;
	if (tmp == NULL)
		return (NULL);
	if (tmp->left && !tmp->right)
		return (tmp);
	res = find_open_node(tmp->left);
	if (!res)
		return (res);
	return (find_open_node(tmp->right));
}
/**
 * heap_insert - inserts a node into a binary heap
 * @root: Root node of the heap
 * @value: value to add
 *
 * Return: Pointer to added node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *tmp;

	if (root == NULL)
		return (NULL);
	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	if (*root == NULL)
	{
		*root = new;
		return (new);
	}
	tmp = find_open_node(*root);
	if (!tmp)
		tmp->right = new;
	heapify(root);
	return (new);
}
