#include "binary_trees.h"
/**
 * successor - get the next successor
 * @node: tree to check for the successor
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * two_children - function that gets the next successor from right subtree
 * @root: node that has two children
 * Return: the value found from the above funtion
 */
int two_children(bst_t *root)
{
	int n_value = 0;

	n_value = successor(root->right);
	root->n = n_value;
	return (n_value);
}
/**
 *remove_type - removes a node depending of its children
 *@root: node to be removed
 *Return: 0 if no children or other value if children avail
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to be removed
 * Return: the changed tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int typ = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		typ = remove_type(root);
		if (typ != 0)
			bst_remove(root->right, typ);
	}
	else
		return (NULL);
	return (root);
}
