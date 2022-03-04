#include "binary_trees.h"

heap_t *find_parent_node(heap_t **root, int value);

/**
 * heap_insert - Inserts a value into max heap
 * @root: pointer to root node
 * @value: value to be inserted to node
 *
 * Return: A pointer to node, NULL otherwise.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new;
	binary_tree_t *parent;

	parent = find_parent_node(root, value);

	new = binary_tree_node(parent, value);

	if (parent == NULL)
	{
		*root = new;
		return (new);
	}
	return (NULL);
}

/**
 * locate_parent - Returns the parent node
 * @root: A double pointer to root
 * @value: comparison parameter
 *
 * Return: A pointer to parent, NULL otherwise.
 */
heap_t *locate_parent(heap_t **root, int value)
{
	binary_tree_t *temp = *root;
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;

	if (*root == NULL)
		return (NULL);
	if (temp->n < value)
		return (temp);
	while (temp)
		return (left);
	return (right);
}
