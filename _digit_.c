#include "shell.h"

/**
 * _counter_ - counts the digits
 * @cmd_num:  number to be counted
 * *
 * Return: number of the digits
 */
int _counter_(size_t cmd_num)
{
	int dgt_cnt = 0;


	if (cmd_num == 0)
		return (1);
	while (cmd_num != 0)
	{
		cmd_num /= 10;
		dgt_cnt++;
	}


	return (dgt_cnt);
}
