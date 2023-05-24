#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "listing.h"
#include "main.h"
#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - realloc the line buffer
 * @line: to be buffered
 * @oldSize: something borrowed
 * @newSize: something blue
 *
 * Return: new allocated buffer
 */
char *rlLine(char **line, unsigned int oldSize, unsigned int newSize)
{
	char *fresh_line = NULL;
	unsigned int x;

	fresh_line = malloc(newSize);
	if (fresh_line)
	{
		for (x = 0; x < oldSize; x++)
			fresh_line[x] = (*line)[x];
		free(*line);
		*line = fresh_line;
	}
	return (fresh_line);
}
/**
 * _getline - gets a line of chars from standard input
 * @params: parameters
 *
 * Return: count of chars
 */
int _getline(param_t *params)
{
	char *lane = NULL;
	static unsigned int bufSize = BUFFER_SIZE;
	char *mod_head = lane;
	unsigned int l;

	lane = malloc(BUFFER_SIZE);/*Allocate memory for the buffer*/
	do {
		l = read(0, mod_head, BUFFER_SIZE);
		if (l == 0)/*If no characters are read, break the loop*/
			break;
		mod_head += l;/*Move the pointer to the next position in the buffer*/
		if (mod_head >= (lane + BUFFER_SIZE - 1 - READ_SIZE))
		{
			lane = rlLine(&lane, bufSize, bufSize * 2);/*Expand buffer sizec*/
			bufSize *= 2;
		}
	} while (*(mod_head - 1) != '\n');/*Continu reading till newline char is got*/

	free(params->buffer);/*Free the previously allocated buffer in params*/
	params->buffer = lane;
	if (l == 0)
		return (-1);
	return (_strlen(params->buffer));/*Return length the buffer)*/
}
