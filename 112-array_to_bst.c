#include "binary_trees.h"
/**
 * array_to_bst - turns an array to a BST tree as ordered
 * @array: array to turn to BST tree
 * @size: size of array to be turned
 * Return: BST tree created from the array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *rt;

	rt = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; i < size; i++)
	{
		if (i == 0)
		{
			bst_insert(&rt, array[i]);
		}
		else
		{
			bst_insert(&rt, array[i]);
		}
	}
	return (rt);
}
