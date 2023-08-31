#include "binary_trees.h"
/**
 * binary_tree_postorder - print elem of the 0tree through post-order traversal
 * @tree: tree to go through for post-ordering
 * @func: function to use for post-ordering
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
