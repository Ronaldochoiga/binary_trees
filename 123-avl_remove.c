#include "binary_trees.h"

/**
 * bal - funtion that Measures balance factor of an AVL
 * @tree: tree to go through measuring
 * Return: balanced factor deduces
 */
void bal(avl_t **tree)
{
	int b_val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	b_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - funtion to get the next successor
 * @node: tree to be checked for successor
 * Return: the min value of the tree
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
 *remove_type - function that removes a node dep on child
 *@root: node to be removed
 *Return: 0 for no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int n_value = 0;

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
	{
		n_value = successor(root->right);
		root->n = n_value;
		return (n_value);
	}
}
/**
 * bst_remove - function remove a node from a BST tree
 * @root: root of the tree where node is removed
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

/**
 * avl_remove - remove a node from an AVL tree
 * @root: root of the tree where node is removed
 * @value: value of the node to be removed
 * Return: the changed tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *rt_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (rt_a == NULL)
		return (NULL);
	bal(&rt_a);
	return (rt_a);
}
