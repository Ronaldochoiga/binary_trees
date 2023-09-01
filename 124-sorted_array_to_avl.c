#include "binary_trees.h"
/**
 * aux_sort - creates the tree using the half element of the array provided
 * @parent: parent of the node to create the array
 * @array: sorted array to be used
 * @begin: array start position
 * @last: array end position
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *rt;
	binary_tree_t *auxiliary;
	int middle = 0;

	if (begin <= last)
	{
		middle = (begin + last) / 2;
		auxiliary = binary_tree_node((binary_tree_t *)parent, array[middle]);
		if (auxiliary == NULL)
			return (NULL);
		rt = (avl_t *)auxiliary;
		rt->left = aux_sort(rt, array, begin, middle - 1);
		rt->right = aux_sort(rt, array, middle + 1, last);
		return (rt);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - function that create an alv tree from sorted array
 * @array: sorted array to be used
 * @size: size of the sorted array used
 * Return: alv tree from the sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
