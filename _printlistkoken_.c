#include "_lists_handle_.h"
#include <stdio.h>

/**
 * _print_listtoken_ - prints all the elements of a list_token_t list
 * @head: points to the first node
 * *
 * Return: the number of nodes
 **/
size_t _print_listtoken_(const list_token_t *head)
{
	int cnt = 0;
	const list_token_t *crrnt;


	if (head == NULL)
		return (0);

	crrnt = head;
	while (crrnt != NULL)
	{
		printf("%s\n", crrnt->token);
		cnt++;


		crrnt = crrnt->next;
	}


	return (cnt);
}
