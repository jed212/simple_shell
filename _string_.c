#include "shell.h"

/**
 *_rev_str_ - reverses a string
 *@str: the string
 *
 *Return: void
 */
void _rev_str_(char *str)
{
	int i, len;
	char tmp;


	len = 0;
	while (str[len] != '\0')
		len++;
	len--;
	for (i = 0; i < len; i++, len--)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
}

/**
 ** __itoa__ - converts int to a string
 **Description - converts integer to string
 * @cmd_num: number to convert
 **
 *Return: converted integer
 **/
char *__itoa__(size_t cmd_num)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int i = 0;


	do {
		str[i++] = cmd_num % 10 + '0';
		cmd_num /= 10;
	} while (cmd_num > 0);
	str[i] = '\0';
	_rev_str_(str);


	return (str);
}
