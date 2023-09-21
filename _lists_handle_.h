#ifndef LISTS_HANDLE_H
#define LISTS_HANDLE_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 *struct list_token_s - singly linked list
 *@token: pointer
 *@token_length: integer
 *@next: pointer to the next node
 **
 *Description:  node structure for singly linked list
 */
typedef struct list_token_s
{
	char *token;
	int token_length;
	struct list_token_s *next;
} list_token_t;

size_t _print_listtoken_(const list_token_t *head);
size_t listtoken_len(const list_token_t *head);
list_token_t *_add_nodetoken_end_(list_token_t **head, char *token);
void _free_listtoken_(list_token_t **head);

#endif
