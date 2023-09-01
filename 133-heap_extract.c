#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - function measures the height of a binary tree
 * @tree: tree to measure the height
 * Return: Height or zero
 */
size_t tree_height(const heap_t *tree)
{
	size_t hgt_l = 0;
	size_t hgt_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hgt_l = 1 + tree_height(tree->left);

	if (tree->right)
		hgt_r = 1 + tree_height(tree->right);

	if (hgt_l > hgt_r)
		return (hgt_l);
	return (hgt_r);
}
/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: trees to have their heights sumed up
 * Return: Height or zero
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t hgt_l = 0;
	size_t hgt_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hgt_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		hgt_r = 1 + tree_size_h(tree->right);

	return (hgt_l + hgt_r);
}

/**
 * _preorder - uses pre-order tranversal to go through
 * @tree: tree to undergo tranversal
 * @node: the last node in the transverse
 * @height: height of tree involved
 *
 * Return: void
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - the functionheapifies max binary heap
 * @root: binary heap
 */
void heapify(heap_t *root)
{
	int val;
	heap_t *temp0, *temp1;

	if (!root)
		return;

	temp0 = root;

	while (1)
	{
		if (!temp0->left)
			break;
		if (!temp0->right)
			temp1 = temp0->left;
		else
		{
			if (temp0->left->n > temp0->right->n)
				temp1 = temp0->left;
			else
				temp1 = temp0->right;
		}
		if (temp0->n > temp1->n)
			break;
		val = temp0->n;
		temp0->n = temp1->n;
		temp1->n = val;
		temp0 = temp1;
	}
}

/**
 * heap_extract - the function extracts the root node from a Max Binary Heap
 * @root: the root heap involved in this function
 * Return: val of deduced node
 **/
int heap_extract(heap_t **root)
{
	int val;
	heap_t *hp_r, *node;

	if (!root || !*root)
		return (0);
	hp_r = *root;
	val = hp_r->n;
	if (!hp_r->left && !hp_r->right)
	{
		*root = NULL;
		free(hp_r);
		return (val);
	}

	_preorder(hp_r, &node, tree_height(hp_r));

	hp_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(hp_r);
	*root = hp_r;
	return (val);
}
