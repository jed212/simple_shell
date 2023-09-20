#include "main.h"
/**
 *quote_is_none - get state length and next state
 *@str: string
 *@state: state
 *Return: length of state
 */
size_t quote_is_none(const char *str, quote_state_t *state)
{
	size_t len = 0;


	while (is_itspace(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 *quote_is_word - get state length and next state
 *@str: string
 *@state: state
 *Return: length of state
 */
size_t quote_is_word(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && !is_itspace(*str) && !is_itquote(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 *quote_is_double - get state length and next state
 *@str: string
 *@state: state
 *Return: length of state
 */
size_t quote_is_double(const char *str, quote_state_t *state)
{
	size_t len = 0;


	while (*str && *str != '"')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 *quote_is_single - get state length and next state
 *@str: string
 *@state: state
 *
 * Return: length of state
 */
size_t quote_is_single(const char *str, quote_state_t *state)
{
	size_t len = 0;


	while (*str && *str != '\'')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 *quote_is_escape - get state length and next state
 *@str: string
 *@state: state
 *Return: length of state
 */
size_t quote_is_escape(const char *str, quote_state_t *state)
{
	if (*str)
	{
		if (state && *(++str))
			*state = quote_state(*str);
		return (1);
	}
	return (0);
}
