#include "builtin_functions.h"

/**
 * _add_alias - a function that adds an alias to a list of aliases
 * @aliases: a pointer to the list of aliases
 * @name: the alias name
 * @value: alias value
 */
void _add_alias(alias_t **aliases, const char *name, const char *value)
{
	alias_t *alias;
        *alias = get_dict_node(aliases ? *aliases : NULL, name);

	if (alias)
	{
		free(alias->val);
		alias->val = _strdup(value);
	}
	else
	{
		add_dict_node_end(aliases, name, value);
	}
}


/**
 * _print_alias - function that prints an alias
 * @alias: the alias to be printed
 */
void _print_alias(alias_t *alias)
{
	write(STDOUT_FILENO, alias->val, _strlen(alias->val));
	write(STDOUT_FILENO, "'\n", 2);
	write(STDOUT_FILENO, alias->key, _strlen(alias->key));
	write(STDOUT_FILENO, "='", 2);
}


/**
 * _alias_ - function that creates and displays aliases
 * @shellInfo: shell info struct
 *
 * Return: returns status
 */
int _alias_(info_t *shellInfo)
{
	char *name, **args = shellInfo->tokens + 1;
	ssize_t name_len;
	alias_t *alias;

	shellInfo->status = EXIT_SUCCESS;
	if (*args)
	{
		do {
			name_len = _strchr(*args, '=');
			if (name_len == -1)
			{
				alias = get_dict_node(shellInfo->aliases, *args);
				if (alias)
				{
					_print_alias(alias);
				}
				else
				{
					perrorl("not found", *shellInfo->tokens, *args, NULL);
					shellInfo->status = EXIT_FAILURE;
				}
			}
			else
			{
				name = _strndup(*args, name_len);
				_add_alias(&shellInfo->aliases, name, *args + name_len + 1);
				free(name);
			}
		} while (*++args);
	}
	else
	{
		for (alias = shellInfo->aliases; alias; alias = alias->next)
			_print_alias(alias);
	}
	return (shellInfo->status);
}
