#include "binary_trees.h"

/**
 * heap_insert - function inserts a value in Max Binary Heap
 * @root: pointer to the root node of the Heap to insert the value to
 * @value: the value of the new node
 * Return: value of the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *n, *flp;
	int size, lvs, sub, bit, lvl, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	lvs = size;
	for (lvl = 0, sub = 1; lvs >= sub; sub *= 2, lvl++)
		lvs -= sub;

	for (bit = 1 << (lvl - 1); bit != 1; bit >>= 1)
		tree = lvs & bit ? tree->right : tree->left;

	n = binary_tree_node(tree, value);
	lvs & 1 ? (tree->right = n) : (tree->left = n);

	flp = n;
	for (; flp->parent && (flp->n > flp->parent->n); flp = flp->parent)
	{
		temp = flp->n;
		flp->n = flp->parent->n;
		flp->parent->n = temp;
		n = n->parent;
	}

	return (n);
}

/**
 * binary_tree_size - function measures the size of a binary tree
 * @tree: tree to be measured size
 * Return: size or null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
