#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
/**
 * _strcpy - copies str  to anther memory
 * @src: * to source str
 * @dest: * to the dest address
 *
 * Return: pointer to the dest
 */
char *_strcpy(char *dest, const char *src)
{
	int x;

	x = 0;
	while (src[x] != '\0')
	{
		des[x] = src[x];
		x++;
	}
	if (src[x] == '\n')
		dest[x] = '\n';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: int less than, equal to, or greater than 0 if s1 is, respectively
 * less than, equal to, or greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int result = 0;

	do {
		result = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (result == 0);

	return (result);
}

/**
 * _strcmp_n - compares n bytes of 2 strs
 * @s1: str 1
 * @s2: str 2
 * @n: num of bytes to comp
 *
 * Return: int less than, equal to, or greater than 0 if s1 is, respectively
 * less than, equal to, or greater than s2
 */
int _strcmp_n(char *s1, char *s2, int n)
{
	int x = 0, result = *s1 - *s2;

	while (x <= n)
	{
		result = *(s1++) - *(s2++);
		if (result != 0)
			break;
		x++;
	}

	return (result);
}


/**
 * _atoi - turn a str into an int
 * @s: string to eval
 * Return: n the val of first num in the str
 */
int _atoi(char *s)
{
	int num, temp, l, mult = 1;

	num = 0;
	temp = 0;

	l = _strlen(s);
	l--;
	while (l >= 0)
	{
		temp = num;
		num = num + (s[l] - '0') * mult;
		if (num < temp || num > INT_MAX)
			return (-1);
		l--;
		mult *= 10;
	}
	return (num);
}
