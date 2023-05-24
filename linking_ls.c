#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "shell.h"
#include "main.h"

/**
 * list_len - the number of elements in a linked list_t list
 * @h: start of list
 *
 * Return: length of list
 */
size_t list_len(list_t *h)
{
	size_t z;/* Loop through the list and increment z for each node*/

	for (z = 0; h != 0; z++)
		h = h->next;
	return (z);/*Return the number of nodes in the list*/
}

/**
 * print_list - prints all the elements of a list_t list
 * @h: start of list
 *
 * Return: length  of list
 */
size_t print_list(list_t *h)
{
	int c;

	for (c = 0; h != 0; c++)/*Loop thru  list and print each node's*/
	{
		if (h->str == NULL)
			break;
		_printf("%s\n", h->str);
		h = h->next;
	}
	return (c);/*Return the number of nodes processed*/
}

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: start of list
 * @str: key
 * @val: value
 * Return: ptr to new head
 */
list_t *add_node(list_t **head, char *str, char *val)
{
	list_t *new;

	new = malloc(sizeof(list_t));/*Allocate memory for a new nod*/
	if (new == NULL)
		return (NULL);
	/*Allocate memory for a new node*/
	new->str = _strdup(str);
	new->len = _strlen(new->str);
	new->val = _strdup(val);
	new->valLen = _strlen(val);
	new->next = *head;
	*head = new;/*Update the head pointer to the new node*/

	return (new);/*Return the new node*/
}

/**
 * get_node - search for a node
 * @head: start of list_t  list
 * @str: key
 * Return: ptr to desired node, NULL if not found
 */
list_t *get_node(list_t *head, char *str)
{
	list_t *d;/*If the list is empty, return NULL*/

	if (!head)/*Iterate thru list to find node*/
		return (NULL);
	d = head;
	while (d)
	{
		if (!_strcmp(h->str, str))
			break;
		d = d->next;
	}
	return (d);/*Return the found node (or NULL if not found*/
}

/**
 * free_list - clears a linked list from mem
 * @head: ptr to head of linked list_t list
 */
void free_list(list_t *head)
{
	list_t *ptr = head;/*Iterate thru list and free mem */node

	while (head)
	{
		ptr = head->next;
		free(head->str);
		free(head->val);
		free(head);
		head = ptr;
	}
}
