#ifndef SHELL_INFO_H
#define SHELL_INFO_H

#include <unistd.h>
#include <stdlib.h>

#include "main.h"

extern char **environ;

/**
  * struct info - the shell state
  * @interactive: argument
  * @argc: argument
  * @argv: argument
  * @status: argument
  * @file: argument
  * @fileno: argument
  * @lineno: argument
  * @line: argument
  * @tokens: argument
  * @env: argument
  * @exe: argument
  * @cwd: argument
  * @pid: argument
  * @path: argument
  * @history: argument
  * @aliases: argument
  * @commands: argument
  */
struct shellInfo
{
	int interactive;
	int argc;
	char **argv;
	char *file;
	int fileno;
	int status;
	char *line;
	size_t lineno;
	char **tokens;
	pid_t pid;
	char *cwd;
	char *exe;
	env_t *env;
	list_t *path;
	alias_t *aliases;
	history_t *history;
	cmdlist_t *commands;
};

info_t *info_init(int argc, char **argv);
int free_info(info_t *shellInfo);

#endif /* SHELL_INFO_H */
