#include "lists.h"

/**
 * check_cycle - checks if list is circular
 * @list: node of list taken as parameter
 * Return: 0 if unsuccessful, 1 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *tmp = list, *tmp2 = list;

	if (list == NULL)
		return (0);
	while (tmp && tmp2 && tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next->next;
		if (tmp == tmp2)
			return (1);
	}
	return (0);
}
