#include "binary_trees.h"

/**
 * binary_tree_node - creates a new tree node
 * @parent: parent node to target
 * @value: value for new node passed as parameter
 *
 * Return: pointer to new node, NULL otherwise
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	if (parent)
		new->parent = parent;
	return (new);
}
