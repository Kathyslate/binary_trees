#include "binary_trees.h"

/**
 * get_binary_tree_height - function that goes through a
 * binary tree using level-order traversal
 * @root_node: pointer to the root node of the tree to
 * measure the height of
 *
 * Return: the height of the tree. If tree is NULL, do nothing
 */

size_t get_binary_tree_height(const binary_tree_t *root_node)
{
	size_t left_height, right_height;

	if (root_node == NULL)
		return (0);
	left_height = get_binary_tree_height(root_node->left);
	right_height = get_binary_tree_height(root_node->right);
	if (left_height >= right_height)
		return (1 + left_height);
	return (1 + right_height);
}

/**
 * get_binary_tree_level - perform a function on a
 * specific level of a binary tree
 * @root_node: pointer to the root of the tree
 * @level: level of the tree to perform a function on
 * @function: function to perform
 *
 * Return: void
 */

void get_binary_tree_level(const binary_tree_t *root_node,
	size_t level, void (*function)(int))
{
	if (root_node == NULL)
		return;
	if (level == 1)
		function(root_node->n);
	else if (level > 1)
	{
		get_binary_tree_level(root_node->left, level - 1, function);
		get_binary_tree_level(root_node->right, level - 1, function);
	}
}

/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;
	h = get_binary_tree_height(tree);
	for (i = 1; i <= h; i++)
		get_binary_tree_level(tree, i, func);
}
