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
	binary_tree_t *a, *b;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	a = first->parent;
	b = second->parent;
	if (a == NULL || first == b || (!a->parent && b))
	{
		return (binary_trees_ancestor(first, a));
	}
	else if (b == NULL || a == second || (!b->parent && a))
	{
		return (binary_trees_ancestor(a, second));
	}
	return (binary_trees_ancestor(a, b));
}
