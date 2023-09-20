#include "main.h"
/**
 *_isnumber_ - check if a string consists only of digits
 *@st: pointer to string
 *Return: true or false
 */
bool _isnumber_(const char *st)
{
	if (st)
	{
		while (*st)
		{
			if (!_isdigit_(*st++))
				return (false);
		}
		return (true);
	}
	return (false);
}
