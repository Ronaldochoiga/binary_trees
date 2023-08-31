#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if tree is root
 * @node: Node to be checked
 * Return: one or zero
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
