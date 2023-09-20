#ifndef BUILTIN_FUNC_H
#define BUILTIN_FUNC_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

#define ALIAS_HELP "alias [KEY[=VALUE] ...]"
#define ALIAS_DESC								\
	"Define and display aliases.\n\0"					\
	"If given no arguments, display existing aliases.\0"	\
	"Otherwise, an alias is defined for each KEY=VALUE pair.\0"	\
	"For each KEY with no VALUE the corresponding alias is displayed.\0"	\
	"If VALUE ends with a space, the following word will be expanded.\0"	\
	"\0"

#define CD_HELP "cd [DIR]"
#define CD_DESC									\
	"Change the current working directory to DIR.\n\0"			\
	"If DIR is omitted, it defaults to the value of the variable HOME.\0"	\
	"If DIR is -, the current directory reverts to its previous value.\0"	\
	"\0"

#define ENV_HELP "env"
#define ENV_DESC								\
	"Print the environment.\0"						\
	"\0"

#define EXEC_HELP "exec COMMAND [ARGS ...]"
#define EXEC_DESC								\
	"Replace the shell with the given command.\n\0"				\
	"COMMAND is executed, replacing the executing shell.\0"			\
	"ARGS are passed as positional arguments to COMMAND.\0"			\
	"If the command cannot be executed, the shell exits.\0"			\
	"\0"

#define EXIT_HELP "exit [STATUS]"
#define EXIT_DESC								\
	"Exit the shell with a status of STATUS.\n\0"				\
	"If STATUS is omitted, the exit status is that of the last command.\0"	\
	"\0"

#define HELP_HELP "help [BUILTIN]"
#define HELP_DESC								\
	"Display infor about the builtin commands.\n\0"			\
	"If BUILTIN is omitted, the available commands are displayed.\0"	\
	"\0"

#define SETENV_HELP "setenv [NAME [VALUE]]"
#define SETENV_DESC								\
	"Set VALUE as the env variable NAME.\n\0"			\
	"If NAME is omitted, the shell execution env is displayed.\0"	\
	"If VALUE is omitted, the value of NAME is set to an empty string.\0"	\
	"\0"

#define UNSETENV_HELP "unsetenv NAME"
#define UNSETENV_DESC								\
	"Remove variable NAME from the env.\0"			\
	"\0"

typedef int (*builtin_fp)(info_t *);

/**
 * struct builtin - builtin command
 * @name: name of the command
 * @f: the function to call
 * @help: the command usage
 * @desc: the command description
 */
struct builtin
{
	const char *name;
	builtin_fp f;
	const char *desc;
	const char *help;
};

const struct builtin *get_builtin(const char *name);
const struct builtin *get_builtins(void);

int _alias_(info_t *shellInfo);
int _cd_(info_t *shellInfo);
int _exit_(info_t *shellInfo);
int _exec_(info_t *shellInfo);
int _env_(info_t *shellInfo);
int _help_(info_t *shellInfo);
int _setenv_(info_t *shellInfo);
int _unsetenv_(info_t *shellInfo);

#endif /* _BUILTIN_FUNC_H_ */
