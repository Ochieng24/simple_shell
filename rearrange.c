#include <stdlib.h>
#include <stdio.h>
/**
 * _realloc - reallocates a memory block using malloc
 * @ptr: old block
 * @old_size: size of the old block
 * @new_size: size of the new block
 *
 * Return: pointer to new block
 */
char **_realloc(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newpointer = NULL;
	unsigned int number, x;

	if (!ptr)
	{
		free(ptr);
		return (malloc(sizeof(*ptr) * new_size));
	}
	/*Check if new_size is 0*/
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	/* Check if new_size is equal to old_size*/
	if (new_size == old_size)
		return (ptr);
	/*Determine the number of elements to copy*/
	number = old_size < new_size ? old_size : new_size;
	/*Allocate memory for newPtr*/
	newpointer = malloc(8 * new_size);
	/*Copy elements from ptr to newPtr*/
	if (newpointer)
	{
	/* Initialize newPtr elements to NULL*/
		for (x = 0; x < new_size; x++)
			newpointer[x] = NULL;
		for (x = 0; x < number; x++)
			newpointer[x] = ptr[x];
		free(ptr);
	}
	return (newpointer);
}
