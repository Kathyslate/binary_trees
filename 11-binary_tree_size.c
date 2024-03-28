#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_size - function that return the size of binary tree
 * @tree: tree to check
 * Return: size of tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
