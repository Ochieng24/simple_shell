#include "main.h"
#include "listing.h"
#include "shell.h"

/**
 * _printenv - prints the environment
 * @params: parameters
 *
 * Return: void
 */

void _printenv(param_t *params)
{
if (params->tokCount != 1)
{
_printf("env: %s: No such file or directory\n",/*print error msg*/
params->args[1]);
params->status = 2;/*status to indicate error*/
return;
}
print_list_env(params->env_head);/*prints environment variables*/
params->status = 0;/*indicates succes*/
}
/**
 * print_list_env - print the environment variables
 * @head: pointer to the head of the environment list
 */
void print_list_env(list_t *head)
{
if (head)
{
print_list_env(head->next);/*recursively prints the lists if head ! Null*/
if (head->str)
_printf("%s=%s\n", head->str, head->val);/*print var name and value*/
}
}
