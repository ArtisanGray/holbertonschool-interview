#include "lists.h"

/**
 * is_palindrome - Function that checks
 * if a singly linked list is a palindrome.
 *
 * @head: head pointer of the linked list..
 *
 * Return: 0 on failure, 1 on success.
 */

int is_palindrome(listint_t **head)
{
	int is_pali = 1, nodes = 1, i = 0, *arr = NULL;
	listint_t *ptr = NULL;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	ptr = *head;
	while (ptr->next != NULL)
	{
		nodes++;
		ptr = ptr->next;
	}

	arr = malloc(nodes * sizeof(int));
	ptr = *head;

	while (ptr != NULL)
	{
		arr[i++] = ptr->n;
		ptr = ptr->next;
	}
	i = 0;
	while (i < nodes && is_pali == 1)
	{
		if (arr[i] != arr[nodes - i - 1])
		is_pali = 0;
		i++;
	}
	free(arr);
	return (is_pali);
}
