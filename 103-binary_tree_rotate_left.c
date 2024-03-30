#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp_node;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	temp_node = pivot->left;
	pivot->left = tree;
	tree->right = temp_node;
	if (temp_node != NULL)
		temp_node->parent = tree;
	temp_node = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp_node;
	if (temp_node != NULL)
	{
		if (temp_node->left == tree)
			temp_node->left = pivot;
		else
			temp_node->right = pivot;
	}

	return (pivot);
}
