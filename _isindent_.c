#include "main.h"
/**
 *_isident_ - checks if the character is a valid identifier character
 *@b: character to check
 *Return: If b is an identifier character, return 1. Otherwise, return 0.
 */
bool _isident_(int b)
{
	return (b == '_' || _isalnum_(b));
}
