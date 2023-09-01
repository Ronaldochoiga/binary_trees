#include "binary_trees.h"
/**
 * bst_insert - insert nodes in an order to create a BST tree
 * @tree: tree to create with type BST
 * @value: value of node to be inserted
 * Return: BST tree created
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *n, *tmp;
	binary_tree_t *auxiliary;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		auxiliary = binary_tree_node((binary_tree_t *)(*tree), value);
		n = (bst_t *)auxiliary;
		*tree = n;
	}
	else
	{
		tmp = *tree;
		if (value < tmp->n)
		{
			if (tmp->left)
				n = bst_insert(&tmp->left, value);
			else
			{
				auxiliary = binary_tree_node((binary_tree_t *)tmp, value);
				n = tmp->left = (bst_t *)auxiliary;
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				n = bst_insert(&tmp->right, value);
			else
			{
				auxiliary = binary_tree_node((binary_tree_t *)tmp, value);
				n = tmp->right = auxiliary;
			}
		}
		else
			return (NULL);
	}
	return (n);
}
