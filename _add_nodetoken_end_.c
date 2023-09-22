#include "_lists_handle_.h"

/**
 *_add_nodetoken_end_ - adds a new node at the end of  list list_token_t
 *
 *Description:  adds a new node to the end of the linked list
 * *
 *@head: points to a pointer  pointing  to the first node
 *@token: the token to add
 *
 *Return: address of the new element,  NULL on failure
 */
list_token_t *_add_nodetoken_end_(list_token_t **head, char *token)
{
	list_token_t *new_node, *last_node;


	if (head == NULL)
		return (NULL);


	new_node = malloc(sizeof(list_token_t));
	if (new_node == NULL)
		return (NULL);


	new_node->token = token;
	new_node->token_length = strlen(token);
	new_node->next = NULL;


	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;


		last_node->next = new_node;
	}


	return (last_node);
}
