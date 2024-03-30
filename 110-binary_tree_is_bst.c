#include "binary_trees.h"
#include "limits.h"

/**
 * my_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @node: A pointer to the root node of the tree to check.
 * @lower_bound: The value of the smallest node visited thus far.
 * @upper_bound: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int my_bst_helper(const binary_tree_t *node, int lower_bound, int upper_bound)
{
	if (node != NULL)
	{
		if (node->n < lower_bound || node->n > upper_bound)
			return (0);
		return (my_bst_helper(node->left, lower_bound, node->n - 1) &&
			my_bst_helper(node->right, node->n + 1, upper_bound));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (my_bst_helper(tree, INT_MIN, INT_MAX));
}
