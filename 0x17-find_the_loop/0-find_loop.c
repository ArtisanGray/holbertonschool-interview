#include "lists.h"

/**
 * find_listint_loop - finds loop in linked list..
 * @head: pointer to head node of linked list.
 * Return: loop's node address, or null if no loop is found..
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (head == NULL)
		return (NULL);

	fast = head;
	slow = head;

	while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}
