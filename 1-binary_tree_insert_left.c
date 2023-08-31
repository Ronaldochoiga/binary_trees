#include "binary_trees.h"
/**
 * binary_tree_insert_left - add a node in the left of the parent node
 * if it exists it add the new node first
 * @parent: parent the indicated node
 * @value: value of the node to be added
 * Return: NULL if it fails or the n_node aftyer success
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	n_node = binary_tree_node(parent, value);
	if (n_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		n_node->left = parent->left;
		parent->left->parent = n_node;
	}
	parent->left = n_node;
	return (n_node);
}
