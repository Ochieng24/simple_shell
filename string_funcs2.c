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
<<<<<<< HEAD
<<<<<<< HEAD
	int x;

	x = 0;
	while (src[x] != '\0')
	{
		dest[x] = src[x];/*Copies each character from src to dest*/
		x++;
	}
	if (src[x] == '\n')/*If last char of src is a newline, copy to dest*/
		dest[x] = '\n';
	return (dest);/*Returns the destination string*/
=======
=======
>>>>>>> origin
	int a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	if (src[a] == '\n')
		dest[a] = '\n';
	return (dest);
<<<<<<< HEAD
>>>>>>> bd80c0c9515f958508f16b8b7078b3f9883bce0a
=======
=======
	int x;

	x = 0;
	while (src[x] != '\0')
	{
		dest[x] = src[x];/*Copies each character from src to dest*/
		x++;
	}
	if (src[x] == '\n')/*If last char of src is a newline, copy to dest*/
		dest[x] = '\n';
	return (dest);/*Returns the destination string*/
>>>>>>> origin/master
>>>>>>> origin
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
		result = *s1 - *s2;/*Calculates diff btw the char of s1 and s2*/
		if (*s1 == 0 || *s2 == 0)/*If either string ends, break the loop*/
			break;
		s1++;
		s2++;
	} while (result == 0);

	return (result);/*Returns diff btw the char or 0 if the str are equal*/
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
<<<<<<< HEAD
<<<<<<< HEAD
	int x = 0, result = *s1 - *s2;

	while (x <= n)
=======
	int a = 0, res = *s1 - *s2;

	while (a <= n)
>>>>>>> bd80c0c9515f958508f16b8b7078b3f9883bce0a
=======
	int a = 0, res = *s1 - *s2;

	while (a <= n)
=======
	int x = 0, result = *s1 - *s2;

	while (x <= n)
>>>>>>> origin/master
>>>>>>> origin
	{
		result = *(s1++) - *(s2++);/*Calculates diff btw char of s1 and s2*/
		if (result != 0)/*If characters differ, break the loop*/
			break;
<<<<<<< HEAD
<<<<<<< HEAD
		x++;
=======
		a++;
>>>>>>> bd80c0c9515f958508f16b8b7078b3f9883bce0a
=======
		a++;
=======
		x++;
>>>>>>> origin/master
>>>>>>> origin
	}

	return (result);/*Returns diff btw the char or 0 if the str are equal*/
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

	l = _strlen(s);/*Calls a function _strlen to get the length of the string*/
	l--;
	while (l >= 0)
	{
		temp = num;
		num = num + (s[l] - '0') * mult;/*Converts char to int & adds it to num*/
		if (num < temp || num > INT_MAX)
			return (-1);/*Returns -1 if overflow or underflow occurs*/
		l--;
		mult *= 10;/*Multiplies mult by 10 to move to the next digit*/
	}
	return (num);/*Returns the converted integer value*/
}
