#include "binary_trees.h"
#include<stdlib.h>
/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of
 * integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array_pointer;
	int ext, i = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);
	heap_size = size_binary_tree(heap);
	*size = heap_size;
	array_pointer = malloc(heap_size * sizeof(int));
	if (!array_pointer)
		return (NULL);
	while (heap)
	{
		ext = heap_ext(&heap);
		array_pointer[i] = ext;
		i++;
	}
	return (array_pointer);
}
