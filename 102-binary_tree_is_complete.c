#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @tree_node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */

int binary_tree_is_leaf(const binary_tree_t *tree_node)
{
	if (tree_node != NULL && tree_node->left == NULL && tree_node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @root_node: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */

size_t binary_tree_height(const binary_tree_t *root_node)
{
	size_t left_height, right_height;

	if (root_node == NULL)
		return (0);
	left_height = binary_tree_height(root_node->left);
	right_height = binary_tree_height(root_node->right);
	if (left_height >= right_height)
		return (1 + left_height);
	return (1 + right_height);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @root_node: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *root_node)
{
	binary_tree_t *left_node, *right_node;

	if (root_node == NULL)
		return (1);
	left_node = root_node->left;
	right_node = root_node->right;
	if (binary_tree_is_leaf(root_node))
		return (1);
	if (left_node == NULL || right_node == NULL)
		return (0);
	if (binary_tree_height(left_node) == binary_tree_height(right_node))
	{
		if (binary_tree_is_perfect(left_node) && binary_tree_is_perfect(right_node))
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	binary_tree_t *left_node, *right_node;

	if (root_node == NULL)
		return (0);
	if (binary_tree_is_leaf(root_node))
		return (1);
	left_node = root_node->left;
	right_node = root_node->right;
	left_height = binary_tree_height(left_node);
	right_height = binary_tree_height(right_node);
	if (left_height == right_height)
	{
		if (binary_tree_is_perfect(left_node) && binary_tree_is_complete(right_node))
			return (1);
	}
	else if (left_height == right_height + 1)
	{
		if (binary_tree_is_complete(left_node) && binary_tree_is_perfect(right_node))
			return (1);
	}
	return (0);
}
