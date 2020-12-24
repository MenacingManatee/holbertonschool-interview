#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_depth - gets the depth of a binary tree
 * @root: Root node
 * @side: 0 for left, 1 for right
 *
 * Return: Depth
 */
int get_depth(heap_t *root, int side)
{
	int count = 0;

	if (side == 0)
	{
		for (; root->left != NULL; count++)
			root = root->left;
	}
	else
	{
		for (; root->right != NULL; count++)
			root = root->right;
	}
	return (count);
}

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
		if (!left || !right)
			return (root);
		else if (left->left && !left->right)
			return (left);
		else if (right->left && !right->right)
			return (right);
		else if (!right->left && left->right)
			return (right);
		else if (left && right)
		{
			if (get_depth(root, 0) == get_depth(root, 1))
				return (left);
			return (right);
		}
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
	heap_t *tmp, *new;
	int depth = 0;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	for (depth = 0, tmp = *root; tmp; depth++)
		tmp = tmp->left;
	tmp = find_open_node(*root, depth);
	if (tmp->left)
	{
		tmp->right = binary_tree_node(tmp, value);
		new = tmp->right;
	}
	else
	{
		tmp->left = binary_tree_node(tmp, value);
		new = tmp->left;
	}
	heapify(root);
	while (new->parent && new->n != value)
		new = new->parent;
	return (new);
}
