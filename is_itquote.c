#include "main.h"
/**
 *is_itquote - check if a character is a quote
 *@b: the character to check
 *Return: If b is a quote, return 1. Otherwise, return 0.
 */
bool is_itquote(int b)
{
	return (b == '"' || b == '\'' || b == '\\');
}
