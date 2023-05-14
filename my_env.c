#include "main.h"
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - Retrieves an environ` variable's value
 * @name: The environment vares to be returned name
 * @params: Pointer to the environ list-containing parameter struct
 * Return: pointer to the environ vares value, or NULL if no
 * matchs seen vares value replicated & returned str.no match func ret NULL
 */

char *_getenv(char *name, param_t *params)
{
list_t *ptr = params->env_head;
while (ptr)
{
if (!_strcmp(name, ptr->str))
return (_strdup(ptr->val));
ptr = ptr->next;
}
return (NULL);
}
