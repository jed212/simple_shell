#include "main.h"

/**
 * removes_comments - function that removes all comments from a command
 * @cmd: pointer to the cmd to process
 */
void removes_comments(cmdlist_t *cmd)
{
	char **tokens;
	char **new;
	char *tmp;

	for (tokens = cmd->tokens; *tokens; ++tokens)
	{
		if (**tokens == '#')
		{
			tmp = *tokens;
			*tokens = NULL;
			new = _arrdup_(cmd->tokens);
			*tokens = tmp;
			free_tokens(&(cmd->tokens));
			cmd->tokens = new;
			free_cmdlist(&(cmd->next));
			return;
		}
	}
}
