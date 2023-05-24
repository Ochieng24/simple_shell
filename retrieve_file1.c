#include "main.h"
#include <stdlib.h>
#include "listing.h"

/**
 * rev_string - puts characters in a string in reverse order.
 * @s: a pointer to the reversed version of a null-terminated string.
 */
void rev_string(char *s)
{
int h, t;
int l;
char temp;
if (s == NULL)
{
s = "(null)";
}
for (l = 0; s[l] != '\0'; l++)
;
h = 0;
t = l - 1;
while (h < t)
{
temp = *(s + h);
*(s + h) = *(s + t);
*(s + t) = temp;
h++;
t--;
}
}
/**
*get_rev - returns a reversed copy of a string
*@s: returns a string's mirrored copy.
*Return: reversed str
*/
char *get_rev(char *s)
{
char *points = NULL;/*declare a * var & initialise it to null*/

points = get_string(s);
if (!points)/*check if points is null*/
{
return (NULL);
}
if (s)
{
rev_string(points);/*call the rev_string func as an arg*/
}
return (points);/*return the revesed str points*/
}

/**
 * rot13 - encrypts a string
 * @s: str to be encrypted
 *
 * Return: * to encrypted str
 */
char *rot13(char *s)
{
char *points;/*declare a * var*/
int x;
char charac[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char ray[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
'j', 'k', 'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E',
'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
for (points = s; *points != '\0'; points++)/*iterate thru each char in str*/
{
for (x = 0; x < 52; x++)/*iterate thru each char in array*/
{
if (*points == charac[x])/*check if teh current char matches char in array*/
{
*points = ray[x];/*rep teh char with the corresponding array char*/
break;
}
}
}
return (s);/*return modified str*/
}

/**
 * get_rot13 - get rot13
 * @s: str
 * Return: * to str
 */
char *get_rot13(char *s)
{
char *points = NULL;

points = get_string(s);/*declare a pointer var and initialise*/
if (!points)
return (NULL);
if (s)
{
rot13(points);/*call the rot13 function as arg*/
}
return (points);
}
