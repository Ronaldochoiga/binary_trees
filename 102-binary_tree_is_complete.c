#include "binary_trees.h"
/**
 * new_node - creates a new_node in a linked_list
 * @node: pointer of node to be created by the above function
 * Return: the node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *n;

	n =  malloc(sizeof(link_t));
	if (n == NULL)
	{
		return (NULL);
	}
	n->node = node;
	n->next = NULL;

	return (n);
}
/**
 * free_q - frees the nodes of the linked list
 * @head: Node of the linked_list
 */
void free_q(link_t *head)
{
	link_t *t_node;

	while (head)
	{
		t_node = head->next;
		free(head);
		head = t_node;
	}
}
/**
 * _push - pushes a node into the stack
 * @node: pointer of node of the tree
 * @head: head node of the stack
 * @tail: tail node of the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *n;

	n = new_node(node);
	if (n == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = n;
	*tail = n;
}
/**
 * _pop - pops a node into the stack
 * @head: head node the stack
 */
void _pop(link_t **head)
{
	link_t *t_node;

	t_node = (*head)->next;
	free(*head);
	*head = t_node;
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer of node of the tree
 * Return: 1 or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flg = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flg == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flg = 1;
		if (head->node->right != NULL)
		{
			if (flg == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flg = 1;
		_pop(&head);
	}
	return (1);
}
