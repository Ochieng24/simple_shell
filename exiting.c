#include <stdlib.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
/**
 * validNum - check if string is a valid number
 * @s: string
 *
 * Return: 0 if false, 1 otherwise
 */
int validNum(char *s)
{
	while (*s)/*loop thr char*/
	{
		if (*s > '9' || *s < '0')/*if char ! a digit*/
			return (0);/*Return 0 if char !a digit*/
		s++;/*to next char*/
	}
	return (1);/*Return 1 all char digits*/
}
/**
 * _myExit - buildin exit function
 * @params: parameters
 */
void _myExit(param_t *params)
{
	int point = 0;

	if (!params->args[1])/*no argument after command*/
	{
		point = params->point;/* current status*/
		free_params(params);/* set mem free*/
		exit(point);/* end with current status*/
	}
	if (validNum(params->args[1]))/*argument valid nmbr*/
	{
		point = _atoi((params->args)[1]);/* convert to integer*/
		if (point == -1)
		{
			write_error(params, "Illegal number: ");/* error msg to strd output*/
			write(STDERR_FILENO, params->args[1],/*newline to strd output*/
			      _strlen(params->args[1]));/*argument to  strd error output*/
			write(STDERR_FILENO, "\n", 1);/*new line char to strd output*/
			params->point = 2;/*set 2*/
			return;/*Return*/
		}
		free_params(params);/*mem allctd for prmtr*/
		exit(point);/*end prog wth spcfd status*/
	}
	else
	{
		params->point = 2;/*set 2*/
		write_error(params, "Illegal number: ");
		write(STDERR_FILENO, params->args[1], _strlen(params->args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
}
