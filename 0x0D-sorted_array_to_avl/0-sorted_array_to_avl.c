#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

avl_t *fill_nodes(size_t start, size_t end, avl_t *node, int *array);
avl_t *create_node(int val);
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to first element of sorted array
 * @size: Size of array
 *
 * Return: pointer to root of avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	root = fill_nodes(0, size, NULL, array);
	return (root);
}
avl_t *create_node(int val) {
	avl_t *new = malloc(sizeof(avl_t));

	if (new == NULL)
		return (NULL);
	new->n = val;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
avl_t *fill_nodes(size_t start, size_t end, avl_t *node, int *array) {
	avl_t * new;
	int i = (start + end) / 2;
	if (start >= end || i <= (int)start || i > (int)end)
		return (NULL);
	new = create_node(array[i - 1]);
	new->parent = node;
	new->left = fill_nodes(start, i, new, array);
	new->right = fill_nodes(i, end, new, array);
	return (new);
}
