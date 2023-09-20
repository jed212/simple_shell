#include "main.h"
/**
 *_isspace_ - check if a character is whitespace
 *@b: the character to check
 *Return: If  b is whitespace, return 1. Otherwise, return 0.
 */
bool _isspace_(int b)
{
	return (b == ' ' || (b >= 0x09 && b <= 0x0d));
}
