#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
/**
 * struct builtin_command - Short description
 * @n: member
 * @function: second member
 *
 * Description: Longer description
 */
struct builtin_command
{
	char *n;
	int (*function)(char **token_arr);
};


void display_prompt(void);
void sigint_handler(int signal);
ssize_t _getline_(char **input,
		size_t *malloc_bytes_allocated, int status);
char **array_maker(char *input, char *delimiter);
int _fork(char *cmd, char **token_arr);
char *_which_(char *file_name);
int print_env_(void);
char *_getenv_(const char *n);
int _setenv_(const char *n, const char *v, int overwrite);
int _unsetenv_(const char *n);
char **malloc_array_(char **array, size_t size_of_malloc, char *error_msg);
char *malloc_char_(char **string, size_t size_of_malloc, char *error_msg);
int cpy_arr(char **dest, char **src);
int name_exists(const char *n);
int _env_length(void);
void _free_which(char **path_var, char **token_arr);
void _free_main(char **token_arr, char *input);
void rev_string(char *s);
char *_itoa(size_t command_num);
int digit_counter(size_t command_num);
int error_not_found(char **arvs, char **token_arr, size_t cmd_num);
int is_builtin(char **array_of_tokens);
int builin_handler(char **array_of_tokens);
int exit_builtin_(char **token_arr);
#endif
