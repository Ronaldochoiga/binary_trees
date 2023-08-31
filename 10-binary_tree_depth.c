#include "binary_trees.h"
/**
 * binary_tree_depth - depth of showed node from root
 * @tree: node to be checked the depth
 * Return: zero or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
