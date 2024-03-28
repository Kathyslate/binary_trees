#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_nodes - function that return nodes in a tree with children
 * @tree: tree to check
 * Return: number of nodes with children
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);

	return (0);
}
