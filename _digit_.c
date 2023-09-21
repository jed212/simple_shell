#include "shell.h"

/**
 *  * _dgt_cntr_ - counts the digits
 *   * @cmmnd_nmb:  number to be counted
 *    *
 *     * Return: number of the digits
 *      */
int _dgt_cntr_(size_t cmmnd_nmb)
{
	int dgt_cnt = 0;


	if (cmmnd_nmb == 0)
		return (1);
	while (cmmnd_nmb != 0)
	{
		cmmnd_nmb /= 10;
		dgt_cnt++;
	}


	return (dgt_cnt);
}
