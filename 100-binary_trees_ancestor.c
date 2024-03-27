#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	const binary_tree_t *current = first;

	while (current->parent)
	{
		current = current->parent;

		const binary_tree_t *other = second;

		while (other->parent && other->parent != current)
			other = other->parent;

		if (current->parent == other->parent)
			return ((binary_tree_t *) current->parent);
	}

	return (NULL);
}
