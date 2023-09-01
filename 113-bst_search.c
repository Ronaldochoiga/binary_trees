#include "binary_trees.h"
/**
 * bst_search - function searchs for a special value in the tree and return the node
 * @tree: tree to go through while searching
 * @value: value to search for in the tree
 * Return: the node with the value or NULL if no value found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *fnd;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		fnd = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		fnd = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (fnd);
}
