#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <sys/stat.h>
/**
 *struct _bltn_cmmnd - Short description
 *@name: First member
 *@function: Second member
 **
 ** Description: Longer description
 */
struct bltn_cmmnd
{
	char *name;
	int (*function)(char **array_of_tokens);
};


void prompt(void);
void _sig_int_handler_(int signal);
ssize_t _getline(char **input,
size_t *number_of_malloc_bytes_allocated, int status);
char **_array_maker_(char *input, char *delimiter);
int _fork(char *command, char **array_of_tokens);
char *_which(char *filename);
int _print_env(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *malloc_char(char **string, size_t size_of_malloc, char *error_message);
char **malloc_array(char **array, size_t size_of_malloc, char *error_message);
int copy_array(char **destination, char **source);
int _env_name_exists(const char *name);
int _env_length(void);
void free_which(char **path_var, char **array_of_tokens);
void free_main(char **array_of_tokens, char *input);
void _rev_str_(char *str);
char *__itoa__(size_t cmmnd_nmb);
int _dgt_cntr_(size_t cmmnd_nmb);
int error_not_found(char **arvs, char **array_of_tokens, size_t command_num);
int _is_builtin_(char **array_of_tokens);
int _bltn_handler_(char **array_of_tokens);
int _exit_builtin(char **array_of_tokens);
int _env_builtin(char **array_of_tokens);
#endif
