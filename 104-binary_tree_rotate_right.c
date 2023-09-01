#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates to the right the binary tree.
 * @tree: The root node of the tree
 * Return: Pointer to the node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvt;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pvt = tree->left;
	tree->left = pvt->right;
	if (pvt->right != NULL)
	{
		pvt->right->parent = tree;
	}
	pvt->right = tree;
	pvt->parent = tree->parent;
	tree->parent = pvt;
	return (pvt);
}
