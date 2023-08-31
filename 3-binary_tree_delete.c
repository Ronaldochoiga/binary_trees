#include "binary_trees.h"
/**
 * binary_tree_delete - fress thge whole tree
 * when the nodes in the left and thr right are NULL
 * @tree: tree to be deleted
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
