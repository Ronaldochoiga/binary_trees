#include "binary_trees.h"

/**
 * binary_tree_height_b - funtion Measures height of a binary tree from a bal tree
 * @tree: tree to go through measuring
 * Return: the height of the tree
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t i = 0;
	size_t j = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			i = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			j = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((i > j) ? i : j);
	}
}

/**
 * binary_tree_balance - Measures balance factor of the binary tree
 * @tree: tree to go through measuring
 * Return: balanced factor found
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, t = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		t = left - right;
	}
	return (t);
}
