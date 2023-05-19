#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "listing.h"
#include "shell.h"
#include "main.h"

/**
 * get_builtin - Get built-in function
 * @params: Pointer to the param_t struct containing command parameters
 * Return: Function pointer to the built-in function. NULL if not found.
 */

void (*get_builtin(param_t *params))(param_t *)/*func definition*/
{
op_t options[] = {
{"clear", _clear},
{"setenv", _setenv},
{"exit", _myExit},
{"cd", _cd},
{"unsetenv", _unsetenv},
{"alias", _alias},
{"env", _printenv},
{NULL, NULL},
};
/*Decl to ptr var op and initialization to poin first element of array*/
op_t *trav = options;/*traverses arr and compares name of each element*/

while (trav->name)
{
if (!_strcmp(params->args[0], trav->name))
return (trav->func);/*return the associated func ptr if they match*/
trav++;
}
return (NULL);/*return null if no match*/
}
