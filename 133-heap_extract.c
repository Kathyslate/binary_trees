#include "binary_trees.h"

#define INITIAL_NODE_VALUE {0, NULL, NULL, NULL}

#define CONVERT_CONSTANT "0123456789ABCDEF"

#define SETUP_NODE_BLOC { \
	tmp_node = *root; \
	size = size_binary_tree(*root); \
	binary = &buffer[49]; \
	*binary = 0; \
	}

#define NODE_BLOC_FREE { \
		result = tmp_node->n; \
		free(tmp_node); \
		*root = NULL; \
	}

#define HEAD_BLOC_SWAP { \
		head_node = *root; \
		head_node = swap_head_node(head_node, tmp_node); \
		result = head_node->n; \
		free(head_node); \
		*root = tmp_node; \
		tmp_node = perc_down(tmp_node); \
		*root = tmp_node; \
	}

#define CONVERT_CONSTANT_LOOP { \
		*--binary = CONVERT_CONSTANT[size % 2]; \
		size /= 2; \
	}

/**
 * swap_nodes - swaps two nodes in binary tree
 * @node_a: first node
 * @node_b: second node
 * Return: pointer to root
 */
bst_t *swap_nodes(bst_t *node_a, bst_t *node_b)
{
	bst_t node_a_copy = INITIAL_NODE_VALUE;

	node_a_copy.n = node_a->n;
	node_a_copy.parent = node_a->parent;
	node_a_copy.left = node_a->left;
	node_a_copy.right = node_a->right;
	node_a->parent = node_b;
	node_a->left = node_b->left;
	node_a->right = node_b->right;
	if (node_b->left)
		node_b->left->parent = node_a;
	if (node_b->right)
 		node_b->right->parent = node_a;

	node_b->parent = node_a_copy.parent;
	if (node_a_copy.parent)
	{
		if (node_a == node_a_copy.parent->left)
			node_a_copy.parent->left = node_b;
		else
			node_a_copy.parent->right = node_b;
	}
	if (node_b == node_a_copy.left)
	{
		node_b->left = node_a;
		node_b->right = node_a_copy.right;
		if (node_a_copy.right)
			node_a_copy.right->parent = node_b;
	}
	else if (node_b == node_a_copy.right)
	{
		node_b->right = node_a;
		node_b->left = node_a_copy.left;
		if (node_a_copy.left)
			node_a_copy.left->parent = node_b;
	}
	while (node_b->parent)
		node_b = node_b->parent;
	return (node_b);
}

/**
 * size_binary_tree - measuresult the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t size_binary_tree(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + size_binary_tree(tree->left) + size_binary_tree(tree->right));
}

/**
 * swap_head_node - helper func to swap head_node and node
 * @head_node: pointer to head_node
 * @node: pointer to node
 * Return: pointer to severed head_node of tree
 */
heap_t *swap_head_node(heap_t *head_node, heap_t *node)
{
	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	} else
		node->parent->right = NULL;
	node->parent = NULL;
	node->left = head_node->left;
	node->right = head_node->right;
	if (head_node->left)
		head_node->left->parent = node;
	if (head_node->right)
		head_node->right->parent = node;
	return (head_node);
}

/**
 * perc_down - percolate head_node into correct position
 * @node: pointer to head_node
 * Return: pointer to head_node of tree
 */
heap_t *perc_down(heap_t *node)
{
	int maximum;
	heap_t *next = node;

	if (!node)
		return (NULL);
	maximum = node->n;
	if (node->left)
		maximum = MAX(node->left->n, maximum);
	if (node->right)
		maximum = MAX(node->right->n, maximum);
	if (node->left && maximum == node->left->n)
		next = node->left;
	else if (node->right && maximum == node->right->n)
		next = node->right;
	if (next != node)
	{
		swap(node, next);
		perc_down(node);
	}
	return (next);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root of tree
 * Return: value stored in the root node
 * else If function fails, return 0
 */
int heap_extract(heap_t **root)
{
	size_t size, i;
	char *binary, c, buffer[50];
	int result;
	heap_t *tmp_node, *head_node;

	if (!root || !*root)
		return (0);
	SETUP_NODE_BLOC;
	if (size == 1)
	{
		NODE_BLOC_FREE;
		return (result);
	}
	do {
		CONVERT_CONSTANT_LOOP;
	} while (size);

	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				tmp_node = tmp_node->right;
				break;
			}
			else if (c == '0')
			{
				tmp_node = tmp_node->left;
				break;
			}
		}
		if (c == '1')
			tmp_node = tmp_node->right;
		else if (c == '0')
			tmp_node = tmp_node->left;
	}
	HEAD_BLOC_SWAP;
	return (result);
}
