#include "search.h"
/**
 * linear_skip - Searches for a given integer
 * @list: skip list given as parameter
 * @value: integer to find/locate
 * Return: returns NULL on failure, pointer otherwise.
**/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp, *cp;

	if (list == NULL)
		return (NULL);
	tmp = list->express;
	cp = list;
	while (tmp != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   tmp->index, tmp->n);
		if (!tmp->express || tmp->n >= value)
		{
			if (!tmp->express && tmp->n < value)
			{
				cp = tmp;
				while (tmp->next)
					tmp = tmp->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				   cp->index, tmp->index);
			while (cp != NULL)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					   cp->index, cp->n);
				if (cp->n == value)
					return (cp);
				if (cp->n > value)
					return (NULL);
				cp = cp->next;
			}
			break;
		}
		cp = tmp;
		tmp = tmp->express;
	}
	return (NULL);
}
