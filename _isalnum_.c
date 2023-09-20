#include "main.h"
/**
 *_isalnum_ - checks if the character is alphanumeric
 *@b: character to check
 *Return: If b is alphanumeric, return 1. Otherwise, return 0.
 */
bool _isalnum_(int b)
{
	return (_isalpha_(b) || _isdigit_(b));
}
