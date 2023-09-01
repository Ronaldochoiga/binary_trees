#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of the binary tree
 * @tree: tree to go through measuring
 * Return: the height that is measured
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			i = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((i > r) ? i : r);
	}
}
/**
 * binary_tree_depth - depth of indicated node from root
 * @tree: node to check the depth
 * Return: 0 or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - makes a linked list from depth level and the node
 * @head: pointer to head of the linked list
 * @tree: node to be stored
 * @level: depth of node to be stored
 * Return: void
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *n, *auxiliary;

	n = malloc(sizeof(link_t));
	if (n == NULL)
	{
		return;
	}
	n->n = level;
	n->node = tree;
	if (*head == NULL)
	{
		n->next = NULL;
		*head = n;
	}
	else
	{
		auxiliary = *head;
		while (auxiliary->next != NULL)
		{
			auxiliary = auxiliary->next;
		}
		n->next = NULL;
		auxiliary->next = n;
	}
}
/**
 * recursion - goes through entire string and stores each node
 * in linked_node functionality
 * @head: pointer to head of linked list
 * @tree: node to check
 * Return: void
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t lev = 0;

	if (tree != NULL)
	{
		lev = binary_tree_depth(tree);
		linked_node(head, tree, lev);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - print the nodes element in lever-order
 * @tree: root node in the function
 * @func: function to use during the leveling
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *auxiliary;
	size_t hgt = 0, cnt = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		hgt = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (cnt <= hgt)
		{
			auxiliary = head;
			while (auxiliary != NULL)
			{
				if (cnt == auxiliary->n)
				{
					func(auxiliary->node->n);
				}
				auxiliary = auxiliary->next;
			}
			cnt++;
		}
		while (head != NULL)
		{
			auxiliary = head;
			head = head->next;
			free(auxiliary);
		}
	}
}
