#include "binary_trees.h"
/**
 * binary_tree_is_leaf - tells if the node is a leaf
 * that is does not have any child neither left nor right
 * @node: node to be studied
 * Return: 1 for leaf and zero for not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
