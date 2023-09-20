#include "hsh.h"

/**
 * expand - a function that performs variable expansion on the current set of tokens
 * @shellInfo: shell information
 * @tokptr: pointer to the current tokens
 */
void expand(info_t *shellInfo, char ***tokptr)
{
	char **new = NULL;
	char **old;
       	char **tmp;
	char **tokens;

	for (tokens = *tokptr; **tokptr; ++(*tokptr))
	{
		old = new;
		tmp = _expand_vars(shellInfo, tokptr);
		new = arrjoin(old, tmp);

		free_tokens(&tmp);
		free_tokens(&old);
		free(**tokptr);
	}
	free(tokens);
	*tokptr = new;
}

/**
 * expand_vars - function that performs variable expansion on a token
 * @shellInfo: shell information
 * @tokptr: a pointer to the current tokens
 * Return: returns the expanded token
 */
char **expand_vars(info_t *shellInfo, char ***tokptr)
{
	char *var = NULL, *val = NULL;
	char *tok = **tokptr;
	size_t pos = 0, var_len, val_len;
	quote_state_t st = QUOTE_NONE;

	while (var_len = val_len = 1, tok[pos])
	{
		if (quote_state_len(tok + pos, st) == 0)
		{
			if ((st & (QUOTE_DOUBLE | QUOTE_SINGLE)) && !tok[++pos])
				break;
			st = quote_state(tok[pos]);
			if (st & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				++pos;
			continue;
		}
		if ((st & (QUOTE_DOUBLE)) && (quote_state(tok[pos]) & QUOTE_ESCAPE))
		{
			if (!tok[++pos] || !tok[++pos])
			{
				break;
			}
			st = quote_state(tok[pos]);
			if (st & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				++pos;
			continue;
		}
		if (st & (QUOTE_ESCAPE))
		{
			if (!tok[++pos] || !tok[++pos])
				break;
			st = quote_state(tok[pos]);
			if (st & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				++pos;
			continue;
		}
		if (st & (QUOTE_SINGLE))
		{
			pos += quote_state_len(tok + pos, st);
			if (tok[pos])
				++pos;
			continue;
		}
		if (tok[pos] != '$')
		{
			++pos;
			continue;
		}
		if (tok[pos + 1] == '$')
		{
			val = num_to_str(shellInfo->pid);
		}
		else if (tok[pos + 1] == '?')
		{
			val = num_to_str(shellInfo->status);
		}
		else if (_isident_(tok[pos + 1]) && !_isdigit_(tok[pos + 1]))
		{
			while (_isident_(tok[pos + var_len + 1]))
				++var_len;

			var = _strndup(tok + pos + 1, var_len);
			val = get_dict_val(shellInfo->env, var);

			if (val)
				val = _strdup(val);
			else
				val = _strdup("");

			free(var);
			var = NULL;
		}
		if (val)
		{
			val_len = _strlen(val);
			**tokptr = malloc(sizeof(char) * (
					pos + val_len + _strlen(tok + pos + var_len) + 1
					));
			_memcpy(**tokptr, tok, pos);
			_memcpy(**tokptr + pos, val, val_len);
			_strcpy(**tokptr + pos + val_len, tok + pos + var_len + 1);

			free(tok);
			tok = **tokptr;
			free(val);
			val = NULL;
		}
		pos += val_len;
	}
	return (tokenize(**tokptr));
}
