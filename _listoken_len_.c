#include "_lists_handle_.h"

/**
 *  * listtoken_len - returns number of elements
 *   * @head: points to the first node
 *    *
 *     * Return: the number of elements in a linked list_token_t list
 *      */
size_t listtoken_len(const list_token_t *head)
{
	int count = 0;
	const list_token_t *current;


	if (head == NULL)
		return (0);


	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
