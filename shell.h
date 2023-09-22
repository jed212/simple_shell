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
void display_prompt(void);
void _sig_int_handler_(int signal);
ssize_t _getline(char **input,
size_t *number_of_malloc_bytes_allocated, int status);
char **_array_maker_(char *input, char *delimiter);
int _fork(char *cmd, char **token_arr);
char *_which(char *file_name);
int print_env(void);
char *_getenv_(const char *n);
int _setenv_(const char *n, const char *v,  int overwrite);
int _unsetenv_(const char *n);
char *malloc_char_(char **string, size_t size_of_malloc, char *error_msg);
char **malloc_array_(char **array, size_t size_of_malloc, char *error_msg);
int cpy_arr(char **destination, char **source);
int name_exists(const char *n);
int _env_length(void);
void _free_which(char **path_var, char **token_arr);
void _free_main(char **token_arr, char *input);
void _rev_str_(char *str);
char *__itoa__(size_t cmmnd_nmb);
int _dgt_cntr_(size_t cmmnd_nmb);
int error_not_found(char **arvs, char **token_arr, size_t cmd_num);
int _exit_builtin(char **token_arr);
int _env_builtin(char **array_of_tokens);
int _bltn_handler_(char **array_of_tokens)
int _is_builtin_(char **array_of_tokens);
#endif
