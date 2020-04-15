#include "shell.h"
/**
 *sig_handler - sighandler
 *@sig: var int
 * Return: 0
 */
void sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		_putstring("\n:)$ ");
	}
}
