#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify - rebalances a binary heap
 * @root: Root node of heap
 *
 */
void heapify(heap_t **root)
{
	int tmp;
	heap_t *to_swap = NULL;

	if (*root == NULL)
		return;
	heapify(&(*root)->left);
	heapify(&(*root)->right);
	if ((*root)->left && (*root)->left->n > (*root)->n)
	{
		to_swap = (*root)->left;
	}
	else if ((*root)->right && (*root)->right->n > (*root)->n)
	{
		to_swap = (*root)->right;
	}
	if (to_swap)
	{
		tmp = to_swap->n;
		to_swap->n = (*root)->n;
		(*root)->n = tmp;
	}
}
/**
 * find_open_node - finds the leftmost open node
 * @root: root node
 * @level: Level currently on
 *
 * Return: Leftmost open node, or NULL
 */
heap_t *find_open_node(heap_t *root, int level)
{
	heap_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (level > 1)
	{
		left = find_open_node(root->left, level - 1);
		right = find_open_node(root->right, level - 1);
		if (left->left && !left->right)
			return (left);
		else if (right->left && !right->right)
			return (right);
		else if (!right->left && left->right)
			return (right);
		else
			return (left);
	}
	return (root);
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
	int depth = 0;

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
	/*printf("Find node\n");*/
	for (depth = 0, tmp = *root; tmp; depth++)
		tmp = tmp->left;
	tmp = find_open_node(*root, depth);
	/*printf("Node found: %d\n", tmp->n);*/
	if (!tmp)
		tmp->right = new;
	new->parent = tmp;
	if (tmp->left)
		tmp->right = new;
	else
		tmp->left = new;
	heapify(root);
	while (new && new->n != value)
		new = new->parent;
	return (new);
}
