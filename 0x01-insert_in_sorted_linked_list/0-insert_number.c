#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
* insert_node - inserts a node into a sorted linked list
* @head: head node of the linked list
* @number: node data to insert
*
* Return: NULL on fail, otherwise on success
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp, *newNode, *nextNode;
	unsigned int i;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);
	if (*head == NULL)
		*head = newNode;
	tmp = *head;

	for (i = 1; tmp->next != NULL && tmp->next->n < number; i++)
		tmp = tmp->next;
	nextNode = tmp->next;
	tmp->next = newNode;
	newNode->n = number;
	newNode->next = nextNode;
	return (newNode);
}
