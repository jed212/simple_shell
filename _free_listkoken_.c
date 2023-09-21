#include "lists_handle.h"

/**
 *_free_listtoken_ - frees  listtoken_t structure list
 **
 ** Description: free  listtoken_t strudcture list
 *
 *@head: points to a pointer that points to the first node
 * *
 *Return: void
 */
void _free_listtoken_(list_token_t **head)
{
	list_token_t *node;


	if (head == NULL)
		return;

	while (*head != NULL)					{
		node = *head;
		*head = node->next;
		free(node->token);
		free(node);
	}
	head = NULL;
}
