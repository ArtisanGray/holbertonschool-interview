#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - converts sorted array to AVL tree
 * @array: pointer to array
 * @size: size of the array in elements
 * Return:  NULL on error, node to tree otherwise
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node, *right, *left = NULL;
	size_t half;

	if (size == 0 || !array)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	half = (size - 1) / 2;
	node->n = array[half];
	node->parent = NULL;
	if (half > 0)
		left = sorted_array_to_avl(array, half);
	else
		left = NULL;
	if (size > (half + 1))
		right = sorted_array_to_avl(&array[half + 1], size - (half + 1));
	else
		right = NULL;
	node->left = left;
	node->right = right;

	if (node->left)
		(node->left)->parent = node;
	if (node->right)
		(node->right)->parent = node;
	return (node);
}
