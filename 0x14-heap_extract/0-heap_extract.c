#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a heap
 * @root: Root node of heap
 *
 * Return: Value of extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (!root || !(*root))
		return (0);
	return ((*root)->n);
}
