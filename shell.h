#ifndef SHELL_H
#define SHELL_H
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
 *struct _bltn_cmmnd - returns a pointer to a string
 *Description - returns a pointer to string
 *@n: First member
 *@function: Second member
 **
 ** Description: Longer description
 */
struct _bltn_cmmnd
{
	char *n;
	int (*function)(char **token_arr);
};
void display_prompt(void);
void _sig_int_handler_(int signal);
ssize_t _getline_(char **input, size_t *malloc_bytes_allocated, int status);
char **_array_maker_(char *input, char *delimiter);
int _fork(char *cmd, char **token_arr);
char *_which_(char *file_name);
int print_env(void);
char *_getenv_(const char *n);
int _setenv_(const char *n, const char *v,  int overwrite);
int _unsetenv_(const char *n);
char *malloc_char_(char **string, size_t size_of_malloc, char *error_msg);
char **malloc_array_(char **array, size_t size_of_malloc, char *error_msg);
int cpy_arr(char **dest, char **src);
int name_exists(const char *n);
int _env_len(void);
void _free_which(char **path_var, char **token_arr);
void _free_main(char **token_arr, char *input);
void _rev_str_(char *str);
char *__itoa__(size_t cmd_num);
int _counter_(size_t cmd_num);
int error_not_found(char **arvs, char **token_arr, size_t cmd_num);
int exit_builtin_(char **token_arr);
int _env_(__attribute((unused)) char **token_arr);
int _bltn_handler_(char **token_arr);
int _is_builtin_(char **token_arr);
#endif
