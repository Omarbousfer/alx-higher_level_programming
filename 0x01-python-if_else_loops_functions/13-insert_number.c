#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted
 * singly linked list
 *
 * @head: pointer of list
 * @number: number to be added
 * Return: the address of the new node, or NULL
 * if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	if (node == NULL || node->n >= number)
	{
		new->next = node;
		*head = new;
		return (new);
	}
	while (node && node->next && node->next->n < number)
		node = node->next;

	new->next = node->next;
	node->next = new;

	return (new);
}
