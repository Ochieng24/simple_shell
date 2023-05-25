#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "listing.h"
/**
 * isDelim - check if a character is one of the delimiters
 * @c: character
 * @delim: delimeters
 * Return: 1 if it is a delimiter, 0 otherwise
 */
int isDelim(char c, char *delim)
{
	while (*delim)/*loop thru each char in the delim str*/
	{
		if (c == *delim)/*if current char matches delim char*/
			return (1);/*return 1*/
		delim++;/*move to next char in delim str*/
	}
	return (0);/*ret 0 if no match is found indicating its ! delim*/
}
/**
 * _strtok - strtok_r
 * @str: string to be passed
 * @delim: delimiters for tokens
 * @savePtr: state*
 * Return: next token found in string, NULL if not found
 */
char *_strtok(char *str, char *delim, char **savePtr)
{
	char *ptr, *mod, *end;
	int qF = 0;/*initialise qF to 0*/

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)/*find end of the str*/
		end++;
	while (*ptr && isDelim(*ptr, delim))/*skip lead delims*/
		ptr++;
	mod = ptr;
	if (*ptr == '\0')
		return (NULL);
	if (*ptr == '\'')/*if 1st char is a quote*/
	{
		ptr++;
		mod = _strchr(ptr, '\'');/*find closing quote*/
		if (!mod)
			_printf("no matching quote found!\n");
		exit(-1);/*exit if theres no match*/
		*mod = '\0';
		*savePtr = mod + 1;/*set savePtr to next char*/
		return (_strdup(ptr));/*return substr within quotes*/
	}
	while (*mod)
	{
		if (*mod == '\'')
			qF = 1;/*if quote found,set qF to to 1*/
	if (isDelim(*mod, delim) && qF == 0)/*if delim found and ! in quotes break*/
	break;
		mod++;
	}
	if (*mod == '\0')
	*savePtr = mod;
	else
		*savePtr = mod + 1;/*set savePtr to next char after delim*/
	*mod = '\0';
	return (_strdup(ptr));/*return the token*/
}
