#include "binary_trees.h"

/**
 * tree_size - function measures the sum of heights of a binary tree
 * @tree: tree to measure the height
 *
 * Return: Height or zero
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t hgt_l = 0;
	size_t hgt_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hgt_l = 1 + tree_size(tree->left);

	if (tree->right)
		hgt_r = 1 + tree_size(tree->right);

	return (hgt_l + hgt_r);
}

/**
 * heap_to_sorted_array - function converts a Binary Max Heap
 * to a sorted array of integers as per the instructions
 * @heap: heap to be converted
 * @size: size of the node to be stored
 * Return: array produced in a decending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *j = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	j = malloc(sizeof(int) * (*size));

	if (!j)
		return (NULL);

	for (i = 0; heap; i++)
		j[i] = heap_extract(&heap);

	return (j);
}
