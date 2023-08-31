#include "binary_trees.h"
/**
 * binary_tree_preorder - prints elem of the tree using preoder transveral
 * @tree: tree to go through to preorder
 * @func: function to use while preordering
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
