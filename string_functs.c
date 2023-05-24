#include <stdlib.h>
/**
 *str_concat - joins two strs
 *@s1: first str param
 *@s2: Second str param
 *Return: 0 when unsuccessful,else, malloc ptr
 */
char *str_concat(char *s1, char *s2)
{
	char *points;
	int a = 0;
	int z = 0;
	int w = 0;

	if (s1 == NULL)/*checks if input is NULL*/
	{
		s1 = "";/*assign empty str to S1 if S1 is null*/
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[a] != '\0')/*iterate thru char of S1 till null char is reached*/
	{
		a++;/*increment value of a*/
	}
	while (s2[z] != '\0')
	{
		z++;
	}
	points = malloc((a * sizeof(char)) + (z * sizeof(char)) + 1);
	if (points == NULL)/*checks if allocation isnt successful*/
	{
		return (NULL);/*indicate failure*/
	}
	for (a = 0; s1[a] != '\0'; a++)/*copies char from S1 to concatenated str*/
	{
		points[a] = s1[a];/*copy char from S1 to points*/
		w++;
	}
	for (z = 0; s2[z] != '\0'; z++)/*copy char from s2 to conc str*/
	{
		points[w] = s2[z];
		w++;
	}
	points[w] = '\0';/*appends null char at the end of concatebated str*/
	return (points);
}
/**
 * string_nconcat - concat 2 strs
 * @s1: first string param
 * @s2: second string param
 * @n: amount of bytes for s2
 * Return: Null on failure, else ptr to malloc
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *points;
	unsigned int a = 0;
	unsigned int z = 0;

	if (s1 == NULL)/*checks if input str is null*/
	{
		s1 = "";
	}
	if (s2 == NULL)/*checks if s2 is null*/
	{
		s2 = "";
	}
	while (s1[a] != '\0')/*iterates thru S1 char till null char is enc*/
	{
		a++;
	}
	while (s2[z] != '\0')/*iterate thru char of s1 till null char is reached*/
	{
		z++;
	}
	if (n > z)
	{
		n = z;
	}
	points = malloc(sizeof(char) * (n + a) + 1);/*alloc mem for concat str*/
	if (points == NULL)
	{
		return (NULL);
	}
	for (a = 0; s1[a] != '\0'; a++)/*copy char from s1 to concatenated str*/
	{
		points[a] = s1[a];
	}
	for (z = 0; z < n; z++)
	{
		points[a + z] = s2[z];/*copy char fronm s2 to points*/
	}
	points[a + z] = '\0';/*appends null char at end of concatenated str*/
	return (points);
}
/**
 *_strlen - return len of a str
 *@s: string
 *Return: 0 if null, else len without null byte
 */
int _strlen(char *s)
{
	int l = 0;

	if (s == NULL)/*checks if S is NULL*/
	{
		return (0);/*if s is empty ret 0 to indicate empty*/
	}

	for (l = 0; s[l] != '\0'; l++)/*Iter thru char of s till a null char is got*/
		;/*Empty loop body,incre the val of "l" to count the char*/
	return (l);
}

/**
 * _strdup - copy str to a new alloc block of memory
 * @str: string
 *
 * Return: * to duplicated str, NULL if insufficient memory
 */
char *_strdup(char *str)
{
	int l = 0; /* index of terminating null byte */
	char *points = NULL;/*Decl a * to char named "points" and init it to NULL.
			      */

	if (!str)
		return (NULL);
	while (*str)/*Iterates thru char of str till a null char is encountered.*/
	{
		l++;/*Increments the value of "l" to move to the next character.*/
		str++;/*Increments the pointer to str to move to the next character.*/
	}
	points = (char *) malloc(sizeof(char) * (l + 1));/*Alloc mem for dupl*/
	if (points)
	{
		while (l >= 0)
			*(points + l--) = *(str--);/*Copy char from str in reverse order.*/
	}
	return (points);
}

/**
 * _strchr - locates a character in a string
 * @s: where to start looking
 * @c: values to find
 *
 * Return: pointer to begining of mem area
 */
char *_strchr(char *s, char c)
{
	int a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == c)/*Checks if the current character is equal to c.*/
			return (&s[a]);/*If found, returns a pointer to the current character.*/
		a++;
	}
	if (c == '\0')
		return (&s[a]);
	return (0);/* If c is not found and not a null character, returns NULL.
		     */
}

