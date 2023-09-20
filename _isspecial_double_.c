#include "main.h"
/**
 *_isspecialdouble_ - check if a character is special inside double quotes
 *@b: the character to check
 *Return: If b is special, return 1. Otherwise, return 0.
 */
int _isspecialdouble_(char b)
{
	return (b == '"' || b == '$' || b == '\\');
}
