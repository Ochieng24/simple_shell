#include "main.h"
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - Gets environment var value
 * @name: name of the env var to be returned
 * @params: Ptr to env list
 * Return: ptr to environ variables value
 */
char *_getenv(char *name, param_t *params)
{
list_t *pointing_list = params->env_head;
while (pointing_list)/*iterates while 'pointing_list' is not NULL */
{
if (!_strcmp(name, pointing_list->str))
return (_strdup(ptr->val));/* Return a duplicated str */
pointing_list = pointing_list->next;/* Move 'pointing_list' to the next node */
}
return (NULL);/*return NULL if no match*/
}
