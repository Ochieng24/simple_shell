#include <stdlib.h>
#include "listing.h"
/**
 * move_left -removes leading 0's
 * @a: buffer
 * @size: size of array
 * @num: no of digits in binary num
 * Return: buffer
 */
char *move_left(char *a, int size, int num)
{
int x;
char *points;

for (x = 0, points = (a + size - num); x < num; x++, points++)
*(a + x) = *points;/*move each character to the left*/
*(a + num) = '\0';/*Terminate the string with null character*/
return (a);
}
/**
 * get_binary - converts unsigned int to binary
 * @n: integer
 * Return: * to binary
 */
char *get_binary(unsigned int n)
{
char *points = NULL;
unsigned int x, nummer = 0, dimension = 0;

if (n == 0)
{
points = malloc(2);/*allocate nmemory for 0 and Null char*/
if (points)
{
points[0] = '0';/*store 0 in the buffer*/
points[1] = '\0';/*terminate the string with null char*/
}
return (points);
}
dimension = sizeof(int) * 8 + 1;/*calc dimension required for binary rep*/
points = malloc(size);
if (points)
{
for (x = 0; x < dimension; x++)
{
points[x] = '0';/*initialises each bit as '0'*/
}
points[dimension - 1] = '\0';/*terminate the string with null character*/
x = dimension - 2;
while (n != 0)
{
points[x] = n % 2 == 0 ? '0' : '1';/*converts rem of n/2 into a 1 or 0*/
nummer++;
n = n / 2;
x--;
}
nummer++;
points = move_left(points, dimension, nummer);/*remov lead 0s from binary rep*/
}
return (points);
}
/**
 * get_char - returns a copied char
 * @c: char to be copied
 * Return: ptr of copied char
 */
char *get_char(char c)
{
char *points = NULL;

points = malloc(2);/*allocate memory for the char and null char*/
if (points == NULL)
{
return (NULL);
}
points[0] = c;/*store the char in the buffer*/
points[1] = '\0';/*terminate the string with null char*/
return (points);
}
/**
 * get_string - returns a new duplicated string
 * @s: string to be copied
 * Return: Null if string is null, else pointer of copied string
 */
char *get_string(char *s)
{
char *points = NULL;
int x, z;

if (s == NULL)
{
points = malloc(7);/*allocate memory for null and null char*/
if (points == NULL)
return (NULL);
points[0] = '(';
points[1] = 'n';
points[2] = 'u';
points[3] = 'l';
points[4] = 'l';
points[5] = ')';
points[6] = '\0';/*terminate the str with null char*/
return (points);
}
for (x = 0; s[x] != '\0'; x++)
{
;
}
points = (char *)malloc(x *sizeof(char) + 1);
if (points == NULL)
{
return (NULL);
}
for (z = 0; z < x; z++)
{
points[z] = s[z];/*copy @ char from original strto new str*/
}
points[z] = '\0';
return (points);
}
/**
 * get_number - put integer into a memory block as string
 * @n: integer
 *
 * Return: pointer to integer string, NULL on error
 */
char *get_number(int n)
{
int x, l = 0, temporary;
char *buf_size = NULL;
/* find number bytes to allocate */
temporary = n;
while (temporary >= 10 || temporary <= -10)
{
temporary /= 10;
l++;
}
l++;
if (n < 0)
l++;
buf_size = malloc(sizeof(char) * (l + 1));/*allocate memory for str rep of no*/
if (buf_size)
{
buf[l] = '\0';/*terminate the str with null char*/
if (n < 0)
{
buf_size[0] = '-';/*store neg sign in buffer*/
}
x = l - 1;
while (n >= 10 || n <= -10)
{
temporary = (n % 10) >= 0 ? n % 10 : -(n % 10);/*store last digit in buffer*/
buf_size[x] = temporary + '0';
x--;
n /= 10;
}
temporary = (n % 10) >= 0 ? n % 10 : -(n % 10);
buf_size[x] = temporary + '0';
}
return (buf_size);
}
