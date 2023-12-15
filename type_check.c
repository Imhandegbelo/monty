#include <ctype.h>
#include "monty.h"

/**
 * is_digit - checks if a string is a digit
 * @string: the string
 *
 * Return: 1 if true, 0 otherwisse
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);

}

/**
 * isnumber - checks if a string is a number
 * @str: the string
 *
 * Return: 1 if number, 0 otherwise.
 */
int isnumber(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}
