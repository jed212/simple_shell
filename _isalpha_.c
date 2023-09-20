#include "main.h"

/**
 *_isalpha_ - checks if the character is alphabetic
 *@b: character to check
 *Return: If b is alphabetic, return 1. Otherwise, return 0.
 */
bool _isalpha_(int b)
{
	return ((b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z'));
}
