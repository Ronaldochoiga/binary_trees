#include "binary_trees.h"

/**
 * array_to_heap - function that builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: craeted binary heap or null
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *rt = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&rt, array[i]);

	return (rt);
}
