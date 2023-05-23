#include <stdlib.h>
#include "shell.h"
#include "main.h"
/**
 * isDelim - check if a character is one of the delimiters
 * @c: character
 * @delim: delimeters
 *
 * Return: 1 if it is a delimiter, 0 otherwise
 */
int isDelim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
/**
 * _strtok - strtok_r
 * @str: string to be passed
 * @delim: delimiters for tokens
 * @savePtr: state
 *
 * Return: next token found in string, NULL if not found
 */
char *_strtok(char *str, char *delim, char **savePtr)
{
	char *ptr, *mod, *end;
	int qF = 0;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && isDelim(*ptr, delim))
		ptr++;
	mod = ptr;
	if (*ptr == '\0')
	{
	return (NULL);
	}
	if (*ptr == '\'')
	{
		ptr++;
		mod = _strchr(ptr, '\'');
		if (!mod)
		{
			_printf("no matching quote found!\n");
			exit(-1);
		}
		*mod = '\0';
		*savePtr = mod + 1;
		return (_strdup(ptr));
	}
	while (*mod)
	{
		if (*mod == '\'')
			qF = 1;
	if (isDelim(*mod, delim) && qF == 0)
	break;
		mod++;
	}
	if (*mod == '\0')
	*savePtri = mod;
else
*savePtr = mod + 1;
*mod = '\0';
return (_strdup(ptr));
}
