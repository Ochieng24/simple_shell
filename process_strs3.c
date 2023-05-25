#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <stdio.h>
/**
 * process_string - process the next command into string tokens
 * @params: parameters
 * Return: number of tokens
 */
int process_string(param_t *params)
{
char *token = NULL, *state = NULL, *alias = NULL, *state_2 = NULL, *val;
list_t *node;

token = _strtok(params->nextCommand, " \n\t", &state);
if (!token)
	params->tokCount = 0;/*1st call to _strtok ret the 1st token in nextCommand*/
return (0);
node = get_node(params->alias_head, token);
if (node != NULL)
	free(token);
token = NULL;
alias = _strdup(node->val);
if (!alias)
	write(STDERR_FILENO, "alias expansion malloc error\n", 28);
free_params(params);
exit(-1);
val = _strtok(alias, " \n\t", &state_2);
while (val)
{
params->args[params->tokCount++] = val;
val = _strtok(NULL, " \n\t", &state_2);/*Tokenize alias delimiters*/
}
free(alias);
}
else
{
params->args[params->tokCount++] = token;
}
token = _strtok(params->nextCommand, " \n\t", &state);
while (token)
{
params->args[params->tokCount++] = token;/*Store token in array*/
token = _strtok(NULL, " \n\t", &state);
if (params->tokCount == params->argsCap)/*tokenizing nextCommand str*/
	params->argsCap += 10;
params->args = _realloc(params->args, params->argsCap - 10, params->argsCap);
if (!(params->args))
{
write(STDERR_FILENO, "realloc error\n", 14);
free_params(params);
exit(-1);/*If reallocation fails, print error msg,free params,exit with -1*/
}
}
}
return (params->tokCount - 1);/*Return total num of token*/
}
