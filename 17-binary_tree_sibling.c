#include "binary_trees.h"

/**
 * binary_tree_sibling - finds if a node is a sibling
 * @node: node to check tehstatus
 * Return: The sibling node if available
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
