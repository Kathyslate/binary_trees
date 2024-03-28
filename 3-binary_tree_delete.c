#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - deletes a binary
 *
 * @tree: Pointer to the tree to be deleted
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
