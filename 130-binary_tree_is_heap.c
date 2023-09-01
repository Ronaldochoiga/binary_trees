#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to go through measuring
 * Return: the height deduced
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
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			i = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			j = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((i > j) ? i : j);
		}
}

/**
 * binary_tree_balance - function Measures balance factor of a binary tree
 * @tree: tree to go through measuring
 * Return: balanced factor derived
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, t = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		t = left - right;
	}
	return (t);
}

/**
 * tree_is_perfect - shows whether the tree is perfect or not
 * @tree: tree to check the perfection
 * Return: 0 or level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int i = 0, j = 0;

	if (tree->left && tree->right)
	{
		i = 1 + tree_is_perfect(tree->left);
		j = 1 + tree_is_perfect(tree->right);
		if (j == i && j != 0 && i != 0)
			return (j);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - perfect or not a perfect tree
 * @tree: tree to check for perfection
 * Return: 1 or zero
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		r = tree_is_perfect(tree);
		if (r != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - funtion checks if the binary tree is a valid Max Binary Heap
 * @tree: tree to check for validity
 * Return: 1 or zero
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int b_val;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	b_val = binary_tree_balance(tree);
	if (b_val == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (b_val == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
