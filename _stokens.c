#include "main.h"

/**
 * tokenize - function that splits a string
 * into tokens and dequotes
 * @str: the string
 * Return: returns NULL on failure otherwise
 * return array containing the tokens in str,
 * terminated by NULL.
 */
char **tokenize(const char *str)
{
	char **tokens;
	size_t cnt;
	const char *tok;
	quote_state_t state;

	if (str == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens(str) + 1));
	if (tokens == NULL)
	{
		return (NULL);
	}
	for (cnt = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++cnt)
	{
		tok = str;

		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}

		tokens[cnt] = _memdup(tok, str - tok + 1);

		if (!tokens[cnt])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[cnt][str - tok] = '\0';
	}
	tokens[cnt] = NULL;
	return (tokens);
}

/**
 * count_tokens_noquote - function that counts the words
 * in a string
 * @str: the string
 * Return: If str NULL, return -1.
 * otherwise return number of words in str.
 */
size_t count_tokens_noquote(const char *str)
{
	size_t tok_cnt;

	for (tok_cnt = 0; *str; ++tok_cnt)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !_isspace(*str));
	}
	return (tok_cnt);
}

/**
 * count_tokens - function that  computes the length
 * of a string after dequoting
 * @str: the string to be evaluated
 * Return: length of str
 */
size_t count_tokens(const char *str)
{
	size_t cnt;
	quote_state_t state;

	for (cnt = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++cnt)
	{
		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}
	}
	return (cnt);
}


/**
 * tokenize_noquote - function that splits a string into tokens
 * @str: the string
 * Return: return NULL, otherwise return array of tokens.
 */
char **tokenize_noquote(const char *str)
{
	char **tokens;
	const char *tok;
	size_t cnt;

	if (str == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens_noquote(str) + 1));
	if (!tokens)
		return (NULL);

	for (cnt = 0; *str; ++cnt)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok = str;
		do {
			++str;
		} while (*str && !_isspace(*str));

		tokens[cnt] = _memdup(tok, str - tok + 1);
		if (!tokens[cnt])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[cnt][str - tok] = '\0';
	}
	tokens[cnt] = NULL;

	return (tokens);
}

/**
 * free_tokens - function that frees & nullifies an array of strings
 * @tokens: a pointer to an array of tokens
 */
void free_tokens(char ***tokens)
{
	char **tok;

	if (tokens == NULL)
	{
		return;
	}
	tok = *tokens;
	if (!tok)
	{
		return;
	}

	while (*tok)
	{
		free(*tok++);
	}
	free(*tokens);
	*tokens = NULL;
}
