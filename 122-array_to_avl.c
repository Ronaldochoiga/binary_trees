#include "binary_trees.h"

/**
 * array_to_avl - turns an array to an avl tree
 * @array: array to turned into an AVL tree
 * @size: size of array to be turned
 * Return: AVL tree generated
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t a, b = 0;
	avl_t *rt;

	rt = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (avl_insert(&rt, array[a]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (rt);
}
