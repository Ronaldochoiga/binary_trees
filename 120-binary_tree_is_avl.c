#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to go through measuring
 * Return: the height of the tree as measured
 */

size_t binary_tree_height(const binary_tree_t *tree)
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
			i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			j = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((i > j) ? i : j);
		}
}

/**
 * bal_avl - compare each subtree if its AVL.
 * @tree: node that point to the tree to be checked.
 * @high: node that point to the higher node selected
 * @lower: node that point to the lower node selected.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t hgt_l, hgt_r, bal;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		hgt_l = binary_tree_height(tree->left);
		hgt_r = binary_tree_height(tree->right);
		bal = hgt_l > hgt_r ? hgt_l - hgt_r : hgt_r - hgt_l;
		if (bal > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - confirms if the binary tree is a valid AVL tree.
 * @tree: node that point to the tree to be checked.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
