#include "shell.h"

/**
 ** num_of_tokens_ - returns the number of tokens in a string
 **
 ** Description: function that  returns the number of tokens in a string
 **
 ** @input: input string
 ** @delimiter: delimiter string
 **
 ** Return: -1 if failure and a number if not
 **/
size_t num_of_tokens_(char *input, char *delimiter)
{
	char *token;
	size_t token_counter;


	token_counter = 0;
	token = strtok(input, delimiter);
	while (token != NULL)
	{
		token_counter++;
		token = strtok(NULL, delimiter);
	}
	return (token_counter);
}
/**
 **_array_maker_ - creates a NULL terminated array of a string delimited
 **
 **Description: creates a NULL terminated array of a string delimited
 **@input: input string
 **@delimiter: delimiter string
 **
 ** Return: returns NULL on failure and the array on success
 **/
char **_array_maker_(char *input, char *delimiter)
{
	char *input_cpy, *token;
	char **token_arr;
	size_t token_counter, token_index_, token_free_index_;


	token_arr = NULL;
	malloc_char_(&input_cpy, strlen(input) + 1,
			"Error: input cpy malloc failure!");
	strcpy(input_cpy, input);
	token_counter = num_of_tokens_(input_cpy, delimiter);
	token_arr = malloc_array_(token_arr, token_counter + 1,
			"Error:  tokens malloc failure!");
	strcpy(input_cpy, input);
	token = strtok(input_cpy, delimiter);
	for (token_index_ = 0; token_index_ < token_counter; token_index_++)
	{
		token_arr[token_index_] = (char *) malloc(sizeof(char) *
				strlen(token) + 1);
		if (token_arr[token_index_] == NULL)
		{
			for (token_free_index_ = 0;
					token_free_index_ < token_index_;
					token_free_index_++)

				free(token_arr[token_free_index_]);
			free(input_cpy);
			free(token_arr);
			perror("Error: array of tokens malloc failure!");
			return (NULL);
		}
		strcpy(token_arr[token_index_], token);
		token = strtok(NULL, delimiter);
	}
	free(input_cpy);
	token_arr[token_counter] = NULL;
	return (token_arr);
}
