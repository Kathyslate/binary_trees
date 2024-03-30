#include "binary_trees.h"
#include<stdlib.h>
#include<string.h>
#define INITIAL_NODE_VALUE {0, NULL, NULL, NULL}

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
 * do_convert - do_converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *do_convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = 0;
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
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
 * insert_node - helper func to insert_node node to correct location
 * @root: double pointer to root of max heap
 * @node: node to insert_node
 */
void insert_node(heap_t **root, heap_t *node)
{
	heap_t *temp_node;
	int size;
	unsigned int i;
	char *binary;
	char c;

	temp_node = *root;
	size = size_binary_tree(temp_node) + 1;
	binary = do_convert(size, 2, 1);
	for (i = 1; i < strlen(binary); i++)
	{
		c = binary[i];
		if (i == strlen(binary) - 1)
		{
			if (c == '1')
			{
				node->parent = temp_node;
				temp_node->right = node;
				break;
			}
			else if (c == '0')
			{
				node->parent = temp_node;
				temp_node->left = node;
				break;
			}
		}
		if (c == '1')
			temp_node = temp_node->right;
		else if (c == '0')
			temp_node = temp_node->left;
	}
}


/**
 * heap_insert - insert_nodes a value in Max Binary Heap
 * @root: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *ht = NULL, *ret;

	if (!root)
		return (NULL);
	ht = calloc(1, sizeof(heap_t));
	ht->n = value;
	if (!*root)
	{
		*root = ht;
		return (ht);
	}
	insert_node(root, ht);
	while (ht->parent && ht->n > ht->parent->n)
	{
		ret = swap_nodes(ht->parent, ht);
		if (ret)
			*root = ret;
	}
	return (ht);
}
