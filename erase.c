#include "main.h"
#include "shell.h"

/**
 * _clear - erases the shell screen
 * @params: parameters passed
 *
 * Return: void
 */
void _clear(param_t *params)
{
(void)params;/*suppress compiler warning*/
_printf("\033[2J\033[1;1H");/*prints ANSI escape char to clear & move cursor*/
